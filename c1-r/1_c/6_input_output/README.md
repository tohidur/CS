- **Formatted I/O**
  - `%wd`
    ```c
    scanf("%2d%3d", &a, &b);
    // 369 546
    a => 36
    b => 9
    
    // with printf if bits are > w then still C is going to print it
    printf("%3d", 32322);
    // Output: 32322
    ```
  - `%w.ns`
    ```c
    printf("%4s", "tohidur");  // At-least 4 if more then more will be printed
    printf("%.4s", "tohidur"); // Only 4 chars will be printed
    printf("%8.4s", "tohidur"); // Total fields size will be 8 chars out of which 4 will be printed.
                                // Leading 4 will be empty.
    ```
  - _Suppression char in scanf_  
   ```c
    scanf("%d%*c%d%*c%d", &x, &y, &z); // %*c - suppress a char
   ```

### File I/O  
```c
FILE *fp;A
FILE *fopen(char *name, char *mode);
int fclose(FILE *fp);
```
- `getc()` - reads a char from a file.
- `putc()` - writes a char to a file.
- `fscanf()`
- `fprintf()`
- `getw()` - reads an integer from a file
- `putw()` - writes an integer to a file
- `fseek()` - set the position to desire point
- `ftell()` - gives current position in the file
- `rewind()` - set the position to the beginning point

- _Closing a file using - `fclose`_   
  - In case there is any data in the buffer yet to process by system call that will get performed
  - Buffer memory will be collected
  - pointer relation to file will be freed
  - Anyway at the end of the program execution all the open file pointer will be closed

-  `fseek()`  
   `fseek(FILE *stream, long int offset, int whence)`
   - whence macros defined on stdio.h  
     - SEEK_SET - 0 - Beginning
     - SEEK_CUR - 1 - Current Pos
     - SEEK_END - 2 - End of the file
   - offset
     - positive value - right side
     - negative value - left side
   - return
     - 0 - success
     - Non 0 - failure
   - `fseek(fp, 0, SEEK_END);`  
     Got the end of the file and don't move (0)
     `len = ftell(fp);` - File size

- `gets() | puts()`  
  ```c
  char* gets(char *s); // Unline str will not stop on space it will stop on newline or EOF.
                       // going to return a string pointer for success and NULL for failure
  int puts(char *s);  // writes a strint s and a trailing new line
  ```

- Linux provides you 3 file pointers - stdin, stdout, stderr
  - `getchar()` <=> `getc(stdin)`
  - `printf()` <=> `putc(stdout)`

- Program to read stream of chars
  - check program - 2_read_char_stream.c

- `feof()`  
  ```c
  do {
    fscanf(q, "%s %d", e.name, e.age);
    printf("%s %d", e.name, e.age);
  } while(!feof(q));
  // returns 0 for EOF
  ``` 
 