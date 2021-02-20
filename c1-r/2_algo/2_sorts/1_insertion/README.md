### Insertion Sort
#### Algo
```
InsertionSort(A) {
    for j = 2 to A.length  // First element is already sorted only one card
        key = A[j]
        // insert key into the sorted sequence
        i = j - 1;  // Start from the immidiate left element and go till the first of the list.
                    // Already sorted elements
        while (i > 0 && A[i] > key)
            A[i+1] = A[i]  // Keep shifting elements to right till you find right position for the key
            i = i - 1;
        A[i+1] = key
}
```

#### Analysis
Worst case is reverse sorted order
For n => (n-1) comparisons + (n-1) movements
T(n) = O(n^2)

Best case - Omega(n)

-**Improvements**  
- To find out a position you need to perform search on lhs
  - We can perform binary search - O(log n)
  - But you have move the records - that would take n time
  - To reduce the movements you can use - double linked list
  - But if you use linked list then you can't perform binary search
  - So anyway - searching and moving would take - O(n)
- Not possible to improve
