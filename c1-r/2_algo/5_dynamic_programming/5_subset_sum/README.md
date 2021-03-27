### Subset Sum
If we have n number find out the subset whose sum = W.  
It's quite similar to 0/1 knapsack.  

- We can't apply greedy here.  
- Exhaustive search - Number subset - O(2 ^ n).  
- **Recursion Equation**  
  ```
               | SS(i-1, S)  ; S < ai
               | SS(i-1, S - ai) OR sS(i-1, S)    ; S > ai
  SS(i, S) =   | True   ; i = 0, S = 0
               | False  ; i = 0, S != 0
  ```

- **Recursion Tree**  
  ```
            SS(10,10)
        SS(9,9)   SS(9,10)
   SS(8,8) SS(8,9) ....
   ...
   SS(0,0)
  
  Depth of tree - O(n)
  Number of nodes in tree - 2 ^ n
  ```

- **Unique sub-problems**  
  n * S
