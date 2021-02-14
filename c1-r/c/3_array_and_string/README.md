### Array  
Stored contiguously  
- **Row Major - Column Major 2D-Array**  
  Place it row after row or column after column contiguously
  ```c
  // For m X n 2D Array
  A[i][j] = (n * i + j) * size + Base
  ```
  
  - If row major then accessing row at a time will give you less number of page faults.
    For column major accessing column at a time will give you less number of page faults.
    These depends on your program  

- **Binary Addressing of 2D Array**  
  ```c
  // For m X n 2D Array
  A[i][j] = (n * i + j) * size + Base
  // (0 <= j <= n -1)
  
  // Consider n = 2 ^ k and m = 2 ^ l
  // Means we need k bits to represent n and l bits to represent m

  // To represnt the above equation in binary. Consider size = 2 ^ x
  ((i * 2 ^ k) + j) * (2 ^ x) + Base
  ((2 ^ l * 2 ^ k) + j) * (2 ^ x) + Base
  // So we need - l + k + x bits to represent 2D array
  ```
### String Operations  
- `char *strcat(s, t)`  
   Concat t to the end of s

- `char *strncat(s, t, n)`
  Concat n chars of t to the end of s

- `int strcmp(s, t)`  
  return negative, zero, positive for `s < t`, `s == t` and `s > t`

- `int strncmp(s, t)`  
  Same as above just for first n chars of t

- `void strcpy(s, t)`  
  copy t to s

- `void strncpy(s, t, n)`  
- `int strlen(s)`  
- `char *strchar(s, c)`  
  Returns pointer to first c. NULL if it's not present
