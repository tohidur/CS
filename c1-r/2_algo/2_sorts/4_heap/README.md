### Heap
- Heap can be implemented as binary tree, 3-ary tree, n-ary tree..

#### Max Heapify
Convert and array to max heap
```
MaxHeapify(A, i)
{
    l = 2i;
    r = 2i + 1;

    if (l <= A.heap_size and A[l] > A[i])
        largest = l;
    else
        largest = i;

    if (r <= A.heap_size and A[r] > A[largest])
        largest = r;

    if largest != i
        swap(A, i, largest)
        MaxHeapify(A, largest);
}

// Time - O(log n)
// Space - O(log n)
```

#### Build Max-Heap
```
BuildMaxHeap(A)
{
    A.heap_size = A.length
    for (i = floor(A.length / 2) down to 1)
        MaxHeapify(A, i)
}
```

- **Analysis**  
  - If height h then - `ceil(n / 2 ^ (h+1)` is number of node present in h height level - at most
  - Total time to build heap
    ```
    Sigma(h = 0 to n) [ ceil(n/2^(h+1)) * O(h) ]
    Sigma(h = 0 to n) [ ceil(n/(2^h * 2)) * c*h ]
    O( (c*n/2) * Sigma(h = 0 to infinity) [ h/2^h ]) )   // We can put O() as 0 to infinit is greater than 0 to n
    // In coreman book - Sigma(h = 0 to infinity) [ h/2^h ]) --> 2
    O( (c*n/2) * 2 )
    O(cn)
    O(n)
    
    To complexity of building a heap is - O(n)
    ```

#### Heap-Sort
```
HeapSort(A)
{
    BuildMaxHeap(A)
    for (i = A.length down to 2)
        swap(A, 1, A[i])
        A.heap_size = A.heap_size - 1
        MaxHepify(A, 1)
}

// O((n/2) log n)  - At least nearly
// O(n log n)
```
