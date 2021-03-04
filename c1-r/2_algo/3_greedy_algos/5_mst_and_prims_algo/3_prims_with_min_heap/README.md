### Prims - With Min Heap

```
MST_Prims(G, cost, r)
{
    // r = root

    for each vertex u ∈ G.vertices  // O(n)
    {
        u.key = ∞  // key = cost
        u.π = NIL // π = parent
    }
    r.key = 0  // root key is 0
    Q = G.vertices // Build min heap using key. As all of them are infinity the order doesn't matter
                   // O(n)
    while (Q != ∅)  // while Q is not empty
                    // O(n)
    {
        u = ExtractMin(Q)  // O(log n)
        for each vertex 'v' adjancent to 'u'  // O(n)
        {
            if v ∈ Q and cost(u,v) < v.key
                v.π = u
                v.key = w(u,v)  // Decrease key on Heap
                                // O(log n)
        }
    }
}

// so it for decease key seems = O(n^2 log n)
// but in aggregate analysis - O(E log n)

So = O(n log n) + O(E log n) + O(n)
   = O(E log n)
   = O(E log V)

```

- **Using Fibonaci heap**  
  With this we can use this decrease key with constant time.  
  So = O(v log v + E)

- **Which is better**  
  - O(V^2) - Without heap
  - O(E log V) - With min heap
  
  It depends on the graph.
  - If dense graph where `E = O(V^2)` (Almost complete)  
    So without heap is better

  - If sparse graph where `E = O(V)`  
    So with min heap is better
