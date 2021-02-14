#include<stdio.h>


void main() {
    int nc;
    for (nc=0; getchar() != EOF; ++nc);
    printf("%d", nc);
}

