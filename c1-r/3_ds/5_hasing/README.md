## Hashing
The most dominating operations on any data structures is Search.  
Time we get for searching are..  
- Unsorted Array - O(n)
- Sorted Array - O(log n)
- Linked List - O(n)
- Binary Tree - O(n)
- BST - O(n)
- Balanced BST - O(log n)
- Priority queues (min/max heap) - O(n)

So the lowest is - O(log n)  
We have two DS with o(1) searching time complexity.  
- Direct Address Table (DAT)
  - Use array indexing to store keys.  
    Beneficial if number of keys is same as number of array cells.

### Introduction to Hashing
Even though the number of possible keys that have to inserted a DS are very
large - (universal set u). But very less keys among u will be present in our DS
at any time.

Here instead of declaring a DS of size u we are going to define one with the
size that we are going to actually use.  
And then we can try to map keys in u using hash function.  
```
hash_function(0 - 999) -> (0-9)

Here - mod 10 can be hash function.
```

- **Collisions problems**  
  - Better hash functions  
    It's can decrease number of collisions but can't be eradicated.
  
  - Chaining  
    Maintain a linked list if there is a collision.

  - Open Addressing  
    Re-compute the hash value with minor modifications and you might get an
    empty slot. Keep on doing this until you probe all the values.  

    Probing means searching for an empty space to insert values.  
    There are 3 ways of probing with open addressing.  
    - Linear probing
    - Quadratic probing
    - Double hashing
    
    We can utilize the space better with this open addressing compare to chaining.
    And when required we can increase the size of the hash table.

  Chaining is better if you want to - Insert, Delete and Search
  Open addressing is better if if you just want to - Insert and Search. 

### Chaining
```
                [ ]
T[h(k)] ---->   [ ] -> [ | ] -> [ | ]
                [ ] 
```
- Insertion - Insert in the beginning of list - O(1)
- Searching  
  - Worst case - O(n) time.  
    If all elements are mapped to 1 list.
  
  - But if you use uniform hash function then  
    each slot might get `n/m` elements.
    Average Search - `θ(1 + n/m)` time.  
    
    This n/m is called load factor - α. So, θ(1 + α).  
    Now if n = k*m (k is some constant).  
    α = n/m --> α = km/m --> α = k. A constant.  
    Then you can say constant time is taken to Search elements.  

- Average deletion will also be of constant similar to search.

- The advantage of Chaining of deletion. It will take on Average constant time.  
  With open-addressing deleting one element leads to re-arranging other elements.  

- Disadvantage of this method is Pointers. Extra space.
