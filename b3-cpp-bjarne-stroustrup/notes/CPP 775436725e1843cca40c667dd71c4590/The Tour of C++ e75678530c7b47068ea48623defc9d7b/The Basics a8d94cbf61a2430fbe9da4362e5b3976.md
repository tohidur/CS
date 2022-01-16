# The Basics

**Contents**

- Introduction
- The Basics
- User-Defined Types
- Modularity
- Postscript
- Advice

# 1. The Basics

- C++ is a statistically typed language.
- A nonzero value returned indicates faiure.
- `<<` - “put to” operator.
- Example Code
    
    ```cpp
    #include <iostream>
    using namespace std;  // make names for std visible without std::
    
    double square(double x) {  // square a double pricision floating-point number.
    	return x*x;
    }
    
    void print_square(double x) {
    	cout << "the square of" << x << "is" << square(x) << "\n";
    }
    
    int main() {
    	print_square(1.234);  // print: the square of 1.234 is 1.52276
    }
    ```
    
- In assignment and arithmetic operations, C++ performs all meaningful conversions between basic types so that they can be mixed freely.
    
    ```cpp
    void some_function() {
    	double d = 2.2;
    	int i = 7;
    	d = d * i;  // assign sum to d.
    	i = d * i;  // assign product to i (truncating the double d*i to an int)
    }
    ```
    
- Notations for expressing initialisation.
    
    ```cpp
    double d1 = 2.3;
    double d2 {2.3};
    
    complex<double> z = 1;  // a complex number with double precision floating-point scalars.
    complex<double> z2 {d1,d2};
    complex<double> z3 = {1,2};  // the = is optional with { ... }
    vector<int> v {1,2,3,4,5,6};  i// a vector of ints
    ```
    
    - In doubt, use the general {}-list form, it saves you from conversions which looses information.
        
        ```cpp
        int i1 = 7.2;  // becomes 7
        int i2 {7.2};  // error: floating-point to integer conversion
        int i3 = {7.2}; // error: floating-point to interger conversion (= is redundant)
        ```
        
    - When defining variable you don’t need to specify type explicitly when it can be deducted from initialiser.
        
        ```cpp
        auto b = true;
        auto ch = 'x';
        auto i = 123;
        auto d = 1.2;
        auto z = sqrt(y);  // z is a type whatever sqrt returns
        ```
        
        - With `auto` use `=` because there is no type conversion involved which can cause problem.
    - C++ offers some specific operators to modify a variable.
        
        ```cpp
        x+=y;  // x = x+y
        ++x;  // increment x by 1
        x-=y;
        --x;
        x*=y;
        x/=y;
        x%=y;
        ```
        
- Constants
    - `const`
    - `constexpr`
        - To be evaluated at compile time
        
        ```cpp
        const int dmv = 17;
        int var = 17;
        constexpr double max1 = 1.4*square(dmv);  // Ok if square(17) is constant expression
        constexpr double max2 = 1.4∗square(var);  // error: var is not a constant expression
        const double max3 = 1.4∗square(var);  // OK, may be evaluated at run time
        
        double sum(const vector<double>&);  // sum will not modify it's arguments
        vector<double> v {1.2, 3,4, 4.5};  // v is not a constant
        const double s1 = sum(v);  // Ok: evaluated at runtime
        constexpr double s2 = sum(v);  // sum(v) not constant expression
        ```
        
        - For a function to be usable in a `constexpr`, that is, in an expression that will be evaluated by the compiler, it must be defined `constexpr`.
        `constexpr double square(double x) { return x*x };`
        - 
- `>>` - “get from” operator.
    
    ```cpp
    bool accept2() {
    	int tries = 1;
    
    	while (tries < 4) {
    		cout << "Do you want to proceed (y or n)?\n";
    		char answer = 0;
    		cin >> answer;
    	
    		switch(answer){
    			case 'y':
    				return true;
    			case 'n':
    				return false;
    			default:
    				cout << "Sorry, I don't understand that.\n";
    				++tries;  // increment
    			}
    	}
    	cout << "I'll take that for a no.\n";
    	return false;
    }
    ```
    
- Pointers, Arrays, and Loops
    - Pointer Basic
        
        ```cpp
        char v[6];  // array of 6 characters
        char* p;  // pointer to a character
        
        char* p = &v[3];  // p points to v's fourth element
        char x = *p;  // *p is the object that p is points to
        
        // * - means contents of
        // & - means address of
        ```
        
    - C++ Simpler loop
        - With `:` operator
            
            ```cpp
            void print()
            {
            	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
            	
            	for(auto x : v)
            		cout << x << '\n';
            
            	for(auto x : {10, 21, 32, 43, 54, 65})
            		cout << x << '\n';
            
            	//...
            }
            ```
            
            - For every element in `v` place a copy in `x` and print it.
            - If we didn’t want to copy the value from `v` into the variable `x`, but rather just have `x` refer to an element, we could write...
                
                ```cpp
                void increment()
                {
                	int v[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
                	for (auto& x : v)
                			++x;
                }
                ```
                
                - The unary suffix `&` means “reference to”.  A reference is similar to pointer, except that you don’t need to use a prefix `*` to access the value.
                
                Also a reference can not be made to refer to a different object after it’s initialisation.
                
                When used in declaration, the operators (such as `&`, `*`, `[]`) are called declarator operators.
                    
                    ```cpp
                    T a[n];  // Array of n Ts
                    T* p;  // Pointer to T
                    T& r;  // reference to T
                    T f(A)  // function return a result of type T
                    ```
                    
    - `nullptr`
        
        We try to ensure that a pointer always points to an object, so that dereferencing it is valid. When we don’t have an object to point to or if we need to represent the notion of “no object available”, we give the pointer the value `nullptr`.
        
        ```cpp
        double* pd = nullptr;
        Link<Record>* lst = nullptr;  // pointer to a link to a record
        int x = nullptr;  // error: nullptr is pointer not integer
        ```
        
        - It is often wise to check that a pointer argument that is suppose to point to something, actually points to something
            
            ```cpp
            int count_x(char* p, char x)
            		// count the number of occurrences of x in p[]
            		// p is assumed to point to a zero-terminated array of chars (or to nothing)
            {
            	if (p==nullptr) return 0;
            	int count = 0;
            	for (; *p != 0; ++p)
            		if (*p == x)
            			++count;
            	return count;
            }
            ```
            
            - In older code, `0` or `NULL` is typically used instead of `nullptr`. However, using `nullptr` eliminates potential confusion between integers (such as `0` or `NULL`) and pointers (such as `nullptr`)

## 2. User-Defined Types

- **2.1 Structures**
    
    ```cpp
    struct Vector {
    	int sz;  // number of elements
    	double* elem; // pointer to element
    }
    
    void vector_init(Vector& v, int s)
    {
    	v.elem = new double[s];  // allocates an array of s doubles
    	v.sz = s;
    }
    
    double read_and_sum(int s)
    	// read s integers from cin and return their sum; s is assumed to be positive
    {
    	Vector v;
    	vector_init(v,s);
    	for (int i=0; i!=s; ++i)
    		cin >> v.elem[i];
    
    	double sum = 0;
    	for (int i=0; i!=s; ++i)
    		sum += v.elem[i];
    
    	return sum;
    }
    ```
    
    - We use `.` to access `struct` member through a name (and through a reference)
    and `->` to access struct member through a pointer.
        
        ```cpp
        void f(Vector v, Vector& rv, Vector* pv)
        {
        	int i1 = v.sz;
        	int i2 = rv.sz;
        	int i3 = pv->sz;
        }
        ```
        
- **2.2** **Classes**
    
    ```cpp
    class Vector {
    	public:
    		Vector(int s):
    			elem{new double[s]};
    			sz{s} {};
    			
    			double& operator[](int i) {  // subscript function
    				return elem[i];
    			}
    
    			int size() {
    				return sz;
    			}
    
    	private:
    		double* elem;
    		int sz;
    };
    
    double read_and_sum(int s)
    {
    	Vector v(s);
    	for (int i=0; i!=v.size(); ++i)
    		cin >> v[i];
    
    	double sum = 0;
    	for (int i=0;i!=v.size();++i)
    		sum+=v[i];
    	return sum;
    }
    ```
    
    - A function with same name as it’s class is called a constructor
- **2.3 Enumeration**
    
    ```cpp
    enum class Color {red, blue, green};
    enum class Trafic_light { green, yellow, red };
    
    Color col = Color::red;
    Trafic_light light = Trafic_light::red;
    
    // If you don't want to explicitly qualify enum names and want enumerator
    // values to be ints, you can remove the class from `enum class` to get plain
    // enum
    ```
    
    ```cpp
    Traffic_light& operator++(Trafic_light& t)
    		// prefix increment: ++
    {
    	switch(t) {
    			case Traffic_light::green: return t=Trafic_light::yellow;
    			case Traffic_light::yellow: return t=Trafic_light::red;
    			case Traffic_light::red: return t=Trafic_light::green;		
    	}
    }
    
    Traffic_light light = Traffic_light::red;
    Traffic_light next = ++light;
    ```
    

## 3. Modularity

- Distinguish between the interface to a part and its implementation. The key point here is that the function bodies, the function definitions are “elsewhere”.
    
    ```cpp
    Vector::Vector(int s)
    	:elem{new double[s]}, sz{s}
    {
    }
    
    double& Vector::operator[](int i)
    {
    	return elem[i];
    }
    ```
    
- **Separate Compilation**
    
    User code sees only declaration types, definitions are in separate file and compiled separately. To organise the program in semi-independent code fragments this helps minimise compilation time also.
    
    ```cpp
    // Vector.h
    
    class Vector {
    public:
    	Vector(int s);
    	double& operator[](int i);
    	int size();
    private:
    	double* elem;
    	int sz;
    };
    
    // user.cpp
    #include "Vector.h"
    #include<cmath>
    
    using namespace std;
    
    double sqrt_sum(Vector& v) {
    	double sum = 0;
    	for (int i=0;i!=v.size();++i)
    		sum+=sqrt(v[i]);
    	return sum;
    }
    
    // To help the compiler ensure consistency, the .cpp file providing th
    // implementation of Vector will also include the `.h` file providing it's
    // interface
    
    // Vector.cpp
    #include "Vector.h" // get the interface
    
    Vector::Vector(int s)
    	:elem{new double[s];}, sz{s}
    {
    }
    
    double& Vector::operator[](int i)
    {
    	return elem[i];
    }
    
    int Vector::size()
    {
    	return sz;
    }
    ```
    
- **Namespaces**
    
    For expressing that some declarations belong together and that names should’t clash with other names especially with standard-library names in the namespace `std`. The precaution is wise.
    
    ```cpp
    namespace My_code {
    	class complex { /*...*/ };
    	complex sqrt(complex);
    	// ...
    	int main();
    }
    
    int My_code::main()
    {
    	complex z {1,2};
    	auto z2 = sqrt(z);
    	std::count << '{' << z2.real() << ',' << z2.imag() << '}\n';
    	//...
    };
    
    int main()
    {
    	return My_code::main();
    }
    ```
    
- **Error Handling**
    - Exceptions
        - Vector - out of range access
            
            ```cpp
            double& Vector::operator[](int i)
            {
            	if (i<0 || size()<=i) throw out_of_range{"Vector::operator[]"};
            	return elem[i];
            }
            ```
            
            ```cpp
            void f(Vector& v)
            {
            	// ...
            	try {  // exceptions here are handled by handler defined below
            		v[v.size()] = 7; // try to access beyond the end of v
            	}
            	catch(out_of_range) {
            		//... handle range error
            	}
            
            	//...
            }
            ```
            
            - the `out_of_range` type is defined in standard-library.
    - Invariants
        - Whenever we define a function we should consider what its preconditions are and if feasible test them.
        - These pre conditions of what is assumed to be true for a class is called invariants. Like” **`elem`** points to an array of **`sz`** doubles’.
        - It is the job of constructor to establish the invariants for it’s class
        
        ```cpp
        Vector::Vector(int s)
        {
        	if (s<0) throw length_error{};
        	elem = new double[s];
        	sz = s;
        }
        ```
        
        - `length_error` is a `std` exception.
        - `bad_alloc` - another `std` exception. If `new` can’t find memory to allocate.
            
            ```cpp
            void test()
            {
            	try {
            		Vector v(-27);
            	}
            	catch (std::length_error) {
            	}
            	catch (std::bad_alloc) {
            	}
            }
            ```
            
    - You can define your own classes to be used as exceptions. Later in the note.
- **Static Assersions**
    - Usually preferable if exception can be found at compile time rather than run time.
    - Things we can know at runtime we should report failures at compile error message
        
        ```cpp
        static_assert(4<=sizeof(int), "integers are too small"); // check integer size
        ```
        
        - `static_assert` can be used for anything that can be expressed in terms of constant expressions.
            
            ```cpp
            constexpr double C = 299792.458;  //km/s
            
            void f(double speed) {
            	const double local_max = 160.0/(60*60);
            
            	static_assert(speed<C, "can't go that fast"); // error: speed must be constant
            	static_assert(local_max<C, "can't go that fast"); // OK
            }
            ```
            
            - Mostly used to check parameters in generic programming.