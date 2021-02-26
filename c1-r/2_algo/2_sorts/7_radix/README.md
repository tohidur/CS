### Radix Sort
```
RadixSort(A, d)  // d -> maximum number of digits 
{
    // Each key in A[1....n] is a d-digit integer
    // Digits are numbered 1 to d from right to left

    for i = 1 to d do
        use a sable sortig algo to sort a on digit i
}
```

- **Points**  
  - As range here is known the best is to go with counting sort
    Assuming decimal numbers range is 0 - 9 in every digit
  
  - The intuition behind is, after first pass 1 digit numbers will be in it's correct position.
    And after 2nd pass 2 digit numbers would be in it's correct position
    
  - How many passes are required?
    If largest number is l and number system base is b
    then passes are - `log l base b`
    And say we are using counting sort - O(n+b)
    
    `T(n) = O(log l base b) * O(n+b)`
    Say l is really large - n^k
    so T(n) = O(k log n base b) * O(n+b)
    as k is constant
    `T(n) = O(n * log n base b)`
    
    Space complexity - O(b) // for counting sort
