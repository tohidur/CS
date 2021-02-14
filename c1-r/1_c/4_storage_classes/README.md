### Storage Classes  
Storage classes are
- register
- static
- extern

- **Examples of storage classes**  
We are telling the compiler to store the variable to the register. Not activation record.
```c
int main() {
    register int i = 10;
    int *a = &i;  // Here register might not have address.
}
// Don't write program like this.


int main() {
    int i = 10;
    register int *a = &i;
    printf("%d", *a);
    return 0;
}
// This will work just fine


int main() {
    int i = 10;
    register static int i = 10;
    printf("%d", i);
    return 0;
}
// By static you are asking the compiler to store it in the data section
// By register you are asking the compiler to store it in the register.
// So compiler will get confused. 
// This is not possible
```

- **Example of static int**  
  Suppose you want to call a function many times and you want to count how many times you have called it.
  ```c
  int countFuncCall(void) {
    static int count = 0;  // not int count = 0;
                           // Static and global variable will always be initialized to zero.
    return ++count;
  }
  
  int main() {
    countFuncCall();
    countFuncCall();
    countFuncCall();
    printf("%d times function is called", countFuncCall());
    return 0;
  }
  
  int main() {
    static int i = 5;
    if (--i) {
        main();
        printf("%d", i);
    }
    return 0;
  }
  // Output will be - 00000
  ```

- **Example of global variable**  
  ```c
  #include<studio.h>
  
  int i;  // If it's declared as external variable then it will be stored in the data section, not activation record.
          // static and global variable will be initialized to zero if you don't initialize it.
  
  void func1() {
    i = 20;   // If no declaration then it will refer to global variable
    printf("%d", i);
  }
  
  void func2() {
    int i = 30;  // local variable has higher precedence compare to golbal variable
    printf("%d", i);
  }
 
  int main() {
    func1();
    func2();
    return 0;
  } 
  // Output: 20, 30
  ```

- **Storage management**  
  Heap is used for dynamically created data structure
  C has some functions in `stdlib.h` to access memory dynamically
  `size_t` - stands for any data type which is unsigned
  
  - `void *malloc(size_t n)`  
    Will give you pointer to starting address of n bytes in the heap
    ```c
    int *i;
    i = (int *)malloc(sizeof(int)); // typecast because void* is returned. Required for pointer arithmetic
    ```
    If `malloc` is not able to allocate memory then it will return null
    For `malloc` garbage values will be present in the memory space
    Will always give you space in a contiguous manner
  
  - `void *calloc(size_t n, size_t size)`  
    How many elements you want to store and what is the size of each element.
    Garbage value of entire space will be cleared. Everything will be initialized to zero
    Always gives you space in a contiguous manner
  
  - `void *realloc(void *ptr, size_t size)`  
    Already you have been allocated some space, now you want to resize it.
  
  - `void free(void *ptr)`  
    System will add an extra space with `malloc` and `calloc` to know how much space is allocated.
    `free` will access that that info and free up the entire memory
    For garbage collection
