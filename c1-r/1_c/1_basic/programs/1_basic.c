#include <stdio.h>

int main() {
    int n;
    do {
        printf("Enter a value \n");
        scanf("%d", &n);
    } while(n < 0);

    printf("n value: %d", n);
}

