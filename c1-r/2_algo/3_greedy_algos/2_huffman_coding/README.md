### Huffman Coding
Used for compressing file
Let's assume in a entire file has 100 characters and there are of 4 distinct chars (a, b, c, d).
Now in order to encode 4 chars how many bits do we need?

- **Fixed size encoding**  
  In order to encode 4 chars we need log 4 bits or 2 bits
  - a - 00
  - b - 01
  - c - 10
  - d - 11
  Total bits = 100 * 2 = 200 bits to represent the entire file

- **Variable size encoding**  
  It's useful if distribution of chars are not even.
  So say occurrences of chars in file are
  - a - 50 times
  - b - 40 times
  - c - 5 times
  - d - 5 times
  
  So char have highest frequency represent it using the least number of bits
  - a - 0
  - b - 10
  - c - 110
  - d - 111
  
  To follow this format we need to follow - **Prefix course** 
  Which is if I am using a pattern to represent a char then that pattern should be a prefix of any other course.
  
  So, gain in terms of bits
  (50 * 1) + (40 * 2) + (5 * 3) + (5 * 3) = 160 bits to represent the entire file.


#### Huffman Algo
```
Huffman(c)
{
    n = |c|  // c - set of all characters
    make a min heap 'Q' with c  // O(n)

    for i = 1 to n - 1
        allocate a new node z
        z.left = x = ExtractMin(Q); // O(log n) // Smaller value always have to be on left
        z.right = y = ExtractMin(Q); // O(log n)
        z.freq = x.freq + y.freq;
        Insert(Q, z);  // Insert in min heap // O(log n)
    return ExtractMin(Q);
}
// Time complexity - O(n log n)
// Space complexity - lenght of the tree - O(n)
```

- **Visual Representation**  
  ```
  We have 6 modes
  a - 40, b - 30, c - 20, d - 5, e - 3, f - 2
  
         100
      0/     \1
    40(a)    60
          0/    \1
        30(b)   30
             0/    \1
            10      20(c)
         0/    \1
        5(d)    5
             0/   \1
           2(f)   3(e)
  a - 0
  b - 10
  c - 111
  d - 1100
  e - 11011
  f - 11010
  ```

- **How to get Huffman coding after constructing the tree**  
  - Take left child of every node as 0 and right child as 1 (or vice versa)

  - You will get bits pattern and bits required to represent a char from Huffman coding

  - Every chars will be at leaf node of the tree.

  - There is another way to calculate total bits required.

    - Multiple frequency of every char with length of of char node from root node in the tree

    - It is also called **Weighted external path length** in terms of tree terminology.

    - This question can be asked in another way
      - How can you build a tree so that I can decrease the weight of the external path length?
