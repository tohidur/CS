## Graphs

### Representation of Graphs
There are two popular representation of graphs
- Adjacency Matrix
  ```
  [a] --- [b]
   |       |
   |       |
  [c] --- [d]
 
        a   b   c   d 
        _   _   _   _
  a |   0   1   0   1
  b |   1   0   1   0
  c |   0   1   0   1
  d |   1   0   1   0
  
  If weighted graph then you can specify weigh instaed of 0/1
  Better for dense graph 
  // Dense Graph - O(E) = O(V^2)
  Space required = O(V^2)
  ```

- Linked List
  ```
   | a | -> [b | ] -> [d | \o]
   | b | -> [a | ] -> [c | \o]
   | c |
   | d |
  
  Better for sparse graph
  O(E) = O(V)
  
  Space required
  Undirected graph - V + 2E(for linked lists) O(V+2E)
  Directed graph - V + E
  
  S(G) = O(V + E)
  ```

### Introduction of BFS and DFS
Searching nodes in the Graph (It's not traversing because we may not reach
all nodes in the graph if it's disconnected.)
To search we use two terminology

- Visited - To visit to node.  
  We use an array to keep track of visited nodes with 0/1 values.
 
- Explore - To visit the node and also visit all it's adjacent nodes.
  - BFS - We use an Queue to keep track of unexplored nodes.
  - DFS - We use an Stack to keep track of unexplored nodes.

The space complexity - O(n) for array and nearly O(n) for queue/stack.


#### BFS
- **Algo**  
  ```c
  BFS(v)  // The search starts from vertex v
  // The graph 'G' and array visited[] are global;
  // visited[] is initialized to '0'
  {
    u = v;
    visited[v] = 1;

    repeat
    {
      for all vertices w adj to u do
      {
        if (visited[w] == 0)
        {
          add w to q;
          visited[w] = 1;
        }
      }
      If q is empty then return;
      Delete the next element, u from q;
    }
  }
  ```
- **Complexities**  
  - Space - O(V) (for visited array for for queue)
  - Time
    - Linked List Repr 
      - O(V) (for visited init) + O(2E) (for visiting linked lists)
      - O(V + E)
    - Adjacency Matrix Repr
      - O(V) for visited array init
      - O(V) for check visited array for V vertics - O(V^2)
      - O(V^2) + O(V) = O(V^2)
  
#### Breadth First Traversal using BFS
Traversal - To visited every node of every component of the entire graph.
Search - To visited reachable nodes of a graph.

- **Algo**  
```c
BFT(G, n)
{
  for i = 1 to n do
    visited[i] = 0;
  for i = 1 to n do
    if( visited[i] = 0 ) then BFS(i);
}
```
Complexity is same as BFS

#### DFS
- **Algo**  
  ```c
  DFS(v)
  {
    visited[v] = 1;
    for each vertex w adj to v do
    {
      if ( visited[w] == 0) then
        DFS(w);
    }
  }
  
  // S(n) = O(V)(for visited init) + O(V) (for recursion stack)
  // T(n) = O(V + E) // for linked list
  // T(n) = O(V^2) // for adjacency matrix
  ```


### Topological Sort
A directed acyclic graph
We need to find out topological order when all the dependencies are met

- **Algo - 1**  
  - Step 1  
    Identify vertices that have no incoming edge.
    - O(V) for one vertex to find this out.
    - O(V ^ 2) for V vertices.
  
  - Step 2
    Delete this vertex of in degree 0 and all it's outgoing
    edges from the graph. Place it in the output
    - O(E)
    
  - Repeat Step 1 and Step 2 until the graph is empty

  - Overall complexity - O(V^2 + E)
 
- **Algo - 2**
  ```
  [v1] -> [v3] -> [v4]
  [v2] -> [v1]
  [v3] -> [v6]
  [v4] -> [v3] -> [v6]
  [v5] -> [v1]
  [v6]
  ```
  - We are going to maintain a separate array. To know the in-degree of vertices.
    ```
    [ 2 | 0 | 2 | 1 | 0 | 2 ]
      1   2   3   4   5   6
    ```
    - Initialize time = O(V + E)
    - To find out vertices with degree 0 - O(V) for v vertices - O(V^2)
    - Once one vertex is deleted we can mark that array cell to -> -1
    - To reduce this time complexity when we are reducing in-degree if
      It's getting 0 then we can add that to a queue.
      So, Instead of searching for 0 in-degree vertex in array we can
      just pop an element from the queue - O(1) time.  
      So, time complexity is reduced to O(V) from O(V^2).
      
  - Time complexity = O(V + E) instead of O(V ^ 2 + E) in algo-1.
