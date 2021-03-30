### All pair shortest path - Floyd Warshall

Find-out shortest path from all nodes, not only from a single node.
<br>
It's similar to apply Single source shortest path to every node - But it's slow.
- For one node shortest path - O(E log V)
- So, for every node - O(VE log V) -> O(V^3 log V)
- Also, it can't be applied on negative edges.  
- Dijkstra is a greedy algorithm - Dynamic programming would be better.  
<br>
With bellman ford algo negative edges are possible.  
- For one node - O(VE)
- For V nodes - O(V^2 * E)
- So, O(V^4)


#### Dynamic Programming  
- **Optimal Sub-Structure**  
  - V = {1, 2, 3, ..., n}
  - i, j ∈ V
  - d(i,j)k = Distance of shortest path from i to j by including only k vertices - {1, 2, ... k}
  
  ```
            | d(i,j)(k-1)   ; k > 0 // If shortest path doesn't include kth vertex then we can exelude it
            |
  d(i,j)k = | d(i,k)(k-1) + d(k,j)(k-1)  ; k > 0  // If kth vertex there in paty. Then we are splitting path in 2.
            |                                     // and both path will contain kth vertex now
            |
            | w(ij)     ; k == 0
  ```
  - It works on directed graph
  - It works with negative weight edges. But there should not be any negative weight cycle.

- **Example**  
  ```
       11
  [1] ------- [2]
   |  \6     /  |
  1|     \     |3
   |  /7    \  |
  [3] -------- [4]
         2
  
  // Weight metrics
       1    2   3   4
       _    _   _   _
  1 |  0    11  1   6
  2 |  11   0   7   3
  3 |  1    7   0   2
  4 |  6    3   2   0
  
  // D1 - Set of all pairs in case all path goes through 1st vertex
       1    2   3   4
       _    _   _   _
  1 |  0    11  1   6
  2 |  11   0   7*  3*
  3 |  1    7*  0   2*
  4 |  6    3   2   0
  
  (i, j) = min(w(i,j), w(i,1) + w(1,j))
  
  
  // D2 - compute by including 1 and 2 - {1, 2}. So just extend D1 matrix
        1    2   3   4
       _    _   _   _
  1 |  0    11  1   6
  2 |  11   0   7   3
  3 |  1    7   0   2
  4 |  6    3   2   0 

  (i, j) = min(wd1(i,j), wd1(i,2) + wd1(2,j)) 
  .....
  .....
  .....
  ```
 
 - **Number of sub-problems**  
   - For each matrix we are calculating values for each cell - n^2 cells. 
   - We are doing this for n times
   - For each cell it's a constant operation - `(i, j) = min(w(i,j), w(i,1) + w(1,j))`
   - O(n^3)
   - Space complexity - O(2 * n^2) - O(n^2). At a time 


#### Algo
```
FLOYD_WARSHALL(w)
{
    n = w.rows
    D0 = W
    for k = 1 to n
        let DK = (d(i,j)k) be a new nxn matrix
        for i = 1 to n
            for j = 1 to n
                d(i,j)k = min(d(i,j)(k-1), d(i,k)(k-1) + d(k,j)(k-1))
    return DN
}
```
