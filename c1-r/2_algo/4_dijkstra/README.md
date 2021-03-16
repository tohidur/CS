### Single Source Shortest part

Minimum spanning tree and shortest path are not same thing
```
       2
  * -------- *
  |          |
1 |          | 1
  |          |
  * -------- *
        1

Minimum spanning tree cost - 3
Shortest path - 2
```

#### Dijkstra
Weighted, directed graph

- Depends on Relaxing edge mechanism
```
     [s]
     |  \
  10 |   \ 20
     |    \
    [v]---[u]
        5

d(v) = 10
d(u) = 20

Relax edge (v, u) if d(u) > d(v) + (vu)
```

- Dijkstra is not applicable if there is negative edge

- **Process**  
  1. At beginning path weight to source (a) is 0 and all other is infinity
  2. Select minimum of all - At the beginning it would be source node (a)
  3. Relax outgoing edges from a - say (b=10 and c=5)
  4. Repeat 2, 3. In this process don't select the nodes which are already selected


- **Algo**  
```
DIJKSTRA(G, w, s)
{
    Initialise_single_source(G, s)  // O(V)
    
    S = ∅   // captial S to denote set. Already explored vertices

    Q = G.V  // Build heap with graph vertices
             // O(V)

    while (Q != ∅)
        u = Extract_Min(Q)  // O(log V)
        s = S U {u} // O(1)
        for each verted v ∈ G Adj[u]  // Loop will go at worst case number of Edges - E
            Relax(u, v, w)  // O (log V)
}

// O(V) + O(V) + V * O(log V) + E * O(log V)
// O(E log V)
```
