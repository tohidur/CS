### Asymptotic Notation  
- **Big-O**  
  X-Axis - input size - n.  
  Y-Axis - time taken - t.  
  Time is increasing with n - f(n).  
  Find out worst case.  
  So. Find out another function `c * g(n)` such a way that after some value `n0`  
  `f(n) < c * g(n);` - where n >= n0 and c > 0 and  n0 >= 1.  
  Then - `f(n) = Big-O(n)`.  
  
  There will be more upper bound n^2, n^3. Take lowest one.  

- **Big-Omega**  
  For lower bound.  
  `f(n) >= c * g(n);` - where n >= n0, c > 0 and n0 >= 1  
  Then - `f(n) = Big-Omega(n)`.  

  There will be more lower bound log n, log log n. Take upper one.  

- **Big-Theta**  
  Average Case - If a function is both lower and upper bound.  
  `c1 * g(n) <= f(n) <= c2g(n)` - where c1, c2 > 0, n >= n0, n0 >= 1.  
  Then - `f(n) = Big-Theta(n)`.  
  
  `3n^3 + n^2` - Always Big-Theta(n ^ 3).  


- **Examples**  
  - Example1  
    ```
    A() {
        i = 1, s = 1;
        while( s <= n) {
            i++;
            s = s + i;
        }
    }
    n - 1   2   3   4   5
    k - 1   3   6   10  15 
    First n natural number - (K(K+1)) / 2;

    k = O(root(n))
    ```
  
  - Ex2  
    ```
    i = 1
    for (i = 1; i ^ 2 <= n; i++)
        print("something");
    
    i ^ 2 = n;
    i = root(n);
    so from 1 to roo(n) time - O(root(n)) or Theta(root(n))
    ```
  
  - Ex3  
    ```
    A()
    {
        int i, j, k, n;
        for (i = 1; i <= n; i++) {
            for (j = 1; i <= i; j++) {
                for(k=1; k <= 100; k++) {
                    pf("something");
                }
            }
        }
    }
    ```
  
  - Ex4  
    ```
    A() {
        int i, j, k, n;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= i ^ 2; j++) {
                for (k=1; k <= n/2; k++) {
                    pf("something");
                }
            }
        }
    }
    
    2 ^ 1 * 1 / 2
    2 ^ 2 * 2 / 2
    2 ^ 3 * 3 / 2
    2 (n(n+1)/2) * (n(n+1)/2)/ 2
    
    OR
    
    (n/2) * (1 + 4 + 9 + ... + n ^ 2) - Sum of squares of first n natural numbers - (n (n + 1) (2n + 1)) / 6

    O(n ^ 4)
    ```
  
  - Ex5  
    ```
    A() {
        int i, j, k, n;
        for (i = n/2; i <= n; i++) {
            for (j = 1; j <= n/2; j++) {
                for (k=1; k <= n; k=k*2) {
                    // constant time
                }
            }
        }
    }
    
    (n/2) * (n/2) * (log n)
    O(n ^ 2 log n)
    ```

  - Ex6  
    ```
    // Assume n >= 2
    A() {
        while(n>1)
        }
            n = n / 2;
        }
    }
    O(log n)
    ```
    
  - Ex 7  
    ```
    A() {
        for (i = 1; i <= n; i++) {
            for(j = 1; j <= n; j = j+i) {
                // constant time
            }
        }
    }
    
    1 - n time | 2 - n / 2 time | 3 - n / 3 time
    n (1 + 1/2 + 1/3 + 1/4 + ......) - log n definition
    O(n log n) 
    ```

  - Ex8  
    ```
    A() {
        int n = 2 ^ ( 2 ^ k)
        for (i = 1; i <= n; i++) {
            j = 2;
            while (j <= n) }
                j = j ^ 2;
                pf("ravi");
            }
        }
    }
    
    O(n * loglog n)    
    ```

#### Analysis of Recursive algo  
```
T(n) = c + 2 * T(n/2)
```
- Methods
  - Back Substitution (somewhat slow)
    ```
    Ex1:
    ---
    T(n - 1) = 1 + T(n - 2)
    T(n - 2) = 1 + T(n - 3)
    ...
    T(n) = K + T(n-k)
    k = n - O(n)
    
    Ex2:
    ---
    T(n) = n + T(n-1);
         = n + (n - 1) + ...... + 1
         = n(n + 1) / 2
         = O(n ^ 2)
    ```
    
  - Recursion Tree Method
    ```
    T(n) = 2T(n/2) + c; n > 1
    
              T(n)
            /   |  \
         T(n/2) c  T(n/2)   -- c
         / | \
    T(n/4) c T(n/4) ...     -- 2c
    .....                   -- 4c
    
    T(n) = c * (1 + 2 + 4 + 8 + ..... + n)
         = c * ((2 ^ k+1 - 1) / (2 - 1))
         = c ( 2 ^ k+1 -1)
         = c ( 2 ^ (log n + 1) - 1)
         = c ( 2n - 1 )
         = O(n)
    ```

- **How to compare two functions**  
    - **2 ^ n - n ^ 2 - Which is larger**   
      ```
      // Apply log on both side
      log 2 ^ n  ---  log n ^ 2
      n log 2    ---  2 log n
      n          ---  2 log n
      2 ^ 100    ---  2 log 2 ^ 100
      2 ^ 100    ---  2 * 100
      So 2 ^ n is bigger
      ```
    - **n ^ 2 -- n log n - which is larger**   
      ```
      // Cancel out common terms
      n ^ 2  ---  n log n
      n      ---  log n
      So n ^ 2 is larger 
      ``` 
    - **n -- (log n) ^ 100 - which is larger**  
      ```
      n             ---     (log n) ^ 100
      log n         ---     100 * log log n
      log 2 ^ 128   ---     100 * log log 2 ^ 128
      128           ---     100 * log 128
      128           ---     100 * 7 
      so (log n) ^ 100 is larger
      
      But if n = 2 ^ 1024
      1024  ---     1000 // n is larger
      After some values of n - n is always larger
      ```

    - **n ^ log n -- n log n - which one is larger**  
      ```
      2 ^ 1024 ^ 1024 =  2 ^ 1024 * 1024
      // OR
      // Apply log
      log n log n -- log n + log log n
      // n - 2 ^ 1024
      1024 * 1024 -- 1024 + 10
      ```    

- **Masters theorem**  
  ```
  T(n) = a T(n/b) + θ((n ^ k) * log^p n)
  a >= 1, b > 1, k >=0 and p is a real number
  
  1. if a > b^k - T(n) = θ(n^log (base b) a)
  2. if a = b^k
      i. if p > -1, then T(n) = θ(n^log (base b) a * log^(p+1) n)
     ii. if p = -1, then T(n) = θ(n^log (base b) a * loglog n)
    iii. if p < -1, then T(n) = θ(n^log (base b) a)
  3. if a < b^k
    i. if p >= 0, then T(n) = θ(n^k log^p n)
   ii. if p < 0, then T(n) = O(n^k) 
  ```
  
  - Ex1  
    ```
    T(n) = 3 T(n/2) + n^2
    a = 3, b = 2, k = 2, p = 0
    3 < 2^2
    a < b^k
    T(n) = θ(n^2 log^0 n)
         = θ(n^2)
    ```
  
  - Ex2  
    ```
    T(n) = 4T(n/2) + n^2
    a = 4, b = 2, k = 2, p = 0
    a = b^k
    T(n) = θ(n^(log4) * log^1 n)
    T(n) = θ(n^ log n)
    ```
  
  - Ex3  
    ```
    T(n) = T(n/2) + n^2
    a = 1, b = 2, k = 2, p = 0
    a < b^k
    T(n) = θ(n^2 * log^0 n)
    T(n) = θ(n^2)
    ```
  
  - Ex4  
    ```
    T(n) = 2^n T(n/2) + n^n
    a has to be constant
    So, master's theorem is not applicable here
    ```

-  
