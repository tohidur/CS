# Containers And Algorithms

## Libraries

**Few selected standard library headers**

| <algorithm> | copy(), find(), sort() |
| --- | --- |
| <array> | array |
| <chrono> | duration, time_point |
| <cmath> | sqrt(), pow() |
| <complex> | complex, sqrt(), pow() |
| <fstream> | fstream, ifstream, ofstream |
| <future> | future, promise |
| <iostream> | istream, ostream, cin, cout |
| <map> | map, multimap |
| <memory> | unique_ptr, shared_ptr, allocator |
| <random> | default_random_engine, normal_distribution |
| <regex> | regex, smatch |
| <string> | string, basic_string |
| <set> | set, multiset |
| <sstream> | istrstream, ostrstream |
| <thread> | thread |
| <unordered_map> | unordered_map, unordered_multimap |
| <utility> | move(), swap(), pair |
| <vector> | vector |

## **String**

- Concatenation
    
    ```cpp
    string compose(const string& naem, const string& domain)
    {
    	return name + '@' + domain;
    }
    
    auto addr = compose("dmr", "bell-labs.com");
    ```
    
    - You can concatenate a `string`, a string literal, a C style string, or a character.
- A standard string has move constructor so returning even long strings by value is efficient.
- A string is mutable.
- Subscripting operations are supported - `[]`.
- Ability to manipulate substrings.
    
    ```cpp
    string name = "Niels Stroustrup";
    
    void m3()
    {
    	string s = name.substr(6,10);  // s = "Stroustrup"
    	name.replace(0,5,"nicholas");  // // name becomes "nicholas Stroustrup"
      name[0] = toupper(name[0]);  // name becomes "Nicholas Stroustrup"
    }
    ```
    
    - `substr` - Fist argument is an index (position), second one is the length of the desired substring. Similar for `replace()`.

## **Stream I/O**

`iostream` library. More on STL I/O Stream chapter

- **Output**
    - I/O stream library defines output for every built-in type. Further, it’s easy to define output of a user defined type.
    - The operator `<<` (”put to”) is used as an output operator on objects of type `ostre` `count` is the standard output stream and `cerr` is the standard stream  for reporting error.
    - By default, values written to `cout` are converted  to a sequence  of characters.
- **Input**
    - STL offers `istream` for input.
    - Like `ostream` it deals with char representations of built-in types. Can easily be extended for user-defined types.
    - To read a sequence of number, the convenient way of doing that is read into a string.
        
        ```cpp
        void hell()
        {
        	string str;
        	cin >> str;
        }
        ```
        
    - Whitespace characters are discarded by `cin`. Use `getline()` if you want to read the whole line.
        
        ```cpp
        void hello_line()
        {
        	cout << "Please enter you name\n";
        	string str;
        	getline(cin,str);
        	cout << "Hello, " << str << "!\n";
        }
        ```
        
- **I/O of User-Defined Types**
    
    Consider a simple type `Entry` used to represent entries in a telephone book.
    
    ```cpp
    struct Entry {
    	string name;
    	int number;
    }
    ```
    
    - **Output Operator**
        
        ```cpp
        ostream& operator<<(ostream& os, const Entry& e)
        {
        	return os<<"{\""<<e.name<<"\","<<e.number<<"}";
        }
        ```
        
    - **Input Operator**
        
        ```cpp
        isteam& operator>>(istream& is, Entry e)
        	// read {"name", number} pair. Note: formatted with {" ", and }
        {
        	char c, c2;
        	if (is>>c && c=='{' && is>>c2 && c2=='"') {  // start with {"
        		string name;  // the default value of string is the empty string ""
        		while(is.get(c) && c!='"')  // anything before closing " is part of the name
        			name+=c;
        		
        		if (is>>c && c==',') {
        			int number = 0;
        			if (is>>number>>c && c=='}') { // read the number and a }
        				e = {name,number};
        				return is;
        			}
        		}
        	}
        	is.setf(ios_base::failbit);  // register the failure in the stream
        	return is;
        }
        ```
        
        - An input operation returns a reference to its istream which can be used to test if the operation succeeded. For example, when we used a condition, `is>>c` means “Did we succeed at reading from `is` into `c`?”.
        - `is>>c` skips white space by default, but `is.get(c)`does not
        - Read such pair of values
            
            ```cpp
            for (Entry ee : cin>>ee;)
            	cout << ee << '\n';
            ```
            

## **Containers**

A class with the purpose of holding objects is commonly called `container`. Like, `strings` holding characters.

### vector

A vector is a sequence of elements of a given type. The elements are stored contiguously in memory.

- We can initialise a vector with a set of values of its element type.
    
    ```cpp
    vector<Entry> phone_book = {
    	{"David Home", 123456},
    	{"Karl Popper", 234567},
    }
    ```
    
- Elements are to be accessed through subscripting.
- range-for loop can be used.
    
    ```cpp
    void print_book(const vector<Entry>& book)
    {
    	for (const auto& x : book)
    		cout<<x<<'\n';
    }
    ```
    
- While defining a `vector` we give an initial size and optional initial element value.
    
    ```cpp
    vector<int> v1 = {1, 2, 3, 4}; // size is 4
    vector<string> v2;  // size is 0
    vector<Shape*> v3(23);  // size is 23; initial element value: nullptr
    vector<double> v4(32, 9.9);  // size is 32; initial element value: 9.9
    ```
    
- Initial size can be changed. `push_back()` increasing its size by 1.
    
    ```cpp
    void input()
    {
    	for (Entry e; cin>>e;)
    		phone_book.push_back(e);
    }
    ```
    
- Assigning `vector`s involves copying its elements. That can be expensive for too many elements. You need rely on references of pointers of move operation when possible.

## Elements

`vector` is a container of elements of type `T` : `vector<T>`. `T`can be built ins (`char`, `int`, `double`) or user-defined (`string`, `Entry)`or pointers (`const char*`, `Shape*`). When you insert a new element its value is copied into the container. For example if you insert an integer `7`, its value is copied not some reference or pointer. If you care about memory sizes and run-time performance this is critical.

## Range Checking

Standard library `vector` does not guarantee range checking.

```cpp
void silly(vector<Entry>& book)
{
	int i = book[ph.size()].number; // book.size() is out of range
}
```

- Leads to a common problem of out of range.
- Simple range checking vector adaption.
    
    ```cpp
    template<typename T>
    class Vec : public std::vector<T> {
    public:
    	using vector<T>::vector; // using the constructor from vector under the name Vec.
    	
    	T& operator[](int i)  // range check
    		{ return vector<T>::at(i); }
    
    	const T& operator[](int i) const  // range check const objects
    		{ return vector<T>::at(i); }
    };
    ```
    
- The `at()` operation is `vector` subscript operation that throws an exception of type `out_of_range` if its argument is out of the `vector`s range.
- User can catch the exception now.
    
    ```cpp
    void checked(Vec<Entry>* book) {
    	try {
    		book[book.size()] = {"Joe", 9999999}; // will throw an exception
    		//...
    	}
    	catch(out_of_range) {
    		cout << "range error\n";
    	}
    	catch (...) {  // default exception
    		cerr<<"unknown exception thrown\n";
    	}
    }
    ```
    

### list

STL offers a double-linked list called `list`.

```cpp
list<Entry> phone_book = {
	{"David Home",123456},
	{"Karl Popper",234566}
};
```

- Here we tend not to access by subscripting like vector. We search the list looking for the value.
    
    ```cpp
    int get_number(const string& s)
    {
    	for (const auto& x : phone_book)
    		if (x.name==s)
    			return x.number;
    	return 0;  // use 0 to represent "number not found"
    }
    ```
    
- Every STL container provides functions `begin()` and `end()`, which returns as iterator to the first and to one-past-the-last element.
    
    ```cpp
    int get_number(const string& s)
    {
    	for (auto p = phone_book.begin(); p!=phone_book.end(); ++p)
    		if (p->name==s)
    			return p->number;
    	return 0;
    }
    ```
    
    - Given an iterator `p`, `*p` is the element to which it refers, `++p` advances `p` to refer to the next element and when `p` refers to a class with a member `m`, then `p->m` is equivalent to `(*p).m`.
- Adding an element to the list and removing element from a list is easy. A vector performs better for traversal (e.g., find() and count()) and for sorting and searching (e.g., sort() and binary_search()).
    
    ```cpp
    void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
    {
    	phone_book.insert(p,ee);  // add ee before element referred to by p
    	phone_book.erase(q);  // remove the element referred to by q
    }
    ```
    
    - Unless you have a reason not to, use a vector instead of list.

### **map**

Writing code to look up the name is tedious and liner search is inefficient.

STL offers search tree(a red-black tree) called `map`.

In other context `map` is known as an associative array or a dictionary. It is implemented as a balanced binary tree. Its a container of pairs of values optimised for lookup.

```cpp
map<string,list> phone_book = {
	{"David Home",123456},
	{"Karl Popper",234566}
}
```

- Its binary search so complexity is `O(long(n)`.
- If key not present the default value is default of `value`. Default of integer is 0.
- You can use `find()` and `insert()` instead of `[]`.

### unordered_map

Use hashed lookup which is much more efficient nearly O(1).

```cpp
unordered_map<string,list> phone_book = {
	{"David Home",123456},
	{"Karl Popper",234566}
}
```

- STL unordered_map provides a default hash function for `string`s. If necessary you can provide your own.

### Container Overview

Standard Container Summary

| vector<T> | A variable size vector |
| --- | --- |
| list<T> | A double-linked list |
| forward_list<T> | A singly-linked list |
| deque<T> | A double-ended queue |
| set<T> | A set |
| multiset<T> | A set in which value can occur many times |
| map<K,V> | An associative array |
| multimap<K,V> | A map in which key can occur many times |
| unordered_map<K,V> | A map using a hashed lookup |
| unordered_multimap<K,V> | A multimap using hashed lookup |
| unordered_set<T> | A set using hashed lookup |
| unordered_multiset<T> | A multiset using a hashed lookup |

## Algorithms

STL provides the most common algorithms for containers.

- Sort a vector a place each unique element to a list
    
    ```cpp
    bool operator<(const Entry& x, const Entry& y)  // less than
    {
    	return x.name<y.name;  // orders Entrys by their name
    }
    
    void f(vector<Entry>& vec, list<Entry>& lst)
    {
    	sort(vec.begin(),vec.end());  // use < for order
    	unique_copy(vec.begin(),vec.end(),lst.begin());  // don't copy adjacent equal elements
    }
    ```
    
- If we want to place the unique elements in a new container..
    
    ```cpp
    list<Entry> f(vector<Entry>& vec)
    {
    	list<Entry> res;
    	sort(vec.begin(),vec.end());
    	unique_copy(vec.begin(),vec.end(),back_inserter(res));  // appends to res
    }
    ```
    
    - `back_inserter()` extends the container also. So, no need for C-style memory management using `realloc`.
    - You can use container version of `sort(vec)` instead of iterator version `sort(vec.begin(),vec.end())`.

### Use of Iterators

- In container many iterator referring to use elements can be obtained. In addition many algorithms returns iterators for example `find().`
    
    ```cpp
    bool has_c(const string& s, char c)
    {
    	return find(s.begin(),s.end(),c)!=s.end();
    }
    ```
    
- Find location of all occurrences of a character in a string - `find_all` (custom)
    
    ```cpp
    vector<string::iterator> find_all(string& s, char c)
    {
    	vector<string::iterator> res;
    	for (auto p = s.begin();p!=s.end();++p)
    		if (*p==c)
    			res.push_back(p);
    	return res;
    }
    ```
    
- We can generalise `find_all`(custom).
    
    ```cpp
    template<typename C, typename V>
    vector<typename C::iterator> find_all(C& c, V v)
    {
    	vector<typename C::iterator> res;
    	for (auto p = c.begin();p!=c.end();++p)
    		if (*p==v)
    			res.push_back(p);
    	return res;		
    }
    ```
    
    - `typename` inside a function is needed to inform the compiler that `C`'s iterator is suppose to be a type and not a value of some type.
    - We can hide this implementation detail by introducing a type alias for `iterator`.
        
        ```cpp
        template<typename T>
        using iterator<T> = typename T::iterator;
        
        template<typename C, typename V>
        vector<iterator<C>> find_all(C& c, V v)
        {
        	vector<iterator<C>> res;
        	for (auto p=c.begin();p!=c.end();++p)
        		if (*p==v)
        			res.push_back(p);
        	return res;
        }
        ```
        

### Iterator types

A object of some sort. Different containers has different iterator types.

- `vector`s iterator is an ordinary pointer.
- `vector`s iterator can implemented as a pointer to the vector plus an index.
`iterator: (start == p, position == 3)`. Using such iterator will allow range checking.
- `list` iterator is slightly more complicated than a simple pointer referring to element. Because an element does not know where the next element is. So, iterator points to a link rather than element.
- Most importantly all iterators have common semantics and operations. `++` shifts to next element. `*` yields the element.
- User doesn’t need to know the type of iterator, containers knows it. And makes them available under the name of `iterator` and `const_iterator`. For example: `list<Entry>::iterator`.

### Stream iterators

- Iterators are not only needed with containers. There are other places we need it like input and output stream. Use of `ostream_iterator`.
    
    ```cpp
    ostream_iterator<string> oo {cout};  // write strings to cout
    
    // The effect of assigning to *oo is to write the assigned value to cout
    int main()
    {
    	*oo = "Hello, ";
    	++oo;  // To mimic writing into an array through a pointer.
    	*oo = "world!\n";
    }
    ```
    
- `istream_iterator`
    
    ```cpp
    istream_iterator<string> ii {cin};
    ```
    
    Input iterators are used in pairs representing a sequence, so we must provide the stream iterator to indicate the end of input. This is the default `istream_iterator`.
    
    ```cpp
    istream_iterator<string> eos {};
    ```
    
- Typically, `istream_iterator`s and `ostream_iterator`s are not used directly. Instead, they are provided as arguments to algorithms. 
For example: we can write a simple program to read file, sort the words read, eliminate duplicates, and write the result to another file.
    
    ```cpp
    int main()
    {
    	string from, to;
    	cin >> from >> to;  // get source and target file names.
    
    	ifsteam is {from};  // input stream from file "form"
    	istream_iterator<string> ii {is};  // input iterator for stream
    	istream_iterator<string> eos {};  // input sentinel
    
    	ofstream os{to};  // output stream for file "to"
    	ostream_iterator<string> oo {os, "\n";};
    	
    	vector<string> b {ii,eos};  // b is a vector initialised from input [ii:eos)
    	sort(b.begin(),b.end())  // sort the buffer
    	
    	unique_copy(b.begin(),b.end(),oo); // copy buffer to output, discard replicated values.
    
    	return !is.eof() || !os;  // return error state
    }
    ```
    
    - A more elegant solution: Use set to store which avoids duplication and keeps elements is order. And replace unique_copy with just `copy`.
        
        ```cpp
        int main()
        {
        	string from, to;
        	cin >> from >> to;
        	
        	ifstream is{from};
        	ofstream oo{to};
        	
        	set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}};  // read input
        	copy(b.begin(),b.end(),ostream_iterator<string>{os, "\n"});  // copy to output
        	
        	return !is.eof() || !os;
        }
        ```
        

### Predicates

Sometimes the action we are performing inside an algorithm, we want to make that action a parameter to the algorithm: a `predicate`.

- Search map for a fist value larger than 42.
    
    ```cpp
    void f(map<string,int>& m)
    {
    	auto p = find_if(m.begin(),m.end(),Greater_than{42});
    }
    
    struct Greater_than {
    	int val;
    	Greater_than(int v) : val{v} {}
    	bool operator()(const pair<string,int>& r) { return r.second>val; }
    }
    ```
    
- Alternatively you can use lambda expression.
    
    ```cpp
    int cxx = count_if(m.begin(),m.end(),
    						       [](const pair<string,int>& r) { return r.second>42; });
    ```
    

### Algorithm Overview

- Definition
A finite set of rules which gives a sequence of operations for solving a specific set of problems [and] has five important features: `Finiteness`, `Definiteness`, `Input`, `Output`, `Effectiveness`. - Knuth
- Algorithms are present in `<algorithm>` header.
- A half open sequence from `b` to `e` is referred to as `[b:e)`.
- **Selected Standard Algorithms**
    
    
    | p=find(b,e,x) | p is the first p in [b:e) so that *p==x |
    | --- | --- |
    | p=find_if(b,e,f) | p is the first p in [b:e) so that f(*p)==true |
    | n=count(b,e,x) | n is the number of elements *q in [b:e) so that *q == x |
    | n=count_if(b,e,f) | n is the number of elements *q in [b:e) so that f(*q)==true |
    | replace(b,e,v,v2) | Replace elements *q in [b:e) so that *q==v by v2 |
    | replace_if(b,e,f,v2) | Replace elements *q in [b:e) so that f(*q)==true, by v2 |
    | p=copy(b,e,out) | Copy [b:e) to [out:p) |
    | p=copy_if(b,e,out,f) | Copy elements *q from [b:e) so that f(*q)==true to [out:p)   |
    | p=unique_copy(b,e,out) | Copy [b:e)  to [out:p); don’t copy adjacent duplicates |
    | sort(b,e) | Sort elements using <as sorting criterion |
    | sort(b,e,f) | Sort elements of [b:e) using f as the sorting criterion |
    | (p1,p2)=equal_range(b,e,v) | [p1,p2) is the subsequence of the sorted sequence [b:e) with the value v; basically a binary search for v |
    | p=merge(b,e,b2,e2,out) | Merge two sorted sequences [b:e)  and [b2:e2) into [out:p) |
    

### Container Algorithms