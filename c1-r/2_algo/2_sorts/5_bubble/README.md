### Bubble Sort
```
BubbleSort(int a[], n)
{
    int swapped, i, j;
    for (i = 0, i < n, i++)
    {
        swapped = 0;
        for (j = 0, j < n - i - 1; j++) // Shifting the highest element to the end
        {
            if (a[j] > a[j+1)
            {
                swap(a[j], a[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)  // Comparing each pair if in each pair if always left < right then it's already sorted
                           // in other word if there is no swap then it's sorted so we can end the program
            break;
    }
}
```

- **Analysis**  
  ```
  Worst case comparisons
  (n-1) + (n-2) + .... + 1
  (n-1) * (n-2) / 2
  O(n^2)
  
  Best Case
  O(n)
  
  In case of just (n-1) + (n-2) also where on (n-2) ther is no swaping
  then - O(n)
  ```
