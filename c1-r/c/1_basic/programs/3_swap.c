#include <stdio.h>

int swap(int*, int*);

int main() {
    int x, y;
    printf("Enter the values of x an y\n");
    scanf("%d %d", &x, &y);

    swap(&x, &y);

    printf("After swaping \nx = %d\ny = %d\n", x, y);

    return 0;
}

int swap(int *a, int *b) {
    int temp;

    temp = *b;
    *b = *a;
    *a = temp;

    return 0;
}

