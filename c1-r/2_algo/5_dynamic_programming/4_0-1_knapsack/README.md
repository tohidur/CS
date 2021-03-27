### 0/1 Knapsack

Greedy method works well with fraction knapsack but not with 0/1 knapsack.

```
Capacity = w
            A       B
Profit      2       w
Weight      1       w

p/w         2       1

1st -> A -> C = w-1 -> P = 2
We don't have any capacity for B now - inefficient
```

#### Dynamic programming solution  
How many choices for n element - 2 ^ n.
Either element will be included or not.

- **Equation**  
KS(i, w) - whether to consider ith element and capacity of knapsack is w.
Let's say ith element have pi profit and wi weight.
```
            |-
            | max( (pi + K(i-1, w - wi)) , KS(i-1, w) )
            |      if element included    not included
            | 
KS(i, w) =  | 0     ; i = 0 or w = 0    // Recursion base condition
            |
            | K(i-1, w)     ; wi > w  // if weight is greater than capacity
            |-
```


- **Unique sub-problems**  
  Let's assume there are 10 elements and every element is of weight 1. And capacity is 10
  ```
                    KS(10,10)
         KS(9,9)                KS(9,10)
   KS(8,8)     KS(8,9)    KS(8,9)      KS(8,10)
   ....
   K(0,0)
  ```
  
  - The depth of the tree will be - O(n).  Then O(2 ^ n) nodes in the tree.
  - T(n) = O(2 ^ n)  

  How many unique sub-problems? -> n * w.  
  So time complexity of Dynamic problem -> O(n * w)  
 
#### Bottom-Up dynamic programming approach  
```
C = 6
    1   2   3
    _   _   _
W|  1   2   4
P|  10  12  28
```

```
    0   1   2   3   4   5   6
    _   _   _   _   _   _   _
0|  0   0   0   0   0   0   0
1|  0   10  10  10  10  10  10
2|  0   10  12  22  22  22  22
3|  0   10  12  22  28  38  40
```
- KS(1, 1) -> p1 + KS(0, 0) or KS(0,1)  
  To calculate we need cells above it, left upper diagonal and left.
  To we can go - **row wise**.  
  Or we can go - **column wise**.  

- **Note**  
  T(n) - O(n * w).  
  It looks like linear but it's not true when n is very large - 2 ^ n.  
  So now it's O(n * 2 ^ n).  
  Then this is worst than exhaustive search - O(2 ^ n).   
  **It depends on W - Check NP Complete / NP Hard**  


#### Algo
```
input: {w1, w2, w3, ..., wn}, C, {p1, p2, p3, ..., pn}
output: T[n, C]

for i = 0 to C do
    T[0,i] = 0

for i = i to n
{
    T[i,0] = 0
    for (j = 1 to C) do
        if (wi <= j) and T[i-1, j-wi] + pi > T[i-1, j]
        then T[i,j] = T[i-1, j-wi] + pi
        else T[i,j] = T[i-1, j]
}
```