### Graphs (simplified)
Collection of vertices and edges

_NOTE: This is simplified version of graph for the purpose of algo. Detail graph will be on Graph Theory_

- **Classification-1**
  - Simple graph  
    Between two vertices at-most one edge is present

  - Multi Graph  
    Multiple edges between two vertices. Or if there are loops

  - Null Graph  
    No edges, only vertices

  - Maximum no of edges can be present in a simple graph
    ```
    nC2 - n(n-1)/2

    // So in worst case
    E = O(n^2) // Or O(v^2)
    V = O(log E)
    ```

- **Classification-2**  
  - Weighted Graph
  - Unweighted Graph

- **Classification-3**  
  - Labeled graph
  - Unlabeled graph

- **Classification-4**  
  - Directed graph
  - Undirected graph

- **Spanning Tree**  
  Minimum number of edges to connect all the nodes/vertices.
  
  - Minimum number of edges required for n node graph is - n - 1
  - Spanning tree is a sub-graph of the given graph
  - How many such spanning tree possible?  
    If the graph is labeled and complete graph (Kn).  
    Spanning tree = `n ^ (n-2)`


#### Kirchhoff Theorem
How many spanning trees are possible if the graph is not complete (labeled graph)?

```
[1]        [2]
 | \     /  |
 |   \  /   |
 |    /\    |
 |  /    \  |
[3] ------ [4]
```

- Given a graph construct the Adjacency Matrix  
  If there is an edge put 1 else put 0
  ```
     1   2   3   4
     -   -   -   -
  1| 0   0   1   1
  2| 0   0   1   1
  3| 1   1   0   1
  4| 1   1   1   0
  ```

- Take the diagonal 0's and replace them with degree of the nodes  
  degree - number of edges which are incident on any nodes.
  ```
     1   2   3   4
     -   -   -   -
  1| 2   0   1   1
  2| 0   2   1   1
  3| 1   1   3   1
  4| 1   1   1   3
  ```

- Non diagonal 1's - replace them with -1  
    ```
     1   2   3   4
     -   -   -   -
  1| 2   0  -1  -1
  2| 0   2  -1  -1
  3|-1  -1   3  -1
  4|-1  -1  -1   3
  ```

- Non diagonal 0's - leave them as it is  

- Now to find out number of spanning trees - Find-out cofactor of **any** element  
  Cofactor of an element - leave row and column of that element and then find out determinant of the remaining matrix.
  
  Cofactor of 2 (1,2) = (2(9-1) + (-1)(-3-1) + (-1)(1+3)) = 8
  
  So there are 8 spanning trees

- **Notes**  
  - In a complete graph degree of each node would be - `n - 1`.
  - 