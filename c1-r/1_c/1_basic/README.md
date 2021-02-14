### C || Compile || Running
- **PreProcessor Directives**
  - `#include`
  - `#define`

- **How program works**
  ```
  HLL
   |
  Pre Processor  (RC - FI - ME)
   | Pure HLL
  Compiler
   | Assembly language
  Assembler
   | Machile code (recolatable)
  Loader | Linker
  ```
  - Get code after preprocessing  
    `gcc -E file.c > file.i`
  - To assembly language  
    `gcc -S file.i > file.s`
  - Machine language  
    `gcc -c file.s` - output: `file.o`
  - Linker  
    `gcc -o file1.o file.o`
  - Save all files  
    `gcc -Wall -save-temps file.c`

### Input and Data types   

 - **Format Specifiers**
   - `%d` - Decimal numbers
   - `%6d` - Will display 6 spaces - At-least 6 will be used
   - `%f` - Floating point
   - `%6f` - At-least 6 character float
   - `%2f` - At-least 2 chars after decimal point
   - `%c` - Print ASCII char
 
 - **Char - Input/Output**  
   - `getchar()` -> reads input char  
   - `putchar()` -> prints a char  
 
 - **Data Types and Sizes**
   - `char` -> typically 1 byte - can hole 0 - 255  
   - `int` ->  machine & compiler dependent
   - `float` -> at-least 32 bits required
   - `double` -> needs at-least 64 bits
   - `sizeof(int)`
 
 - **Quantifiers**  
   - `short`
   - `long`
   - `signed` - -127 - 127
   - `unsigned` - 0 - 255
 
 - **Enum**
   - Better readability  
     ```c
     enum boolean {NO, YES};
     enum months {JAN=1, FEB, MAR};
     ```
 
 - **Type Conversion**  
   Type conversion has to happen in a specific format. Lower size type needs to be changed to higher size type to avoid
   data loss.  
   ```
   long double
   double
   float
   short or int
   char
   
   a = b - look for data loss
   ```
   - `double sqrt(double) - sqrt(2) - 2 will be converted to double`
   - `i = (float) 10;`

### Operators  

 - **Bitwise Operations**  
   A(60) - 0011 1100
   B(13) - 0000 1100
   - `A & B (AND)` - 0000 1100
   - `A | B (OR)` - 0011 1100
   - `A ^ B (Exclusive OR)` - 
 
 - **Ternary Operator**  
   `(num % 2 == 0) ? printf("number is even") : printf("odd")`
 
- **Increment variable**  
  `n++` - post increment
  `++n` - pre increment

- **Precedence of Operations**  

  | Operators                             | Associativity |
  | -------------                         | ----------    |
  | ()  [] -> .                           | L -> R        |
u | ! ~ ++ -- + - * & (type) sizeof       | R -> L        |
  | * / %                                 | L -> R        |
  | + -                                   | L -> R        |
  | << >>                                 | L -> R        |
  | < <= > >=                             | L -> R        |
  | == !=                                 | L -> R        |
  | &                                     | L -> R        |
  | ^                                     | L -> R        |
  | |                                     | L -> R        |
  | &&                                    | L -> R        |
  | ||                                    | L -> R        |
  | ?:                                    | R -> L        |
  | = += -+ *= /= %= &= ^= pipe= <<= >>=  | R -> L        |
  | ,                                     | L -> R        |

### Functions
- Definition should be above usage
- If not definition then only declaration  
`int max(int, int);`
- Cannot return array and another function. You need to use pointers.
- Call by value - I C this is always followed.
- Call by reference - Need to use pointers
