#### Types of algo
```
                                Problems
                                   |
                    -----------------------------------
                    |                                 |
             Decidable problem                  Undecidable problem
               (algo exists)                      (no algo exists)
                    |                                 |
          ---------------------                  Like halting problem of turing machine
          |                   |
     Tractable           Intractable
        |                     |
    If there exists      If a problem is not
    at least one         tractable then it is
    polinomial bound     intractable
    algo - O(n^k)        O(n ^ log n) || O(C ^ n)
```
- In real life we always want (or most problems are) tractable problem
- Intractable problem is there on real life but instead of most optimal solution we provide heuristic
- O(n^k) is polynomial. But O(n ^ 1000) seems big then? It an observation that over time these problems got
  reduced.
