### Knapsack problem

- **Problem**  
  We are given a bag of capacity 20 units and we have 3 objects provided that. Every object have some profit
  provided that you sell certain units of a object.

  |        | obj 1  | obj 2   |  obj3  |
  | ------ | ------ | ------- | ------ |
  | Profit |   25   |   24    |   15   |
  | Weight |   18   |   15    |   10   |
  
  What the objects you want to place into the bag in such a way that we get the maximum profit.

#### Analysis
- In greedy method we are allowed to use fraction of units
- There are various way we can go about this problem
  - Greedy about profit
  - Greedy about weight
  - Greedy about profit/weight
    We will get max values by this

- **Algo**  
  ```
  GreedyKnapsack
  {
    for i = 1 to n;
        compute pi/wi;
    sort objects in non increasing order of p/w

    for i = 1 to n from sorted list  // Instead of this you can use max heap and deletion
        if (m > 0 && wi <= m)
            m = m - wi;
            p = p + pi;
        else
            break;
    if (m > 0)
        p = p + (pi * (m / wi));  
  }
  
  // Time complexity - O(n log n)
  ```

- **Note**  
  Greedy only works with fractional knapsack not 0/1 knapsack.
