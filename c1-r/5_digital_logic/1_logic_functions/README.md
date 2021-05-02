### Logic functions

#### Basic Properties
- **Idempotency**  
  x.x = x
  x+x = x
  
- **Commutativity**  
  x + y = y + x
  xy = yx
  
- **Associativity**  
  (x + y) + z = x + (y + z)
  (xy)z = x(yz)

- **Complementation**  
  x + x(complement) = 1
  x.x(complement) = 0

- **Distributivity**  
  x(y+z) = xy + xz
  x+yz = (x + y).(x + z)
 
 
#### Switching expressions  
A finite number of combinations of switching variables and constants {0,1} by means of switching operations
(+, ., NOT). We want to simplify expression as much as possible to make our circuit simple.

- **Properties for Simplification**  
```
  Absorption:  
    x + xy = x  
    x + x'y = x + y  
    
    Duel -> x . (x + y) = x  
         -> x . (x' + y) = x . y  
  
  Dual:  
    x . (x' + y) = xy  
    
  Consensus Theorem:  
    xy + x'z + yz = xy + x'z  
    xy + x'z + yz(1)
    xy + x'z + yz(x+x')
    xy + x'z + yzx + yzx'
    xy(1+z) + x'z (1 + y) = xy + x'z
``` 

- Simplify this - x'y'z + yz + xz
  ```
  z(x'y' + y + x)
  z((x'+y)(y' + y) + x)
  z(x' + y + x)
  z(1 + y)
  z
  ```

Here, inversions and cancellations are not allowed.
a + c = a + b
then c != b - You can not cancel out a.
Similar for - ac = ab

#### De-morgan's law and simplification
Find whole complement of an expression

```
(xy)(whole complement) = x' + y'
(x+y)(whole complement) = x'y'
```

f(a, b, ... z, 0, 1, . , +)
f' = f(a', b', ... z', 1, 0, + , .)
fd = f(a, b, ... z, 1, 0, + , .)
