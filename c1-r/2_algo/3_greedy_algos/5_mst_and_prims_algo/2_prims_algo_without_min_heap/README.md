### Prims algo - Without Min Heap

```
Prims(E, cost, n, t)
// E is set of edges
// Cost is (nXn) adjancency matrix
// MST is computed and stored in array t[1:n-1, 1:2]
{
    let (k,l) be an edge of min cost in E;  // O(E)
    mincost = cost[k, l];
    t[1,1] = k, t[1, 2] = l;

    for (i = 1 to n)  // O(N)
        if (cost[i, l] < cost[i, k]) then near[i] = l;
        else near[i] = k;
    near[k] = near[l] = 0;
    for (i = 2 to n - 1)  // O(n-2)
    {
        let j be an index such that near[j] != 0 and cost[j, near[j]] is minimum  // O(n)
        t[i,1] = j; t[i,2] = near[j];
        mincost = mincost + cost[j, near[j]];
        near[j] = 0;
        for k = 1 to n do       // O(n)
            if((near[k] != 0 and (cost[k, near[k]] > cost[k,j]))
                then near[k] = j
        }
    }
}

T(n) = O(n^2)
```
