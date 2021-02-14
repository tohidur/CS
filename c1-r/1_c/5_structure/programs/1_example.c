int example1() {
    struct node
    {
        int i;
        int j;
    };
    struct node a, *p;
    p = &a;
    a.i;
    (*p).i;

    // Structures will be created mostly dynamically by malloc which returns a pointer.
    // So instead of (*p) there is a new operator - short hand operator
    p -> i;  // If p is a pointer then we can access element from a structure pointed by p

    return 0;
}

// Structure use call by value when passing to function.
// So it is recommended to use pointer.

int example2 {
    struct node
    {
        int i;
        int *c;
    }

    struct node a[2], *p;
    int b[2] = {30, 40};
    p = &a[0];
    a[0].i = 10; a[1].i = 20;
    a[0].c = b;

    printf("%d", ++p -> i);  // i will be accessed and then incremented to 11 from 10. -> has higher precedence
    int x;
    x = (++p) -> i; // p will point to 2nd array element and i will be accessed. x = 20;

    p = &a[0];
    x = (p++) -> i; // post increment. x will get 20. then p will point to next element.

    p = &a[0];
    x = *p -> c; // 30 will be assigned

    p = &a[0];
    x = *p->c++; // 30 will be assigned. c will point to next integer in the array. Precedence -> , ++ , *

    p = &a[0];
    x = *p++->c;  // 30 will be printed and assigned. and p will point to second element of the array

    return 0;
}

int main() {
    example1();
    example2();
    return 0;
}
