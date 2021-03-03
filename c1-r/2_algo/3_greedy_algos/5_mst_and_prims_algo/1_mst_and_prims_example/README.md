### MST and Prims algo example  
If weighted graph then we want to find out spanning tree with minimum weight/cost/distance.
So this is - O(n ^ (n-1)) problem. As one complete graph will have n ^ (n-2) spanning tree

To solve this we have two greedy method
- Prims
- Kruskal

#### Prims Algo
```
        [1]
       /   \28
   10 /     \
     /       [2]
    /    14 / \
   /       /   \16
  [6]    [7]    \
 25\  24/ |     [3]
    \  /  |18  /
     [5]  |   /12
      22\ |  /
         [ 4 ]
```

- Draw every node - (As our goal is to connect every node)
- Take edge with minimum weight and draw.
- Then on every step take minimum edge from discovered node to undiscovered node and draw.
```
        [1]
       /
   10 /
     /       [2]
    /    14 / \
   /       /   \16
  [6]    [7]    \
 25\            [3]
    \          /
     [5]      /12
      22\    /
         [ 4 ]
```

- To find out MST from matrix
  - Start with any row. Pick lowest column value of that row.
  - Now two rows are discovered (row of corresponding column you have picked)
  - Now from discovered try to reach column of undiscovered rows.
  - Circle out the identical element also to avoid duplication - (1, 4), (4, 1) are same - For undirected graph
