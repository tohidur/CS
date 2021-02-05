// armstrong if - 371 == 3^3 + 7^3 + 1^3


#include <math.h>
#include <stdio.h>

int main() {
    int number, originalNumber, remainder, result=0, n=0;
    printf("Enter an integer\n");
    scanf("%d", &number);
    originalNumber = number;

    while (originalNumber != 0) {
        originalNumber /= 10;
        ++n;
    };

    originalNumber = number;

    while (originalNumber != 0) {
        remainder  = originalNumber % 10;  // 12(1)
        result += pow(remainder, n);
        originalNumber /= 10;
    };

    (result == number) ? printf("Armstrong Number") : printf("Not armstrong number");

    return 0;
}
