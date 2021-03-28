### Travelling Salesman Problem

In a graph visiting every node exactly once and then coming back to the source.
This cycle is also know as hamiltonian circuit/cycle.
Along with that TSP also try to find-out the minimum cost.

- Exhaustive Search  
  Source and destination is same. Then there is all possible combination of (n-1) nodes.  
  T(n) = O( (n-1)! )  
  So this method will help. Only method can help is Dynamic programming.  


#### Dynamic programming
```
Let's say T(i, S)  - From i I have to start all the vertices in set S and then go back to 1/source vertex.

            | for j ∈ S - min( (i, j) + T(j, S - {j}) )     ; S != ∅
            |
T(i, S) =   | (i, 1)   ; s == ∅
            |
```

```
                    T(1, {2, 3, 4})
        T(2, {3,4})     T(3, {2,3})     T(4, {2,3})
    T(3,{4}) T(4,{3}) T(2,{3}) T(3,{2}) ...
    ...
```

- **Number of sub-problems**  
  - At every level you have compare distance from (n-1) source to a set of Vertices
  - At each level you will reduce the number of elements on set by one by creating (n-i) C (n-i-1) combination.
  ```
  (n-1) + (n-1) * (n-2) C (n-3) + (n-1) * (n-3) C (n-4) + ... + (n-1) * nC2 C 0
 
         n-2
  (n-1) * Σ  (n-2) C k  == Binomal series == (n-1) * ( 2 ^ (n-2) )
         k=0
  
  Number of sub-problems - n-1 * 2^(n-2)
  At each sub-problem you have to figure out the minimum - O(n)
  
  T(n) = O(n) * O(n * 2^n))
       = O(n^2 * 2^n)
  ```
 
  Even dynamic programming is not much of help here.  
  But it will reduce the problem from n!  to  O(n2 * 2^n)
