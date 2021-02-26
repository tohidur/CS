### Selection Sort
```
void SelectionSort(int a[], int n)
{
    int i, j, temp, min;
    for (i=0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Complexity
(n - 1) + (n - 2) + ... + 1
O(n^2)
```
