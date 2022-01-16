# Abstraction Mechanisms

- Classes
    - Concrete Types; Abstract Types; Virtual Functions; Class Hierarchies
- Copy and Move
    - Copying Containers; Moving Containers; Resource Management; Suppressing Operations
- Templates
    - Parameterised Types; Function Templates; Function Objects; Variadic Templates; Aliases

## Classes

- Represents design of concept and ideas in code which makes fairly easy to understand.
- Three important kinds of classes
    - **Concrete classes**
        - They behave just like built-in types.
            - `vector` and `string` classes are just like built-in arrays, except they are better behaved.
            - The representations is part of its definition.
                - In particular
                    - Place objects of concrete types on a stack, in statistically allocated memory and other objects.
                    - Refer to object directly, not through pointers or referrences.
                    - Initialise objects immediately and completely
                    - copy objects
                    - If representations changes then user must recompile, behaves exactly like built-in types. The price concrete classes
                
        - **An Arithmetic Type**
            
            ```cpp
            class complex {
            	double re, im; // representation of two doubles
            public:
            	complex(double r, double i) :re{r}, im{i} {}  // construct complex from two scalar
            	complex(double r) :re{r}, im{0} {}  // construct complex from one scalar
            	complex() :re{0}, im{0} {}  // default complex: {0,0}
            
            	double real() const { return re; }
            	void real(double r) { re = d; }
            	double imag() const { return im; }
            	void imag(double d) { im = d; }
            	
            	complex& operator+=(complex z) { re+=z.re, im+=z.im; return *this;}
            	complex& operator-=(complex z) { re-=z.re, im-=z.im; return *this;}
            
            	complex& operator*=(complex);  // defined out of the class somewhere
            	complex& operator/=(complex);  // defined out of the class somewhere
            };
            ```
            
            - It implies
                - Simple operations must be inlined. That is simple operations must be implemented without function calls. Functions defined in a class are inlined by default
                - A constructor can be invoked without argument - `default constructor`. Here, `complex()`.
                - The `const` specifiers on the functions returning the real and imaginary parts indicates that `these functions do not modify` the object for which they are called.
            - Other useful operations do not require direct access they can be defined separately from class definition.
                
                ```cpp
                complex operator+(complex a, complex b) { return a+=b; }
                complex operator-(complex a, complex b) { return a-=b; }
                complex operator-(complex a) { return {-a.real(), -a.imag()};} // unary minus
                complex operator∗(complex a, complex b) { return a∗=b; }
                complex operator/(complex a, complex b) { return a/=b; }
                
                bool operator==(complex a, complex b) // equal
                {
                	return a.real()==b.real() && a.imag()==b.imag();
                }
                
                bool operator!=(complex a, complex b) {
                	return !(a==b);
                }
                ```
                
                - Here argument passed by value is copied, so that we can modify the argument without changing the caller’s copy, and user the result as return value.
            - One use of `complex`
                
                ```cpp
                void f(complex z)
                {
                	complex a {2.3};
                	complex b {1/a};
                	complex c {a+z*complex{1,2.3}};
                	//...
                	if (c!=b)
                		c = -(b/a)+2*b;
                }
                ```
                
        - **A Container**
            - An object holding a collection of elements, so we call `Vector` a container.
            - Some good characteristics of a container: establishes an useful invariant, provides range checked access, and provides `size()`, deallocates memory.
            - **A destructor**
                
                ```cpp
                class Vector {
                private:
                	double* elem;
                	int sz;
                public:
                	Vector(int s) :elem{new double[s];}, sz{s} {
                		for (int i=0;i!=s;++i) elem[i]=0;
                	}
                
                	~Vector() { delete[] elem; }  // destructor: release resources
                
                	double& operator[](int i);
                	int size() const;
                };
                ```
                
                - Usage
                    
                    ```cpp
                    void fct(int n)
                    {
                    	Vector v(n);
                    
                    	//use v ...
                    
                    	{
                    		Vector v2(2*n);
                    		// .. use v2 ...
                    	} // v2 is destroyed here
                    } // v2 is destroyed here
                    ```
                    
            - This process of acquiring resource in constructor and releasing it in destructor is known as `Resource Acquisitions Is Initialisation or (RAII)`.
            - We should `always avoid`: `naked new operations` AND `naked delete operations`. This is less error prone.
        - **Initialising Containers**
            - In `Vector` we need a convenient ways of getting elements into the container.  Two elegant ways
                - 1. `Initialiser-list constructor`: initialise with a list of elements.
                2. `push_back()`: Add new elements at the end
                    
                    ```cpp
                    class Vector {
                    public:
                    	Vector(std::initializer_list<double>);  //initialize with a list
                    	//...
                    	void push_back(double);  // add elements at the end increasing the size by one
                    };
                    ```
                    
                - Using`push_back()`
                    
                    ```cpp
                    Vector read(istream& is)
                    {
                    	Vector v;
                    	for (double d; is>>d;) // read floating point values to d
                    		v.push_back(d);  // add d to v
                    	return v;
                    }
                    ```
                    
            - Definition of Vector’s `initializer-list` constructor
                
                ```cpp
                Vector::Vector(std::initializer_list<double> lst)
                		:elem{new double[lst.size()]}, sz{lst.size()}
                {
                	copy(lst.begin(),lst.end(),elem);  // copy from lst to elem
                }
                ```
                
            - So we can write.
                
                ```cpp
                Vector v1 = {1, 2, 3, 4, 5};
                Vector v2 = {1.23, 3.45, 6.7, 8};
                ```
                
            
    - **Abstract classes**
        - Abstract type is a type that complete insulates a user from implementation details.
        - Since we don’t know anything about representation (not even size), we must allocate objects with free store and access them through references and pointers.
        - Define `Container` - A Abstract version of `Vector`.
            
            ```cpp
            class Container {
            public:
            	virtual double& operator[](int) = 0;  // pure virtual function
            	virtual int size() const = 0;  // const member function
            	virtual ~Container() {} // destructor
            }
            ```
            
            - The word `virtual` means - “maybe defined later in a class derived from this one”.
            - The curious `= 0` syntax says the function is pure virtual; that is, some class derived from `Container` must define the function.
            - A class with a pure virtual function is called abstract class.
            - This `Container` class can be used as.
                
                ```cpp
                void use(Container& c)
                {
                	const int sz = c.size();
                	for (int i=0;i!=sz;++1)
                		cout << c[i] << '\n';
                }
                ```
                
            - A class that provides an interface to variety of other classes is called - `polymorphic type`.
            - As common in abstract class, Container doesn’t have any constructor. After all, it doesn’t have any data to initialise.
            - On the other hand Container does have a destructor and the destructor is virtual.
            - 
        - A container that implements the functions required by the interface defined by the abstract class `Container` could use the concrete class `Vector`.
            
            ```cpp
            class Vector_container : public Container { // implements Container
            	Vector v;
            public:
            	Vector_container(int s) : v(s) {}  // Vector of s elements
            	~Vector_container() {}
            
            	double& operator[](int i) { return v[i]; }
            	int size() const { return v.size(); }
            };
            ```
            
        - For functions like `use(Container&)` to use a `Cotainer` in complete ignorance of implementation details. some other function will have to make an object on which it can operate.
            
            ```cpp
            voig g()
            {
            	Vector_container vc {10, 9, 8, 7, 6, 5};
            	use(vc);
            }
            ```
            
        - Since `use` doesn’t know about the `Vector_container` and only know about `Container` interface it will work just as well for a different implementation of a `Container`.
            
            ```cpp
            class List_container : public Container {
            	std::list<double> ld;
            public:
            	List_container() {} // empty list
            	List_container(initializer_list<double> il): ld{il} {}
            	~List_container() {}
            
            	double& operator[](int i);
            	int size() const { return ld.size(); }
            };
            
            double& List_container::operator[](int i)
            {
            	for (auto x : ld) {
            		if (i == 0) return x;
            		--i;
            	}
            	throw out_of_range("List container");
            }
            ```
            
            ```cpp
            void h()
            {
            	List_container lc = {1, 2, 3, 4, 5, 6, 7};
            	use(lc);
            }
            ```
            
        - The flip side of this flexibility is that objects must be manipulated through pointers or references.
        - **Virtual functions**
            
            How `use` function know which `operator[]()` function to call? There is table `virtual function table` or `vtbl`. Each class with virtual functions has it’s own `vtbl` identifying its virtual functions
            
    - **Classes** **in** **class** **hierarchies**
        - The class hierarchy
            
            ![Screenshot 2022-01-03 at 6.18.07 PM.png](Abstraction%20Mechanisms%201166fbe7a8d3477e8c42ac1c7b3e7223/Screenshot_2022-01-03_at_6.18.07_PM.png)
            
        - Shape interface
            
            ```cpp
            class Shape {
            	public:
            		virtual Point center() const = 0;  // pure virtual
            		virtual void move(Point to) = 0;
            		
            		virtual void draw() const = 0;
            		virtual void rotate(int angle) = 0;
            
            		virtual ~Shape() {}
            		// ...
            }
            ```
            
        - General function manipulating vectors of pointers to shapes.
            
            ```cpp
            void rotate_all(vector<Shape*>& v, int angle)  // rotate v's elements by angle degrees
            {
            	for (auto p : v)
            		p->rotate(angle);
            }
            ```
            
        - Define a particular shape - Circle - Smiley
            - Define Circle
                
                ```cpp
                class Circle : public Shape {
                public:
                	Circle(Point p, int rr);  // constructor
                
                	Point center() const { return x; }
                	void move(Point to) { x=to; };
                
                	void draw() const;
                	void rotate(int) {}  // nice simple algorithm
                private:
                	Point x;  //center
                	int r;  //radius
                }
                ```
                
            - Define Smiley
                
                ```cpp
                class Smiley : public Circle {
                public:
                	Smiley(Point p, int r) : Circle{p,r}, mouth{nullptr} {}
                
                	~Smiley()
                	{
                		delete mouth;
                		for (auto p : eyes} delete p;
                	}
                
                	void move(Point to);
                
                	void draw() const;
                	void rotate(int);
                
                	void add_eye(Shape* s) { eyes.push_back(s); }
                	void set_mouth(Shape* s);
                	virtual void wink(int i);  // wink eye number i
                
                	//...
                
                private:
                	vector<Shape*> eyes;  //usually two eyes
                	Shape* mouth;
                }
                ```
                
                The `push_back()` member function add its argument to the vector (here, eyes) increasing that vector’s size by 1.
                
                ```cpp
                void Smiley::draw()
                {
                	Circle::draw();
                	for (auto p : eyes)
                		p->draw();
                	mouth->draw();
                }
                ```
                
                - Note
                    - `Shape`'s destructor is virtual and `Smiley`'s destructor overrides it.
                    - <IMP> A virtual destructor is essential for an abstract class because object of a derived class is usually manipulated through a pointer to base class. Then, the virtual function call mechanism ensures the proper destructor is called.
                - Concrete classes - especially classes with small representation - are much like built-in types, we define them as local variables and access them using names, copy them around. Classes in class hierarchies are different: we tend to allocate them on the free store using new, and we access them through pointers or references. See example to reading inputs describing shapes  and constructs appropriate Shape objects.
                    
                    ```cpp
                    enum class Kind { circle, triangle, smiley };
                    
                    Shape* read_shape(istream& is)  // read shape descriptions from input stream is
                    {
                    	// .. read shape header from is and find its Kind k
                    
                    	switch(k){
                    	case Kind::circle:
                    		// read circle data {Point,int} into p and r
                    		return new Circle{p,r};
                    
                    	case Kind::triangle:
                    		// read triangle data {Point, Point, Point} into p1, p2, p3
                    		return new Triangle{p1, p2, p3};
                    
                    	case Kind::smiley:
                    		// read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1, e2, and m
                    		Smiley* ps = new Smiley{p,r};
                    		ps->add_eye(e1);
                    		ps->add_eye(e2);
                    		ps->set_mouth(m);
                    		return ps;
                    	}
                    }
                    ```
                    
                    ```cpp
                    void user()
                    {
                    	std::vector<Shape*> v;
                    	while(cin)
                    		v.push_back(read_shape(cin));
                    	draw_all(v);  // call draw() for each element
                    	rotate_all(v,45);  // call rotate(45) for each element
                    	for (auto p : v) delete p;  // rememeber to delete elements
                    }
                    ```
                    
                    - Problems
                        - A user might fail to `delete` the pointers returned by `read_shape()` .
                        - The owner of a container of Shape pointers might not `delete` the objects pointed to.
                        - Solution
                            
                            One solution to both problems is to return a standard-library `unique_ptr` rather than  a “naked pointer” and store `unique_pointer` in the container.
                            
                            ```cpp
                            unique_ptr<Shape> read_shape(istream& is)
                            {
                            	//...
                            	switch(k) {
                            	case Kind::circle:
                            		// read circle data {Point, int} into p and r
                            		return unique_ptr<Shape>{ new Circle{p, r}};
                            	// ...
                            	}
                            }
                            ```
                            
                            ```cpp
                            void user()
                            {
                            	vector<unique_ptr<Shape>> v;
                            	while(cin)
                            		v.push_back(read_shape(cin));
                            	draw_all(v);  // call draw for each element
                            	rotate_all(v,45); // call rotate(45) for each element
                            } // all Shapes implicity destroyed
                            ```
                            
                            - Now object is owned by the `unique_ptr` which will delete object when it is no longer needed, that is, when its `unique_ptr` goes out of scope.
                            - For the `unique_ptr` version of `user()` to work, we need versions of `draw_all()` and `rotate_all()` that accept `vector<unique_ptr<Shape>>`. Writing many such `_all` functions can become tedious, so an alternative is Templates, explained later.

## Copy and Move

- By default objects can be copied - user-defined and built-in types both. The default meaning of copy is memberwise copy
    
    ```cpp
    void test(complex z1)
    {
    	complex z2 {z1};  // copy initialization
    	complex z3;
    	z3 = z2;  // copy assignment
    	// ...
    }
    ```
    
- For class we must always think of copying. For simple concrete types memberwise icopy is often exactly right semantics for copying. For sophisticated concrete types, such as Vector most of the types but not always and for Abstract types almost never is.
- **Copying Containers**
    - When class is handling resources though pointers a default memberwise copy violates resource handles variants.
    - Copying an object of a class is defined by two members: a `copy constructor` and a `copy assignment`
        
        ```cpp
        class Vector {
        private:
        	double *elem;
        	int sz;
        public:
        	Vector(int s);
        	~Vector(){ delete[] elem; }
        	
        	Vector(const Vector& a);  // copy constructor
        	Vector& operator=(const Vector& a); // copy assignment
        
        	double& opetator[](int i);
        	const double& opetator[](int i) const;
        
        	int size() const;
        }
        ```
        
        ```cpp
        Vector::Vector(const Vector& a)  // copy constructor
        	:elem{ new double[sz] },
        	 sz{a.sz}
        {
        	for (int i=0;i!=sz;++i)  // copy elements
        		elem[i] = a.elem[i];
        }
        ```
        
        ```cpp
        Vector& Vector::operator=(const Vector& a)  // copy assignment
        {
        	double* p = new double[a.sz];
        	for (int i=0;i!=a.sz;++i)
        		p[i] = a.elem[i];
        	delete[] elem;  // delete old elements
        	elem = p;
        	sz = a.sz;
        	return *this;
        }
        ```
        
        - The name `this` is predefined in a member function and points to the object for which the member function is called.
- **Moving Containers - <:NotClear:>**
    - Copying can be costly for large containers. Consider this example..
        
        ```cpp
        Vector operator+(const Vector& a, const Vector& b)
        {
        	if (a.size()!=b.size())
        		throw Vector_size_mismatch{};
        
        	Vector res(a.size());
        	for (int i=0;i!=a.size();++i)
        		res[i]=a[i]+b[i]
        	return res;
        }
        ```
        
        - Returning from `+` involves copying the result out of the local variable `res` and into some place where the caller can access it. We might use `+` like this...
            
            ```cpp
            void f(const Vector& x, const Vector& y, const Vector& z)
            {
            	Vector r;
            	//...
            	r = x+y+z;
            	//...
            }
            ```
            
            - That would a copy a vector at least twice. If container is a large that can be embarrassing.
    - We didn’t really want to copy, we just wanted to get the result out of the function. We wanted to move a Vector rather than to copy it.
    - Moving
        
        ```cpp
        class Vector {
        	//...
        	
        	Vector(const Vector* a);  // copy constructor
        	Vector& operator=(const Vector& a);  // copy assignment
        	
        	Vector(Vector&& a);  // move constructor
        	Vector& operator=(Vector&& a); // move assignment
        }
        ```
        
        - Given that definition, the compiler will choose the `move constructor` to implement transfer of the return value out of the function. This means `r=x+y+z` will involve no copying of `Vector`s. Instead, `Vector`s will just moved.
        
        ```cpp
        Vector::Vector(Vector&& a)
        	:elem{a.elem},  // grab the elements from a
        	 sz{a.sz}
        {
        	a.elem = nullptr;
        	a.sz = 0;
        }
        ```
        
        ```cpp
        Vector f()
        {
        	Vector x(1000);
        	Vector y(1000);
        	Vector z(1000);
        	//...
        	z = x;  // we get a copy
        	y = std::move(x);  // we get a move
        	// ...
        	return z;  // we get a move
        }
        ```
        
        - The `&&` means “rvalue reference” and is a reference to which we can bind an rvalue. The word rvalue is intended to complement lvalue which roughly means “something that can appear on the left-side of an assignment”. So an rvalue means - to a first approximation - a value that you can’t assign to, such an integer returned by a function call, and an rvalue is a reference to something that nobody else can assign to. The `res` local variable in `operator+()` for vector is an example.
- **Resource Management**
    
    By defining constructors, copy operations, move operations, and a destructor, a programmer can provide complete control of the lifetime of a contained resource. Furthermore, a move constructor allows to move simply and cheaply from one scope to another. That way, objects that we cannot or would not want to copy out of scope can be simply and cheaply moved out instead.
    
    Consider a standard-library `thread` representing a concurrent activity and a `Vector` of million `double`s. We can’t copy the former and don’t want to copy the later.
    
    ```cpp
    std::vector<thread> my_threads;
    
    Vector init(int n)
    {
    	thread t {heartbeat};  // run heartbeat concurrently on it's own thread
    	my_threads.push_back(move(t));
    	//.... more initialization ....
    
    	Vector vec(n);
    	for (int i=0;i<vec.size();++i) vec[i]=777;
    	return vec;  // move res out of init()
    }
    
    auto v = init();  // start heartbeat and initialize v
    ```
    
    This makes resource handles, such as Vector and thread, an alternative to using pointers in many cases. In fact, the standard-library “smart pointers”, such as `unique_ptr`, are themselves resource handles.
    
    In very much the same way as new and delete disappear from application code, we can make pointers disappear into resource handles. In both cases, the result is simpler and more maintainable code, without added overhead. In particular, we can achieve strong resource safety; that is, we can eliminate resource leaks for a general notion of resource. Examples are vectors holding memory, threads holding system threads, and `fstream`s holding file handles.
    
- **Suppressing Operations**
    
    Using default copy or move for a class a hierarchy in a disaster, give only a pointer to a base, we simply don’t know what member derived class has. So we can’t know how to copy them. So best thing to do is delete the default copy and move operations
    
    ```cpp
    class Shape {
    public:
    	Shape(const Shape&) =delete;   // no copy operations
    	Shape& operator=(const Shape&) =delete;
    
    	Shape(Shape&&) =delete;  // no move operations
    	Shape& operator=(Shape&&) =delete;
    
    	~Shape();
      //...
    }
    ```
    
    - Now attempt to copy a `Shape` will be caught by the compiler.
    - If you need to copy an object in a class hierarchy write some kind of clone function (explained later).

## Templates

Someone who wants a vector may not always want to use it with only `double`s. 

A template is a class or a function that we parameterise with a set of types or values.

- **Prameterized Types**
    - **Basic Definitions**
        
        ```cpp
        template<typename T>
        class Vector {
        private:
        	T* elem;  // elem points to an array of sz elements of type T
        	int sz;
        public:
        	Vector(int s);
        	~Vector() { delete[] elem; }
        
        	// ... copy and move operations ...
        
        	T& operator[](int i);
        	const T& operator[](int i) const;
        	int size() const { return sz; }
        }
        ```
        
        Define the member function.
        
        ```cpp
        template<typename T>
        Vector<T>::Vector(int s)
        {
        	if (s<0) throw Negative_size{};
        	elem = new T[s];
        	sz = s;
        }
        
        template<typename T>
        const T& Vector<T>::operator[](int i) const
        {
        	if (i<0 || size()<=i)
        		throw out_of_range{"Vector::operator[]"};
        	return elem[i];
        }
        ```
        
        Given the definitions, we can define `Vector` s like this.
        
        ```cpp
        Vector<char> vc(200);  // vector of 200 characters
        Vector<string> vs(17);  // vector of 17 strings
        Vector<list<int>> vli(45);  // vector of 45 lists of integers
        ```
        
    - Support rang-for loop → we must define `begin()` and `end()` functions:
        
        ```cpp
        template<typename T>
        T* begin(Vector<T>& x)
        {
        	return &x[0];  // pointer to first element
        }
        
        template<typename T>
        T* end(Vector<T>& x)
        {
        	return x.begin()+x.size()  // pointer to one-past-last element
        }
        ```
        
        Given those two above we can write.
        
        ```cpp
        void f2(const Vector<string>& vs)  // Vector of some strings
        {
        	for (auto& s : vs)
        		cout << s << '\n';
        }
        ```
        
- **Function templates**
    
    Templates are extensively used for parameterisation of both types and algorithm in the standard library. For example, we can write function that calculates the sum of the element values of any container like this.
    
    ```cpp
    template<typename Container, typename Value>
    Value sum(const Container& c, Value v)
    {
    	for (auto x : c)
    		v+=x;
    	return v;
    }
    ```
    
    ```cpp
    // Usage
    
    void user(Vector<int>& vi,
    					std::list<double>& ld,
    			    std::vector<complex<double>>& vc)
    {
    	int x = sum(vi,0);
    	double d = sum(vi,0.0);
    	double dd = sum(ld,0.0);
    	auto z = sum(vc,complex<double>{});
    }
    ```
    
    - Simplified version of standard library - `accumulate`
- **Function objects Or functor**
    
    Used to define objects that can be called like functions.
    
    ```cpp
    template<typename T>
    class Less_than {
    	const T val;  // value to compare against
    public:
    	Less_than(const T& v) :val{v) {}
    	bool operator()(const T& x) const { return x<val; } // call operator
    }
    
    Less_than<int> lti(42);  // lti(i) will compare i to 42 using i<42
    Less_than<string> lts("Backups"); // lts(s): s<"Backups";
    ```
    
    Such functions are wildly used as arguments to algorithm.
    
    ```cpp
    // Count the occurrences of values for which a predicate returns true
    
    template<typename C, typename P>
    int count(const C& c, P pred)
    {
    	int cnt = 0;
    	for (const auto& x : c)
    		if (pred(x)):
    			++cnt;
    	return cnt;
    }
    ```
    
    A predicate is something we can invoke to return true or false.
    
    ```cpp
    void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
    {
    	cout << "number of values less than" << x
    			 << ": " << count(vec,Less_than<int>{x})
    			 << "\n";
    
    	cout << "number of values less than" << s
    			 << ": " << count(lst,Less_than<string>{s})
    			 << "\n";
    
    }
    ```
    
    - Function objects used to specify the meaning of key operations of a general algorithm are often referred to as - `policy objects`.
    
    **There is a notion for implicitly generating function objects.**
    
    Less_than is defined separately from it’s use, this can be inconvenient.
    
    ```cpp
    void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
    {
    	cout << "number of values less than " << x
    			 << ": " << count(vec, [&](int a){ return a<x; })
    		   << "\n";
    
    	cout << "number of values less than " << s
    			 << ": " << count(lst, [&](const string& a){ return a<s; })
    		   <<< "\n";
    }
    ```
    
    **Lambda expression**
    
    The notion `[&](int a){ return a<x;}` is called lambda expression.
    
    - `[&]` is  a capture list specifying that local names used (such as x) will be passed by reference.
    - Had we wanted to capture only `x`, we could have said so: `[&x]`.
    - Had we wanted to give the generated object a copy of `x` , we could have said so: `[=x]`.
    - Capture nothing is - `[=]`.
- Get rid of annoyance of writing multiple functions of `vector`s of pointers and `unique_ptr`s, such as `draw_all`, `rotate_all`.
    
    
    We first need a function that applies an operation to each object pointed to by the elements of a container of pointers.
    
    ```cpp
    template<class C, class Oper>
    void for_all(C& c, Oper op)  // assume that C is a container of pointers
    {
    	for (auto& x : c)
    		op(*x);  // pass op() a reference to each element pointed to
    }
    ```
    
    Now we can write a version of `user()` without writing a set of `_all` functions.
    
    ```cpp
    void user()
    {
    	vector<unique_ptr<Shape>> v;
    	while (cin)
    		v.push_back(read_shape(cin));
    	for_all(v,[](Shape& s){ s.draw(); });  // draw_all
    	for_all(v,[](Shape& s){ s.rotate(45); });  // rotate_all(45)
    }
    ```
    
- **Variadic Templates**
    
    A template can be defined to accept an arbitrary number of arguments of arbitrary types. Such template is called `Variadic template`.
    
    ```cpp
    template<typename T, typename... Tail>
    void f(T head, Tail... tail)
    {
    	g(head);  // do something to head
    	f(tail...);  // try again with tail
    }
    
    	void f() { }  // do nothing
    ```
    
    - The key is to note that when you pass a list of arguments to it, you can separate the first argument from the reset. We do something to the first argument then recursively call `f()` with the rest of the arguments (the `tail`). The ellipses, ..., is used to indicate “the rest” of a list.
    - Eventually `tail` will become empty and we need a separate function to deal with that.
    
    ```cpp
    template<typename T>
    void g(T x)
    {
    	cout << x << " ";
    }
    
    int main()
    {
    	cout << "first: ";
    	f(1,2.2,"hello");
    }
    ```
    
    - Weakness
        - Type checking of the interface is a possibly elaborate template program.
- **Aliases**
    - Surprisingly often, it is useful to introduce a synonym for a type or a template.
    - For Example
        
        Standard header <cstddef> contains a definition of the alias `size_t.`, maybe `using size_t = unsigned int;` 
        
    - Having an alias `size_t` allows the programmer to write portable code.
    - It is very common for a parameterised type  to provide an alias for types related to their template arguments.
    
    ```cpp
    template<typename T>
    class Vector {
    public:
    	using value_type = T;
    	// ...
    };
    ```
    
    - In fact, every standard-library container provides value_type as the name of it’s value type. This allows us to write code that will work for every container that follows this convention.
        
        ```cpp
        template<typename C>
        using Element_type = typename C::value_type;
        
        template<typename Container>
        void algo(Container& c)
        {
        	Vector<Element_type<Container>> vec;  // keep results here
          //...
        }
        ```
        
    - The aliasing mechanism can be used to define a new template by binding some or all template argument.
        
        ```cpp
        template<typename Key, typename Value>
        class Map {
        	// ...
        };
        
        template<typename Value>
        using String_map = Map<string, Value>;
        
        String_map<int> m;  // m is a Map<string,int>
        ```