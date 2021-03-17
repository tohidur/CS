#### Matrix

- **Multiplication**  
  A x B
  Needs to be compatible
  A = P x R
  B = R x Q
  
  - Columns of A needs to equal to rows of B -> R
  - Size of resulting matrix - P x Q
  - Total scalar multiplication - P x R x Q
  - If multiplying multiple matrix you need to do 2 at a time.
    Matrix has associativity property so you multiply any two at a time if they are compatible.
  - Depending on the order of multiplication number of scalar multiplication would vary, hence performance.


- **Best way to multiply matrices**  
  - How many ways of multiplication possible for n matrices
    ```
        (2*p)!
      ---------
      (p+1)! * p!
    
      where p = (n - 1)
    
      n = 3 -> 2
      n = 4 -> 5
      n = 5 -> 14 
    ```


#### Dynamic Programming
  If you want to apply to any problem you should be able to find out few things

  - Optimal substructures  
    We should be able to split the problem into smaller optimisation problem.

  - Recursive Equations


#### Matrix multiplication - Dynamic programing
- **Optimal Substructure**  
  Let's say we have to multiply n matrices
  A(i) (p(i-1) x p(i)) - where i is 1 to n, and p(i-1) x p(i) is dimension of A(i)
  
  Now if we divide the matrix at k' th position
  (A(i) x A(i+1) x ... x A(k)) + (A(k+1) x ... x A(j))  // i < k < j
      size = p(i-1) x p(k)     +    size = p(k-1) * p(j)
      
  Now to multiply these to the cost is - p(i-1) x p(k) x p(j)
  
  So we can conclude that there is substructure to this problem.

- **Recursive Equation**  
  m[i, j] -- minimum scalar multiplication required to multiple matrices A(i) to A(j)

  ```
            |---
            |  0 ; i = j
  m[i, j] = |
            |  min { m[i, k] + m[k+1, j] + (p(i) * p(k) * p(j))  // i <= k < j
            |---
  
  // k is split and split can be anywhere for possibilities are -> k = (j - i)
  ```

- **Overlapping sub-problems**  
  Recursion Tree
  ```
                           m[1,4]
      m[1,1] m[2,4]     m[1,2] m[3,4]       m[1,3] m[4,4]
        
  ```
