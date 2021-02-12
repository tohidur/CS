### Quick Sort 

#### Idea
- All entries on LHS are shorter.
- All entries on RHS are larger.
- This is devide and conquor procedure
- It usages **partition procedure**

#### Partitioning Procedure
- Point l at first and h at the end of the list.
- pivot is at l
- Increment i till you find an element greater than pivot
- Increment j till you find an elment smaller than or equal to pivot
- Swap i and j
- Repeat
- When j is greater than i
  - Don't swap
  - j is the position of pivot
  - Swap l/pivot with j

#### Quick sort method/Algo
```
Partition(l, h)
{
    pivot = l;
    i = l;
    j = h;
    while (i < j) {
        do {
            i++;
        } while(A[i] > pivot);
        do {
            j++;
        } while(A[j] <= pivot);

        if (i < j)
            swap((A[i], A[j]);
    }
    swap(A[i], A[j]);
    return j
}

QuickSort(l, h)
{
    if (l < h) {
        j = Partition(l, h);
        QS(l, j);
        QS(j + 1, h);
    }
}
```

#### Analysis


