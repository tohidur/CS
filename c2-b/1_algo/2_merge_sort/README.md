### Merge
It's a process of combining two sorted listed into a single sorted list.
Complexity is Theta(m+n) - if m+n then it means some merging had happened.

- **Algo**
  ```
  Algorighm Merge(A, B, m, n) {
    i = 1; j = 1; k = 1;

    while (i <= m && j <= n) {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    for (; i<=m ; i++) {
        C[k++] = a[i];
    }
    for (; j<=n ; j++) {
        C[k++] = a[j];
  }
  ```

- **Merging if there are more than 2 lists**
  - Same process - will be called as 4-way merging.

  - Mostly 2-way merging is followed.
    - If create multiple groups of 2 lists and merge them
    - And go on till you have merged all list
    - This can be done using other pattern also
 

 - **2-way merge sort**
   How it's different from merge sort is.
   - 2-way merge sort is a iterative process.
   - Merge sort is a recursive procedure/algo.


- **Merge Sort**
  - Recursive - Divide and Conquor
  - Algo
    ```
    Algo MergeSort(low, high) {
        if (l < h) {
            mid = l+h/2;
            MergeSort(l, mid);
            MergeSort(h, mid);
            Merge(l, mid, h);
        }
    }
    ```
  - Complexity
    `Theta(n log n)`

