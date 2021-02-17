#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 100

char* resize(char *p, int count);

int main() {
    int count = 0, capacity = DEFAULT_SIZE;

    char *input, *temp;
    char ch;

    input = (char *)malloc((DEFAULT_SIZE * sizeof(char)));

    while ((ch = getchar()) != EOF) {
        if (count == capacity) {
            input = resize(input, capacity);
            capacity = capacity + DEFAULT_SIZE;
        }
        input[count++] = ch;
    }
    puts(input);
    return 0;
}

char* resize(char *p, int capacity) {
    printf("resizing");
    return realloc(p, ((capacity + DEFAULT_SIZE) * sizeof(char)));
}
