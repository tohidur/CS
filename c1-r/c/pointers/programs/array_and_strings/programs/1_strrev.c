#include<stdio.h>
#include<string.h>

void reverse(char* s)
{
    int l, i;
    char *b, *e, ch;

    l = strlen(s);
    b = s;
    e = s;
    for(i = 0; i < l - 1; i++)
        e++;

    for (i = 0; i < l / 2; i++)
    {
        ch = *e;
        *e = *b;
        *b = ch;

        b++;
        e--;
    }
}


int main() {
    char s[]= "tohidur";
    reverse(s);
    printf("%s", s);
}


