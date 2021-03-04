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
