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

#### Bottom-Up approach  
```
A(1, 4)
Subproblems
(1,1), (2, 2), (3, 3), (4, 4)       4 - of size 1
(1,2), (2, 3), (3, 4)               3 - of size 2
(1,3), (2, 4)                       2 - of size 3
(1, 4)                              1 - of size 1

So, total - (4 + 3 + 2 + 1)

if A(1..n) - n(n+1)/2 subproblems - O(n^2)
```

- **Algo**  
```
If A1(p0 x p1), A2(p1 x p2), A3(p2 x p3), A4(p3 x p4)
then p would be an array - [p0, p1, p2, p3, p4]


Matix_Chain(p) {
    n = p.length - 1;
    let m[1...n, 1...n] and s[1...n-1, 2.....n] be new tables
    for i = 1 to n
        m[i,i] = 0

    for l = 2 to n      // l is the chain length
        for i = 1 to n-l+1
            j = i + l - 1
            m[i, j] = infinity
            for k = i to j - 1
                q = m[i, j] + m[k+1, j] + p(i-1)
                if q < m[i, j]
                    m[i, j] = q  // update new min cost value on table
                    s[i, j] = k  // update the split point
    
    return m and s
}

Uniqueue subproblems - O(n^2)
Entries of each subproblem to process - O(n)

T(n) = O(n^3)
Space = O(n^2)  // To store subproblem results on table
```

#### Top-Down approach - Memoization
- **Algo**  
```
Memoized_Matrix_Chain(p)
{
    n = p.length - 1
    let m[1...n, 1....n] be a new table
    for i = 1 to n
        for j = 1 to n
            m[i,j] = infinity

    return Lookup_Chain(m, p, 1, n)
}

Lookup_Chain(m, p, i, j)
{
    if m[i, j] < infinity
        return m[i, j]

    if i == j
        m[i, j] = 0
    else for k = i to j - 1
        q = Lookup_Chain(m, p, i, k)
                + Lookup_Chain(m, p, k+1, j)
                + p(i-1) * p(k) * p(j)
        if q < m[i,j]
            m[i, j] = q

    return m[i, j]
}

T(n) = (n^3)
S(n) = O(n^2) + O(n) = O(n^2)
```
