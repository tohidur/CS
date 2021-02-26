### Bucket Sort

- **Problem**  
  Sort a large number of floating point numbers which are in the range 0.0 to 1.0
  and uniformly distributed across the range?
  
  0.35, 0.12, 0.43, 0.15, 0.04, 0.50, 0.132
  ```
  0 -> 0.04
  1 -> 0.12 -> 0.132 -> 0.15
  2
  3 -> 0.35
  4 -> 0.43
  5 -> 0.50
  
  k buckets. and as uniformly distributed so (n/k) elements per bucket
  so O((n/k) * n)
  O(n^2)
 ``` 