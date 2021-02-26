### Quick Sort
- For smaller input it's better than Merge Sort
- It follows divide and conquer
- It depends on **Partitioning**

#### Partitioning
Find a position for aa element where all elements on LHS would be less
and all elements on RHS would be greater than that element.

```
Partition(A, p, r)
{
    x = A[r]
    i = p - 1
    for (j = p to r -1)
        if (A[j] <= x)
            i = i + 1
            swap(A, i , j)
    swap(A, i+1, r)
    return i + 1 
}
```

#### QuickSort Algo
```
QuickSort(A, p, r)
{
    if (p < r)
        q = Partition(A, p, r)
        QuickSort(A, p, q - 1)
        QuickSort(A, q + 1, r)
}
```

#### Points
- Depending on what position is returned by Partition the sizes of sub-problems will vary.

- So if input is in asc order or desc order then partition will happen on on first/last element.
  So it's no evenly distributing sub problems.
  T(n) = O(n) + T(n-1)
  O(n^2)
  
  Best case - O(n log n)

- Let's assume the split is 1:9
  ```
             n                      - cn
          /     \
        n/10   9n/10                - cn
        /  \        \
     n/100 9n/100   81n/100         - cn
      /                 \
    ...                 729n/1000   - cn (left tree is going to stop faster)
                            \
                            ...     - < cn (as there is no work on left side, it's less than cn work)
  
  How many levels?
  n - n/(10/9) - n/(10/9)^2 - ... - 1
  log n base 10/9
  nearly as Theta(log n base 2) - We can assume
  And every level work done is - n
  So T(n) - Theta(n log n)
  
  So, even if the split is 1:9 we might get the best case time complexity
  ```

- Let's say alternatively on ever level of the tree we are getting best case and worst case
  ```
           n                    - cn
        /    \
       0    (n - 1)             - cn
             /    \
          (n-2)/2  (n-2)/2      - cn
  
  T(n) = cn + cn + 2T((n-2)/2) 
       = 2cn + 2T((n-2)/2)
       <= O(n) + 2T(n/2)
       ~= Theta(n log n)  by masters theorem
  
  So even if it's alternating we are getting best case complexity
  ```
