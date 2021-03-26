### Multi Stage graph

There will be nodes in different stages. Every stage will have some set of nodes.
There will be no edges between nodes of one set. And there will be edges from nodes of one stage to the
nodes of other stage.

The edges will always be from ith to i+1th. But not from i+1th to ith.
And edges can't jump any stage. Means no edges from ith to i+2th

- **Problem** 
Find out the shortest path from source to target.

- Applying Dijkstra  
  It's design to find out the shortest path from one node to all the other node.
  We want a better option - Because this graph has some special characteristics.

- Applying Greedy method  
  There is no guarantee that you will get optimal answer.
  But it runs faster compare to dynamic.
  
- Applying Dynamic Programming   
  It will always give you optimal answer. But will take more time than greedy method.
 

#### Dynamic programming - Substructure and Recursive equation  
- Levels of tree - O(k)   // k = number of stages
- Number of nodes in tree - O(k ^ n)  // exponential
- NUmber of unique sub-problems == number of nodes
```
T[i] =  min of ( for all j = (i+1) to n {cost(i,j) + T(j)} )

// Work done
(n-1) + (n-2) + ..... + 1 = O(n^2) = O(V^2) = O(E)
```
