## Sets

- Well-defined unordered collection of distinct elements.
- Sets can be finite and infinite
- **Null Sets**  
  Set with no elements. Represented using - ∅ or {}
- **Sub Sets - ⊆**  
  If every element of A is also an element of B then, A is a subset of B.  
  B ⊆ A
- **Proper subsets - ⊂**  
  Trivial set - A and ∅ is trivial subset of A.  
  By default trivial subset is added as per this notation - ⊆.  
  But you can define proper sub set without trivial subset - ⊂
  <br><br>
  A = {1, 2}, B = {1, 2}, c = {1}  
  A and B are trivial subset of each other.  
  C is a proper sub-set of A - C ⊂ A.
  <br><br>
  A ⊆ B and B ⊆ A -> A = B
- **Power Set**  
  If 'A' is  a finite set then set of all subsets of 'A' is called power set of
  'A' -> P(A).  
  If 'A' contains n elements, then P(A) contains -> `2 ^ n` elements.
- **Cardinality of a Set**  
  Number of element present in a set.
- **Universal set - U**  
- **Compliment**  
  A(c on top) or A(- on top) = {x/x ∉ A and x ∈ U}
- **Difference**  
  A - B = {x / x∈A and x ∉ B}
- **Intersection**  
  A ∩ B = {x/x∈A and x∈B}
- **Union**  
  A U B = {x / x∈A and x∈B}
- **Disjoint sets**  
  A ∩ B = ∅, then A and B are disjoint sets
- **Symmetric difference or Boolean Sum**  
  Δ - delta
  A Δ B or (A (+) B)
    = {x / x∈A or x∈B but x ∉ A∩B}
    = (A - B) U (B - A)
    = (A U B) - (A ∩ B)

### Laws of sets
- **Commutative Law**  
  1. (A U B) = (B U A)
  2. (A ∩ B) = (B ∩ A)
  3. (A (+) B) = (B (+) A)
- **Associative Law**  
  1. (A U B) U C = A U (B U C)
  2. (A ∩ B) ∩ C = A ∩ (B ∩ C)
  3. (A (+) B) (+) C = A (+) (B (+) C)
- **Distributive Law**  
  1. A U ( B ∩ C) = (A U B) ∩ (A U C)
  2. A ∩ (B U C) = (A ∩ B) U (A ∩ C)
- **Demorgan's Law**  
  1. (A U B)c = Ac ∩ Bc
  2. (A ∩ B)c = Ac U Bc
  3. A-(B U C) = (A - B) U (A - C)
  4. A-(B ∩ C) = (A - B) ∩ (A - C)
- **Idempotent Law**  
  1. A U A = A
  2. B ∩ B = B
- **Absorption Law**  
  1. A U (A ∩ B) = A
  2. A ∩ (A U B) = A
- **Modular Laws**  
  1. (A U B) ∩ C = A U (B ∩ C) iff A ⊆ C
  2. (A ∩ B) U C = A ∩ (B U C) iff C ⊆ A
