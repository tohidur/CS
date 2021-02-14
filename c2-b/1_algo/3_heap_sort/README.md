### Binary tree and Heap

- **Array representation of binary tree**
  ```
            A
          /   \
        B       C
      /  \     /  \
    D     E   F    G

    [A, B, C, D, E, F, G]
  ```
  How to get relationships?
  Formulas
  ```
  - If a node is at index - i
  - It's left child is at - 2*i
  - It's right child is at - 2*i+1
  - it's parents is at - int(i/2) - floor value
  ```

- **Full binary tree**
  Binary tree with maximum number of nodes

  If height of a binary tree is - `h`
  Then nodes will be `2 ^ (h+1) -1`

- **Complete binary tree**
  In array representation there are no empty values.

  In other words. A full binary tree upto height h-1.
  And last level nodes are filled from left to right

  i.e: Every full binary tree is also complete binary tree.

  - Always the height of a complete binary tree would be minimum that is
    `log n`

- **Heap**
  - Heap is a complete binary tree
  - Root will contain the largest value - `max heap`
  - Root will contain the smallest value - `min heap`

  - **Insert operatrion on a max heap**
    ```
    [50, 30, 20, 15, 10, 8, 16]
    
    We want to insert 60.
    ```

    - Insert it on the last space
    - Compare with parent and swap till the top root
    - Time - O(log n)

  - **Delete operation on max heap**
    - Will remove the root element
    - The last element will come to it's place
      - Among two children which is greater, swap it with that child
    - Adjust the elements

    - **Heap sort**
      - After deletion you have obtained an empty space at the end.
        If you store the deleted element in that empty space.
        Then you will end up sorting the elements in ascending order.
        As every time you will delete the max element from a max heap


- **Heap Sort**
  It has two steps
  1. For a given setup of elements create a heap
  2. Delete all the elements from the heap

  - **Complexity**
    - To create heap - `nlogn` (logn time for each element)
    - To delete heap - `nlogn`
    - So total - `2nlogn` -- `O(nlogn)`


- **Heapify**
  - In the abvoe step we have crated a heap by inserting values one by one in
    the heap.

  - Here in heapify we will start from last element and turn it to a heap.
  - Time complexity of heapify is O(n). (Better than previous step O(nlogn))


- **Priorigy Queue**
  - smaller - higher priority - min heap
  - bigger - higher priority - max heap
  
  - How to insert and delete?
    - Using array it will take O(n) - you have to shift each element
    - Heap is better method.
      - logn time for insertion
      - logn time for deletion

  Heap is best data structure for creating priority queue


