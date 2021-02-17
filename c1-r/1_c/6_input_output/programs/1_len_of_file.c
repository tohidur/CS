#include<stdio.h>

int main() {
    FILE *fp;
    int len;

    fp = fopen("1_len_of_file.c", "r");
    if (fp == NULL)
        printf("Error opening file.");

    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    fclose(fp);
    printf("Total size of this program is %d bytes\n", len);

    return 0;
}
