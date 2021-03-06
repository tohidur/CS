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

### Open Addressing
It's also called Closed Hashing.  
Doesn't store elements outside hash table. All elements are stored inside the
table itself.

Load factor α = n/m.  
n -> number of elements stored.  
m -> total size of hash table.  

For open addressing, 0 <= α <= 1.  
Unlike chaining where load factor can be anything.  

For collision second time probing is required. With minor modification to hash
function. Here in second time we will use collision number with the key to
generate new key.

```
h: U -> {0, 1, ... m-1}
h: (U X {0, 1, 2, 3, ... m-1}) -> {0, 1, 2, ... m-1}  // Probe sequence
```

Probe Sequence:
To insert we will follow a sequence of examinations. If I find any empty
cell in this sequence then I am going to insert there. If not then declare
that entire table is full and I will not be able to insert it.

Worst time to search an element - O(m)

Flow
- Inserting - k1 key
  - First collision and key is not k1 use collision number and try re-probing
  - Keep on doing it until you find an empty space.

- Searching
  - Same as Inserting
  - Keep on doing it until you find key - k1
  - Or you get a NULL entry. That means the key is not present in the table.

- Deleting
  - If you delete and make the entry as NULL.
  - In case of collision you will find null and think that key is not present.
    Even though it might have present in the next probing.
  - So, one solution is to replace it with some special char instead of NULL in
    case of deletion.
  - Now when searching if you find that special char you will keep on finding
    the key using collision number.
  - In case of Insertion if you find that special key you insert there.

- Problem with this special char deletion
  - Let's say most of the entry in hash table is deleted except k1.
  - There are bunch of collisions happened before probing k1.
  - So now even though most the table entries are empty you have to go
    through all the collisions before you can find k1.
  - That is why it's better to use Chaining if deletion is involved.

- Advantage
  - We are not wasting space. And in case table gets full we can increase
    table size. And bigger table size means less collisions.


#### Linear Probing
It has two hash functions.  

Hashing function = `h: U -> {0, 1, ... m-1}`  
Probing Hash function = `h'(k, i) = (h(k) + i) mod m` , i - is collision number.

It's linear because if we get a collision on a position say - `a`.
Then next element would be `a+1`, `a+2` and so on.

- **How many prob sequences?**  
  It depends on from where we are starting to probe.  
  - 0 - {0, 1, 2, ... m-1}
  - 1 - {1, 2, 3, ..., m-1, 0}
  - 2 - {2, 3, 4, ..., m-1, 0, 1}
  
  So there are m different probe sequence possible

- **Problems**  
  - **Secondary Clustering**  
    If two have same initial probe numbers then they follow the same
    probe sequence.
  
  - **Primary Clustering**   
    There would be a build up of sequence, a continuous run of probed elements.  
    So, with Linear probing many elements will fall together in a continuous run
    then there will be some gap and then again a continuous run of some elements
    in the hash table.
    
    In uniform hashing probability of a slot is 1/m.  
    But here the probability of the slot after continuous run is (i+1)/m.
    Considering i is the number of elements in that continuous run.
    So, it's much higher than 1/m.

- Worst T(n) -> O(n)
- On Average T(n) -> Constant. // Approx - O(2.5)


#### Quadratic Probing
Probing hash function - `h'(k, i) = (h(k) + c1 * i + c2 * i^2) mod m`  

So, the next probe position would not be linear it would be quadratic.  

But we need to careful here when choosing c1 and c2 value so that.  
m successive probing should cover all the slots on hash table so that we
can declare the there is no empty space left and we can't probe that element.

It's difficult to come up with proper c1 and c2 and m values. So people
doesn't usually go with this quadratic probing.

It solves Primary Clustering problem but no Secondary clustering problem.  
Number of probe sequence are - m.


#### Double Hashing
`h'(k) = (h1(k) + i * h2(k)) mod m`

Probe sequence possible - m ^ 2.  
h1(k) would give you m sequence and h2(k) would give you m sequence.

Now you need to be sure that if you going to probe m times then
all m slots needs to be covered.  

You can do that if make sure that h2(k) and m are relatively prime.  
There are two ways you can do it.
- Make sure h2(k) will always give odd number and m = 2^k.
- m would always be a prime number and h2(k) value would be < m
