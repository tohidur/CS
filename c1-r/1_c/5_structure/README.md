### Structure  
To store elements of different types in one group (unlike array where each element is of same type)
```c
struct ex
{
    int i;
    char c;
} x, y, z;

x.i = 10;
x.c = 'a';

struct ex  // ex is a tag. It's not required but it's helpful to redefine or extend later.
{
    int i;
    char c;
};  // No memory allocated here
struct ex x, y, z;
struct ex x={10, 'a'}; // Initialization

// Nested structure
struct ex1
{
    struct ex a;
    struct ex b;
};
struct ex1 t;
t.a.i = 10;
```

#### Examples on structures, array and pointers  
Check programs section - `1_example.c`

#### Self referential structures
```c
struct ex
{
    int i;
    struct ex *link;
}

// For linked list, trees, graphs etc
// at first link will have garbage value. So accessig it without assigning it will give you segmentation fault
```

#### Create data structures dynamically
```c
int *p = (int *)malloc(sizeof(int));
```
- `malloc` use kernel call like `sbrk` to access memory
- To reduce system call when `malloc` is called it will call for bigger memory from system than required
- `malloc` - gives contiguous memory. But multiple `sbrk` call is maid and holes are there by `free` call then
  you will not have contiguous memory block. That is why `malloc` use linked list to link the memory blocks
  This is similar to `first-fit` of OS memory management.

```c
struct node
{
    int i;
    struct node *l;
};
struct node *p = (struct node *)malloc(sizeof(struct node));
p -> i = 1;
```
