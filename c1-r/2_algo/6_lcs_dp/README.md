### LCS - Longest common subsequence

There is a difference between subsequence and substring. Substring should be contiguous and in increasing order.
Subsequence should be in increase order - but they need not be contiguous.

- How many subsequences possible?  
  Each char can be present or not present in each subsequence - 2^n subsequences.

- Need to find longest common subsequence in two strings - Application - DNA match

- Exhaustive search approach  
  ```
  Find all subsequences of 1st string - O(2^m)
  For each subseqence
    Find common subsequence in 2nd string - O(n * 2^m)
  Find longest - O(2^m)
  
  T(n) = O(n * 2^m)
  ```

- **Dynamic Problem Approach**  
  To be able to do it needs to fulfil 2 criteria

  - Optimal substructure  
    
    Let's say there are two strings
    A = x1, x2, .... xn
    B = y1, y2, .... ym
    
    The purpose here is to take a decision and reduce the problem in sub-problems.  
    If xn == ym then we can find subsequence between x1 - x(n-1) and y1 - y(m-1)  
    if not equal then we can ...  
        either find between - (x1 - x(n-1)) and (y1 - y(m))  
        or find between - (x1 - x(n)) and (y1 - y(m-1))  

  - Recursive equation  
    i = x1, x2, ...., xi   
    j = y1, y2, ...., yj  

    ```
              | 0,                          i=0 or j=0  
    C[i, j] = | 1 + c[i-1, j-1]             i,j > 0 and xi == yj  
              | max(c[i-1, j], c[i, j-1])   i,j > 0 and xi != yj  
    ```


  - Recursion Tree and unique sub-problems  
    Let's take worst case. When there are no match.  
    X = AAA  
    Y = BBB  
    ```
                                    C[3,3]
                         C[2,3]
                  C[1,3]        C[2,2]
            C[0,3]      C[1,2]
                  C[0,1]      C[1,1]
                        C[0,1]      C[1, 0]
    ```
                        
    What will be depth of the tree?
    ```
    C[n,m]
      |
    C[n-1,m] 
      |
    C[n-1,m-1]
      |
    C[0,1] or C[1,0]
    ```
    
    So depth will be O(n+m).  
    And even if the tree is half full - the number of nodes = O(2 ^ (n+m)).  
    So time complexity = O(2 ^ (n+m)).  
    
    But Since there are overlapping problems we can apply dynamic problem?  
    Now the question is how many unique sub-problems.  
  
  - Unique Sub-Problems  
    Would be - m * n.  
    Lets say it's 4 x 4.  
    ```
        0   1   2   3
        --  --  --  --
    0|  00  01  02  03
    1|  10  11  12  13
    2|  20  21  22  23
    3|  30  31  32  33
    ```
    - Every element is depended on  
      - Upper left corner/diagonal element
      - Left element
      - Upper element
    So based on this you have to either compute row-wise or column-wise.
    
  - Time and Space Complexity   
    O(m * n) - (Way less than O (2 ^ (n+m)))


### Algo
```
LCS(X,Y)
{
    m = X.length;
    n = Y.length;

    let C[1....m, 1.....n] be a new table
    for i=1 to m
        C[i,0] = 0
    for j=0 to n
        C[0,j] = 0

    for i = 1 to m
        for j = 1 to n
            if xi == yj
                c[i,j] = c[i-1, j-1] + 1
            else
                c[i,j] = max(c[i-1,j], c[i,j-1])
    return c
}
```
