### Kruskal

In Prims we extend the tree by adding new node
Here, all the nodes are already there, we will add new next minimum edge connecting two nodes.
- So, there can be multiple forests which will then be connected to one tree at the end
- While adding edge look for loops. If there are loops then we can't add that edge.

- **Question 1**  
  Let 'G' be an undirected connected graph with distinct edge weights. Let max-e be the edge with
  maximum weight and min-e be the edge with minimum weight. Which of the following is false?
  
  a. Every minimum spanning tree of G must contain min-3
  b. If max-e is in a minimum spanning tree then it's removal must disconnect G
  c. No minimum spanning tree contains max-e
  d. G has unique minimum spanning tree
  
  - Ans: c

- **Question 2**  
  Let w be the minimum weight among all weights in an undirected connected graph.
  Let e be a specific edge of weight w. Which is false?

  a. There is a minimum spanning tree containing e
  b. If e is not in a minimum spanning tree T, then in the cycle form by adding e to T, all the edges
     have same weight.
  c. Every minimum spanning tree has an edge of weight w
  d. e is present in every minimum spanning tree
  
  - Ans: d

#### Kruskal Algo - With Disjoint set
```
MST_Kruskal(G, W)  // W - weight matrix
{
    A <- ∅  // Initally minimum spanning tree does not contain any edges
            // O(1)
    for each vertex v ∈ V  // O(V)
        create-set(v)  // Will create a disjoint set (tree)
                       // O(1)
    
    E' <- Sort the edges of G in non-decreasing order by weight W  // O (E log E)

    for each edge (u,v) ∈ E'  // O(E)
        if Find_set(u) != Find_Set(v)     |
            A <- A ∪ {(u.v)}              | O(1)
            union(u.v)                    |
}

T(n) = O(E log E)
     = O(E log V^2)
     = O(2 E log V)
     = O(E log V)

Space complexity = O(V)  // To create disjoint set
```

#### Disjoint set - Data Structure
This Data Structure maintains a collection s = {s1, s2, ... , sk} of pairwise disjoint dynamic sets.
i.e. if si and sj, i != j are two sets, then there is no element that is in both si and sj
```
si ∩ sj = ∅ , i != j
```

- **Operations on Disjoint sets**  
  - _Create Set(x)_  
    Representative. We chose an element to represent the set
  - _Union(x, y)_  
    - Unites the disjoint sets that contain x and y, say sx and sy, into a new set sx U sy.
  - _Find_Set(i)_  
    - Returns a pointer to the representative of the set containing x.

- **Linked-List implementation of Disjoint set**  
  - Each element there will be structure/object 
  - Structure will have 3 fields  
    - data
    - next field element pointer
    - index fields will point to index object/structure
  - There will be index object/structure with 2 fields
    - head - will point to first element
    - tail will point to last element
  - You can take any element as representative. Let's say 1st element

- **Time Complexities - Of disjoint set operations (LinkedList)**
  - _Create_Set_  
    - O(1) time
  
  - _Find_Set(x)_  
    - O(1)
    - x is structure/object - You can go to index object by index field
    - from index field first element is the representative
    - so constant time

  - _Union(x, y)_  
    - O(n)
    - You choose one of them to append to other one. It's better if you choose the smaller one.

#### Amortized analysis  of disjoint sets using Linked List representation
To add n elements we will create n different sets
and then perform union n-1 times to get 1 set with n different elements.

n create operations + (n-1) union operations - (2n - 1) operations.

n create operations - O(n)

Worst case kind of union - take bigger set to replace.
U(x2, x1) - cost 1
U(x3, x2) - cost 2
......
U(xn, x(n-1)) - cost n
---
n(n-1)/2 = O(n^2)

Total T(n) = O(n^2) + O(n) = O(n^2)
Amortized = O(n^2) / n = O(n)

#### Disjoint set - using forest
- A faster representation of disjoint sets by rooted tree
- Each node contains one member and each tree represents one set
- Each member points only to it's parent
- The root node of each tree contains the representative and is it's own parent

- Create set - O(1)
- Find set - O(d)
- Union - O(1)


- **Union by rank**   
  Let's try to improve the time of find set - O(d).  
  Always take smaller set and point to bigger set for Union

  If the follow this union rule then based one dept there is minimum number of nodes will get. Maximum can be anything.
  But minimum number of nodes required to have that much depth. See below.

  Dept | Minimum no of nodes in tree after union
  0    | 1
  1    | 2
  2    | 4
  3    | 8
  ........
  d    | 2^d
  
  You should at least have n node in order to make a tree of depth log n
  Or
  The maximum depth possible using n nodes is - log n
  
  So, worst case time for find is - O(d) -> O(log n)

- **Path Compression**  
  To reduce the height even more than - log n

  - Whenever we perform find(x), make every node visited in the pat point to the root.  
    Next time when we perform find, it takes constant time.
  
  - If we don't do find(x) there is no need to compress the path

- **Time complexity using Heuristic**  
  - Union - O(1)

  - Find Operation  
    - O(m log n) - using union by rank for a sequence of m distinct operation
    - O(n + f(1 + log n base (2+(f/n)))) - using path compression alone.  
      for a sequence of n create_set operations, and hence n-1 union operations followed by f find_set operations.

  - O(u + f * α(f + u, u)) using both union by rank and path compression for a sequence of u union and
    f find set operations
    α - is a very slowly growing function
      - Inverse Ackermann function
      - <= 4
      
    so α is a constant
    O(u + f) - Amortised for u union and f find set.
    
    So, for one operation - O(u + f) / (u + f) = O(1)

- **Kruskal's algorithm using Disjoint sets**  
  Given a connected, weighted undirected graph, find the Minimum spanning tree
 
  ```c
  MST_Kruskal(G, W)
  {
    A <- ∅  // O(1)
  
    for each vertex v in V   // O(V)
        create_set(v)
  
    E' - sort the edges of G in non-decreasing order by weight w  // Best sorting algo - O(E log E)
  
    for each edge (u, v) in E'
        if find_set(u) != find_set(v)
            A <- A U {(u, v)}
            union(u, v)
  }
  ``` 
  
  - Complexity  
    - Space - O(V) for create set
    - Time  
      - O(E log E)
      - O(E log V^2)
      - O(E log V)
      - So, O(E log E) or O(E log V)

- **Connected Components using Disjoint sets**  

  If can figure out connected components by traversing but if the graph is dynamic then connected
  disjoint set is useful, traversing fails here.

  Given a undirected graph G = (V, E) find the connected component in the Graph.  
  ```c
  connected_component(G)
  {
    for each vertex v in V  // O(V)
        create_set(v)
    for each edge (u,v) in E
        if find_set(u) != find_set(v)
            union(u, v)  // O(E) - amortised using disjoint set - O(1)
  }
  
  // T(n) = O(E)
  // S(n) = O(V)
  ```

  So at the end the number of connected components would be equal to the number of disjoint sets.
