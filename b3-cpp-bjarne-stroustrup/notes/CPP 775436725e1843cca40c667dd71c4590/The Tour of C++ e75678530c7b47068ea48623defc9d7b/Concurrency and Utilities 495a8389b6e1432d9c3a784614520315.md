# Concurrency and Utilities

### Resource Management

- STL components are designed not to leak resources with the help of constructor/destructor pair. Importantly, this approach interacts correctly with error handling using exceptions.
    
    ```bash
    mutex m;  // used to protect access to shared data
    //...
    
    void f()
    {
    	unique_lock<mutex> lck{m}; // accuire the mutex m
    	// .. manipulate shared data ..
    }
    ```
    
    - A thread will not process until `lck`’s construct has acquired its mutex.
    
- `unique_ptr` and `shared_ptr`
    
    What if we allocate objects using free store and the current scope is not the owner of the resource. These two smart pointes help us with that - `unique_ptr` and `shared_ptr`.
    
    The most basic use of smart pointers is to prevent memory leaks
    
    ```cpp
    unique_ptr<X> make_X(int i)
    	// make an X and immediately give it to unique_ptr
    {
    	// .. check i, etc
    	return unique_ptr<X>{ new X{i} };
    }
    ```
    
    - `unique_ptr`
    Is a handle to an individual object just like vector is a handle to sequence of objects. Both rely on move semantics to make `return` simple and efficient.
    - `shared_ptr`
    Is similar to `unique_ptr` except `shared_ptr` is copied rather than moved.
        
        ```cpp
        void f(shared_ptr<fstream>);
        void g(shared_ptr<fstream>);
        
        void user(const string& name, ios_base::openmode mode)
        {
        	shared_ptr<fstream> fp { new fstream(name,mode) };
        	if (!*fp) throw No_file{};
        
        	f(fp);
        	g(fp);
        }
        ```
        
        - Here `f` holds a copy of `fp` and can outlive `user` function.
        - This make the life type of a shared object hard to predict. Use `shared_ptr` only if you actually need shared ownership.

### Concurrency

- Main standard library concurrency support facilities:
    - `thread`
    - `mutex`
    - `lock`
    - `package_task`
    - `future`
- **Tasks and `thread`s**
    - `task` - a computation that can potentially be executed concurrently with other computations.
    - `thread` - a system level representation of a task in a program.
    - Launched by constructing a `std::thread`(found in `<thread>`) with the task as it’s argument.
    
    ```cpp
    void f();
    
    struct F() {
    	void operation()();  // F's call operator
    };
    
    void user()
    {
    	thread t1 {f};
    	thread t2 {F()};
    
    	t1.join();  // wait for t1
    	t2.join();  // wait for t2
    }
    ```
    
    - The `join` ensure that we don’t exit `user()` until the thread have completed.
    - Threads of a program share a single address space (unlike process).
    - Since threads share address space they can communicate through shared objects.
    - Such communication is typically controlled by locks or other mechanism to prevent data races.
    - **Programming concurrent tasks can be very tricky**
        
        ```cpp
        vod f() { cout << "Hello "; }
        
        struct F {
        	void operation()() { cout << "Parallel World!\n"; }
        };
        ```
        
        - This is an example of bad error:
        `f` and `F()` each use the object `cout` without any form of synchoronization.
        - This can provide output like - `PaHerallllel o World!`
        - You want to define tasks completely separate unless they communicate in a simple and obvious way. `i.e` make sure there is no data races.
    
- **Passing arguments**
    
    ```cpp
    void f(vector<double>& v);
    
    int main() {
    	vector<double> some_vec {1,2,3,4,5};
    	thread t1{f,some_ved);
    }
    ```
    
    - The initialization with `{f,some_vec}`used a `thread` variadic template constructor.
- **Returning result**
    - Pass non-const reference and modify the data.
    - More preferred way is to pass input data by `const` reference and to pass the location of a place to deposit the result as a separate argument:
    
    ```cpp
    void f(const vector<double>& v, double* res);
    
    int main()
    {
    	vector<double> some_vec;
    	double res1;
    	thread t1 {f,some_vec,&res1};
    }
    ```
    
- **Sharing data**
    - Mutex and lock
        - Intro - Mutex and lock
            - The fundamental element of solution is a `mutex`.
            - A thread acquires a mutex using a `lock()` operation.
            
            ```cpp
            mutex m;
            int sh; // shared data
            
            void f()
            {
            	unique_locK<mutex> lck {m};
            	sh += 7;
            }
            ```
            
        - The programmer has to know which mutex is suppose to correspond to which data. This is error-prone. You can this by language means, Like this...
            
            ```cpp
            class Record {
            public:
            	mutex m;
            	//
            }
            ```
            
        - Program sometimes needs to access several resources to perform some action. This can lead to deadlock. For example: `thread1` acquires `mutex1` and waiting for `mutex2` and `thread2` acquires `mutex2`and waiting for `mutex1`.
            
            
            Solution is to use `defer_lock` and trying to `lock` all at once.
            
              
            
            ```cpp
            void f()
            {
            	//...
            	unique_lock<mutex> lck1 {m1,defer_lock};  // defer_lock: don't yet try to acquire the mutex
            	unique_lock<mutex> lck2 {m2,defer_lock};
            	unique_lock<mutex> lck3 {m3,defer_lock};
            
            	lock(lck1,lck2,lck3);    // acquire all three lock
            } // implicitly release all mutex
            ```
            
            - Some people are convinced that sharing must be more efficient that copying results and return. This can indeed be so when large amount of data is involved.
            - But locking and unlocking are relatively expensive operations.
            - On the other hand, modern machines are very good at copying data, especially compact data, such as `vector` elements.
    - **Waiting for events**
        
        Sometimes thread needs to wait for some kind of external event, such as another thread completing a task. 
        
        ```cpp
        using namespace std::chrono;
        
        auto t0 = high_resolution_clock::now();
        this_thread::sleep_for(milliseconds{20});
        auto t1 = high_resolution_clock::now();
        cout << duration_cast<nanoseconds>(t1-t0).count() << " nanoseconds passed\n";
        ```
        
        Notice, we didn’t even have to launch a thread; by default, `this_thread` refers to the one and only thread.
        
        The basic support for communicating using external events is provided by `condition_variable`s found in `<condition_variable>`. A `condition_variable` is a mechanism allowing one `thread` to wait for another. This allows an `thread` to wait for some condition (often called as event).
        
        Consider the example of two threads communicating by passing messages through a queue.
        
        ```cpp
        class Message {  // object to be communicated
        	//...
        };
        
        queue<Message> mqueue; // the queue of messages
        condition_variable mcond;  // the variable communicating events
        mutex mmutex;  // the locking mechanism
        
        // The consumer reads and processes Messages
        void consumer() {
        	while(true) {
        		unique_lock<mutex> lck(mmutex);  // acquire mmutex
        		while (mcond.wait(lck))  /* do nothing */;  // release the lck and wait;
        																							  // reacquire lck upon wakeup
        
        		auto m = mqueue.front();  // get the message
        		mqueue.pop();
        		lck.unlock();  // release lck
        		//... process m ...
        	}
        }
        
        // The corresponding producer looks like this
        void producer()
        {
        	while(true) {
        		Message m;
        		// .. fill the message ..
        		unique_lock<mutex> lck {mmutex};  // protect operations
        		mqueue.push(m);
        		mcond.notify_one();   // notify
        	}                       // release lock (at the end of the scope)
        }
        ```
        
- **Communicating Tasks**
    
    The STL provides a few facilities to allow programmers to operate at the conceptual level of tasks rather than directly at lower level of thread and locks
    
    1. `future` and `promise` - For returning a value from a task spawned on a separate thread.
    2. `packaged_task` to help launch tasks and connect up the mechanisms of returning the result.
    3. `async()` for launching of a task in a manner very similar to calling a function.
    
    These facilities are found in `<future>`.
    
    - `future` and `promise`
        
        `future` and `promise` enables transfer of a value between two tasks without explicit use of a lock. When a task wants to pass a value to another, it puts the value into a `promise`. Somehow, the implementation makes the value appear in the corresponding `future`
        
        If you have a `future<x>` called `fx`, we can `get()` a value of type `X` from it. If the value isn’t there yet, our thread is blocked until it arrives. If the value couldn’t be computed, `get()` might throw an exception (from the system or transmitted from the task from which we were trying to `get()` the value.
        
        The main purpose of `promise` to provide simple “put” operations (called `set_value()` and `set_exception()`) to match `future`'s `get()`. 
        
        ```cpp
        void f(promise<X>& px) //
        {
        	//..
        	try {
        		X res;
        		// .. compute the value for res ...
        		px.set_value(res);
        	}
        	catch(...) {
        		px.set_exception(current_exception());
        	}
        }
        ```
        
        - The `current_exception()` refers to the caught exception.
        
        Get the the value or exception
        
        ```cpp
        void g(future<X>& fx)
        {
        	//...
        	try {
        		X v = fx.get();  // if necessary, wait for the value to get computed
        		// .. use v ...
        	}
        	catch(...) {
        		// ... handle error ...
        	}
        }
        ```
        
    - `packaged_task`
        
        How do we get `future` into the task that needs a result and corresponding promise into the that that should produce the result? - `packaged_task`.
        
        If you ask it by calling `get_future`, a `packaged_task` will give you the `future` corresponding to its `promise`.
        
        ```cpp
        double accum(double* beg, double* end, double init)
        {
        	return accumulate(beg,end,init);
        }
        
        double comp2(vector<double>& v)
        {
        	using Task_type = double(double*,double*,double);
        
        	packaged_task<Task_type> pt0{accum};
        	packaged_task<Task_type> pt1{accum};
        
        	future<double> f0 {pt0.get_future()};  // get hold of future
        	future<double> f1 {pt1.get_future()};
        
        	double* first = &v[0];
        	thread t1 {move(pt0),first,first+v.size()/2,0); // start a thread for pt0
        	thread t2 {move(pt1),first+v.size()/2,first+v.size(),0};
        	
        	// ....
        
        	return f0.get()+f1.get();   // get the results
        }
        ```
        
        - The packaged task template takes the type of the task as its template argument (`Task_type`). and the task as its constructor argument.
        - The `move` operation is needed because because a `packaged_task` cannot be copied.
    - `async`
        
        Treat a task as a function that may happen to run concurrently with other tasks. To launch a task to potentially run asynchronously, we can use `async()`.
        
        ```cpp
        double comp4(vector<double>& v)
        {
        	if (v.size()<10000) return accum(v.begin(),v.end(),0.0);
        
        	auto v0 = &v[0];
        	auto sz = v.size();
        
        	auto f0 = async(accum,v0,v0+sz/4,0.0);  // first quarter
        	auto f1 = async(accum,v0+sz/4,v0+sz/2,0.0);  // second quarter
        	auto f2 = async(accum,v0+sz/2,v0+sz*3/4,0.0);  // third quarter
        	auto f3 = async(accum,v0+sz*3/4,v0+sz,0.0);  // fourth quarter
        
        	return f0.get()+f1.get()+f2.get()+f3.get();
        }
        ```
        
        - Limitations
            - Don’t even think of using `async()` for tasks that share resources needing locking - with `async()` you don’t even know how many threads will be used.
            - `async` is not just a mechanism for parallel computation. For example, it also can be used to spawn a task for getting information from a user, leaving the “main program” active with something else.

### Small Utility Components

- `clock` and `duration` - for measuring time
- Type functions, such as `iterator_traits` and `is_arithmetic` , for gaining information about types.
- `pair`  and `tuple` for representing small potentially heterogeneous sets of values.

- **Time**
    
    ```cpp
    using namespace std::chrono;
    
    auto t0 = high_resolution_clock::now();  // returns "time_point"
    do_work();
    auto t1 = high_resulution_clock::now();
    cout << duration_cast<milliseconds>(t1-t0).count()<<" msec\n";  // gives "duration"
    ```
    
- **Type functions**
    
    A type function is a function that is evaluated at compile-time given a type as it’s argument or returning a type.
    
    - For numerical types, `numeric_limits` from `<limits>` presents a variety of useful information.
    
    ```cpp
    constexpr float min = numeric_limits<float>::min();  // smallest possible float
    constexpr int szi = sizeof(int);
    ```
    
    - `iterator_traits`
        
        The STL `sort()` takes random access iterators. Not every iterator is a random access iterator. For example, `forward_list` is an a singly linked list and subscript operation is expensive, furthermore there is no reasonable way to refer back to the previous position. 
        
        STL provides `iterator_traits` that allows to check what kind of iterator is supported. Given that we can improve the range sort to accept either `vector` , or `forward_list`.
        
        ```cpp
        void test(vector<string>& v, forward_list<int>& lst)
        {
        	sort(v);
        	sort(lst);
        }
        ```
        
        The technique:
        
        ```cpp
        template<typename Ran>  // for random access iterator
        void sort_helper(Ran beg, Ran end, random_access_iterator_tag)
        {
        	sort(beg,end);  // just sort
        }
        ```
        
        ```cpp
        template<typename For>
        void sort_helper(For beg, For end, forward_iterator_tag)
        {
        	vector<decltype(*beg)> v {beg,end}; // initialize the vector
        																		  // from [beg:end)
        	sort(v.begin(),v.end());
        	copy(v.begin(),v.end(),beg);  // copy the elements back.
        }
        ```
        
        ```cpp
        template<typename C>
        void sort(C& c)
        {
        	using iter = iterator_type<C>;   // C::iterator
        	sort_helper(c.begin(),c.end(),iterator_category<iter>{});
        }
        ```
        
        - `iterator_category<iter>{}` - will give.
            - `std::random_access_iterator_tag` if `C`'s iterator supports random access.
            - `std::forward_iterator_tag` if `C`'s iterator supports forward iteration.
        - This technique is called - tag dispatch.
        - STL iterator techniques for using iterator, such as tag dispatch, comes in the form of a simple class template `iterator_traits` from `<iterator>`.
        - This allows simple definition of the type functions used in `sort()`.
        
        ```cpp
        template<typename C>
        	using iterator_type = typename C::iterator; // C's iterator type
        
        template<typename iter>
        	using iterator_category = \
        		typename std::iterator_traits<iter>::iterator_category;
        ```
        
    - **Type Predicates**
        
        Answers a fundamental question about types.
        
        ```cpp
        bool b1 = is_arithmetic<int>();  // yes, int is an arithmetic type
        bool b2 = is_arithmetic<string>();  // no, std::string 
        																	 // is not an arithmetic type
        ```
        
        - These predicates are found in `<type_traits>`.
        - Other examples are `is_class`, `is_pod`, `is_literal_type`, `has_virtual_destructor`, and `is_base_of`.
        
        They are most useful when we write templates
        
        ```cpp
        template<typename Scalar>
        class complex {
        	Scalar re, im;
        public:
        	static_assert(is_arithmetic<Scalar>(),
        							  "Sorry, I only support complex of arithmetic types");
        	//...
        }
        ```
        
        To improve readability compared to using the standard library directly, I define a type function.
        
        ```cpp
        template<typename T>
        constexpr bool is_arithmetic()
        {
        	return std::is_arithmetic<T>::value;
        }
        ```
        
        Old programs use `::value` directly instead of `()`, but this is quite ugly and it exposes implementation details.
        
    - `pair` and `tuple`
        
        Often, we just need data, rather than object of a class, well defined semantics and an invariant for its values. In that case we can use `stuct`. Alternatively, we can let STL definition for us. For example: `equal_range` returns a `pair` of iterators matching the predicate.
        
        - `pair`
            
            ```cpp
            template<typename Forward_iterator, typename T, typename Compare>
            		pair<Forward_iterator,Forward_iterator>
            		equal_range(Forward_iterator first, Forward_iterator last,
            								const T& val, Compare cmp);
            ```
            
            ```cpp
            // Search in a sorted sequence of records
            auto rec_eq = [](const Record& r1, const Record& r2) { return r1.name<r2.name };  // compare names
            
            void f(const vector<Record>& v)
            {
            	auto er = equal_range(v.begin(),v.end(),Record("Reg"),rec_eq);
            	for (auto p=er.first;p!=er.second;++p)  // print all equal record
            		cout << *p;  // assume that << is defined for Record
            }
            ```
            
            - The first member of `pair` is called `first` and the second member is called `second`
            - The STL `pair` (from `<utility>`) is quite frequently used in STL.
            - `make_pair` makes it easy to create a `pair`
                
                ```cpp
                void f(vector<string>& v)
                {
                	auto pp = make_pair(v.begin(),2);  // pair<vector<string>::iterator,int>
                }
                ```
                
            - If you use more than two elements (or less) you can use `tuple`.
        - `tuple`
            
            From `<utility>`
            
            ```cpp
            tuple<string,int,double> t2("Slid",123,3.14);
            
            auto t = make_tuple(string("Herring",10,1.23));
            
            string s = get<0>(t);  // get first element of tuple
            int x = get<1>(t);
            double d = get<2>(t);
            ```
            

### Regular Expressions

Powerful tool for text processing. In `<regex>` STL in form of `std::regex`.

```cpp
regex pat(R"(\w{2}\s*\d{5}(-\d{4})?)";  // Zip code: XXddddd-dddd and variants
cout << "pattern: " << pat << "\n";

// \w{2} --> two letters
// \s*  --> Optionally follwed by some space
// \d{5} --> Followed by 5 digits
// -\d{4} --> Optionally follwed by a dash and four digits
```

- To express the pattern use raw string literal starting with `R"(` and terminated by `)`.
- The simplest way of using is to search for it in a stream.
    
    ```cpp
    int lineno = 0;
    for (string line; getline(cin,line);){
    	++lineno;
    	smatch matches;
    	if (regex_search(line,matches,pat))
    		cout << lineno << ": "<< matches[0] << '\n';
    }
    ```
    
    - If no matches found `regex_search` returns false.
    - `smatch` is a vector of sub-matches.
    - The first element (`matches[0]`) is a complete match.

### **Math**

In `<cmath>`. 

Functions such as `sqrt()`, `log()`, and `sin()` . Complex number version of these functions are found in `<complex>`.

In `<numeric>` we find a small set of generalise numerical algorithm, such as `accumulate()`.

```cpp
void f()
{
	list<double> lst {1,2,3,4,5,999.999};
	auto s = accumulate(lst.begin(), lst.end(), 0.0); // calculate the sum
	cout << s << '\n';
}
```

- **Complex numbers**
    
    STL `complex` is a template.
    
    ```cpp
    template<typename Scalar>
    class complex {
    public:
    	complex(const Scalar& re ={}, const Scalar& im ={});
    	// ...
    }
    ```
    
    The usual arithmetic and most common math operations are supported
    
    ```cpp
    void f(complex<float> fl, complex<double> db)
    {
    	complex<long double> ld {fl+sqrt(db)};
    	db = fl*3;
    	fl = pow(1/fl,2);
    	//..
    }
    ```
    
- **Random Numbers**
    
    In STL `<random>`
    
    Consists of two parts
    
    1. an `engine` that provides a sequence of random or pseudo-random values.
    2. a `distribution` that maps those values into mathematical distribution in a range.
    
    Examples of distributions are `uniform_int_distribution`, `normal_distribution` (”the bell curve”) and `exponential_distribution`
    
    ```cpp
    using my_engine = default_random_engine;  // type of engine
    using my_distribution = uniform_int_distribution<>;  // type of distribution
    
    my_engine re {};
    my_distribution one_to_six{1,6};
    auto die = bind(one_to_six,re);  // makes a generator
    
    int x = die();  // roll the dice
    ```
    
    - `bind` - makes a function that will invoke it’s first argument given its second argument as its argument. equivalent to - `one_to_six(re)`.
    
    It could be used like this (simpler)
    
    ```cpp
    auto die = bind(uniform_int_distribution<>{1,6}, default_random_engine{});
    ```
    

A more simpler approach

```cpp
Rand_int rnd {1,10};
int x = rnd();

class Rand_int {
public:
	Rand_int(int low, int high): dist{low,high} {}
	int operator()() { return dist(re); }
private:
	default_random_engine re;
	uniform_int_distribution<> dist;
};
```

```cpp
int main() {
	Rand_int rnd {0,4};
	vector<int> histogram(5);
	for (int i=0;i!=200;++i)
		++histogram[rnd()];
	
	for (int i=0;i!=mn.size();++i) {
		cout << i << '\t';
		for (int j=0;j!=mn[i];++j) cout << '*';
		cout << endl;
	}
}

// Output
// 0 ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
// 1 ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
// 2 ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
// 3 ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
// 4 ∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗∗
```

- **Vector Arithmetic**
    
    `vector` container does not support mathematical vector operations. Consequently, the STL provides (in `<valarray>`) a vector-like template, called `valarray`.
    
    ```cpp
    void f(valarray<double>& a1, valarray<double>& a2)
    {
    	valarray<double> a = a1*3.14+a2/a1;
    	a2 += a1*3.14;
    	a = abs(a);
    	double d = a2[7];
    	//...
    }
    ```
    
- **Numeric Limits**
    
    In `<limits>` - Provides classes that describes the properties of built-in types .
    
    ```cpp
    static_assert(numeric_limits<char>::is_signed,"unsigned character!");
    static_assert(100000<numeric_limits<int>::max(), "small ints!");
    ```
    
    - `numeric_limits<int>::max()` - is a `constexpr` function.