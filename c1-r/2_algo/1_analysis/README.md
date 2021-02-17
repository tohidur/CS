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
 