#include<stdio.h>

int main() {
    char *name[] = {"tohi", "tohidur", "rohidurrahaman"};
    printf("%c\n", name[2][0]);
    printf("%c", *(*(name + 2)));
}
