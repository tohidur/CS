#include<stdio.h>

int main()
{
    int a[] = {2, 3, 4};
    int *p = &a[0];
    printf("%u\n", p);
    printf("%u\n", &a[0]);
    printf("%u\n", &a[0] + 1);
    printf("%u\n", p + 1);

    // if p is a pointer you can use it as if it is an array
    printf("%d\n", a[2]);
    printf("%d\n", p[2]);

    // So
    // *(p+3) = a[3] = p[3]
    // p+3 = a+3 = &a[3]
    // a is NOT a variable - mnemonic
    // p is a varaible
}

