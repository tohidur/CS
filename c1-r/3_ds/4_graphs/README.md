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
