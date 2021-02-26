### Merge-Sort

#### Algo
- **Merge Algo**  
  ```
  Merge(A, p, q, r)
  {
    n1 = q - p + 1
    n2 = r - q
  
    let L[1 ... n1+1] and R[1 to n2 + 1] be new always
  
    for (i = 1 to n1)
        L[i] = A[p+i-1]
    for (i = 1 to n2)
        R[j] = A[q+j]
  
    L[n1+1] = infinity
    R[n2+1] = infinity
  
    i = 1, j = 1
    for (k = p to r)
        if (L[i] <= R[j])
            A[k] = L[i]
            i = i + 1
        else
            A[k] = R[j]
            j = j + 1
  }
  
  // Time complexity = O(n + m)
  // Space complexity = O(n) - Out of place procedure
  ```
 
- **Merge-Sort Algo**  
  ```
  MergeSort(A, p, r)
  {
    if p < r
        q = floor((p+r)/2)
        MergeSort(A, p, q)
        MergeSort(A, q+1, r)
        Merge(A, p, q, r)
  }
  // O(n log n)
  ```
