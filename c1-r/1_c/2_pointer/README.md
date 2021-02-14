### Pointers and Array  
```c
int arr[5]; // System - Byte addresable - 1 addr for every 1 byte
int *p = arr; // Pointer to array. Here pointer and array behaves in the same way - arr[n] || p[n]
int adr = &arr; // Address of adr.
// or
p = &arr[0];

*(p+3) = arr[3];
p = p + 1; // Depending on the size of an element
```

### Address arithmetic  
- **Valid pointer operations**  
  - Assignment of pointer of same type  
    ```c
    int *p, *q;
    p = q;
    q = p;
    
    int arr[];
    p = arr;
    arr = p;  // [X] - Not possible
    
    char *c;
    p = (int *)c;  // Except c is void pointer (generic pointer)
    ```
  
  - Adding and subtracting a pointer and an integer. Multiplication is not allowed.  
  
  - Subtracting and comparing two pointers
    ```c
    if (p < q)
    
    "q - p + 1"  // How many elements between p and q including p and q.
                 // both should point to same array
    ```
  
  - Assigning or comparing to Zero (NULL check)  

- **Character pointers and functions**  
  ```c
  "tohidur"  // String constant
  char a[] = "tohidur";  // Array of char or string. Not a string constant; \0 null char at the end.
                         // You can modify it.
  char *p = "tohidur";  // String constant
                        // You can't modify it.
  p[3] <=> *(p+3)
  
  // strcpy program
  void strcpy(char *s, char *t) {
    while(*s++ == *t++);  // when \0 - Value of an expression is it's LHS value. So it will break.
  }
  ```

- **Array of pointers and Multi-D Array**  
  char *name[] = {"tohi", "tohidur", "tohidurrahaman"};  
  `name` is a array of pointers to characters.
  This initialization is called static initialization.
  There is one more initialization with the code - `malloc`
  
  - Access  
    ```c
    *(name + 1) - "t" will be printed
    *name + 1 - "o" will be printed
    *(*(name + 2) + 7) <=> name[2][7]
    ```
 
  - Multi-D array   
    ```c
    char arr[2][14] = {"toh", "tohidur", "tohidurrahaman"};
    ```
    - For multi-d all array have to be of same size. Even though you don't use it.
    - If you go with array of pointers you have the liberty to use different size rows. Saves space.
  
  - Multi-D array | Pointers | Function calls  
    - To function you need to pass pointers to array.
      `func(int a[5])` - This doesn't mean an array. It's a pointer.
      So, you need not even declare a size - `func(int a[])`
      Or just simple pointer - `func(int *a)`
    
    - 2D-Array  
      `func(int a[5][6]`
      `func(int a[][6]` - Also allowed
      `func(int (*a)[6])`- Also allowed
      But not - `func(int *a[6])`
        - `(*a)[6]` - a is a pointer of integer arr of 6 elements
        - `*a[6]` - a is an array container pointers
    
    - Check pointer operation program - on pointers/program folder
    
- **Pointers to Functions**  
  Not normally used and not recommended.
  ```c
  int sum(int, int);
  int *fp(int, int);
  /*
  This is wrong.
  Here, fp is function which returns a pointer to integer. () has higher precedence.
  */
  
  // Right way
  int (*fp)(int, int);
  
  // Similar to array sum points to the address no need to use - &
  fp = sum;
  s = (*fp)(5, 6);
  ```
  
  - Generic Pointer  
    ```c
    void* (*gp)(void*, void*)
    int* sum(int*, int*)
    
    // Type cast
    gp = (void* (void*, void*)) sum;
    ```
    
    Unlike type casting to primitive type, using pointer is better because there is not data loss. 

- **Some Complex Declaration**  
  - `char **argv`  
    - Passing parameter to function by command line argument to run main function. Here passing function as argument
      is difficult because it's not called by you.
    
    - argv is a pointer to a pointer to char

  - `int (*daytab)[13]`  
    `daytab` is a pointer to an array 13 integers

  - `int *daytab[13]`  
    `daytab` is an array of 13 pointer to integers
  
  - `void *comp()`  
    `comp` ia function which returns a generic pointer
  
  - `char (*comp)()`  
    `comp` is a pointer to a function which returns char.
  
  - `char (*(*f())[])()`  
    `f` is a function which returns a pointer to an array of pointers. Where each pointer of that array points
    to a function returning char.
  
  - `char (*(*f[3])())[5]`  
    `f` is an array of 3 pointers pointing to a function which returns a pointer to an array of 5 char elements
  