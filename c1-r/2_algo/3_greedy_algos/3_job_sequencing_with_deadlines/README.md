### Job sequencing with deadlines

- **Problem**  
  Given n jogs with their profit and deadline.
  How can you schedule those jobs so that you get most profit?

- Take job with most profit and delay it as far as possible

- **Time complexity**  
  - To sort by profit - O(n log n)

  - Start from the dead line and keep searching for a vacant location
    No there are n jobs and I might have to search n elements for a slot
    So - O(n^2)

  - Total
    O(n log n ) + O(n^2)
    = O(n^2)