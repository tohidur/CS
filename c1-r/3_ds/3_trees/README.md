## Trees

### Traversals
- Inorder  - L-Root-R
- preorder - Root-L-R
- postorder - L-R-Root

- **Algo**  
  ```c
  struct node
  {
    int data;
    struct node *left, *right;
  };

  void inorder(struct node *t)
  {
    if (t == NULL)
        return;
    
    inorder(t->left);
    printf("%d", t->data);
    inorder(t->right);
  }
  
  // T(n) - O(n)
  // S(n) - O(n)
  ```

#### Double Order
- **Algo**  
  ```c
  void doubleorder(struct node *t)
  {
    if (t == NULL)
        return;
    
    printf("%d", t->data);
    doubleorder(t->left);
    printf("%d", t->data);
    doubleorder(t->right);
  } 
  ```

#### Indirect recursion
- **Algo**  
  ```c
  void A(struct node *t)
  {
    if(t)
    {
      printf("%d", t->data);
      B(t->left);
      B(t->right);
    }
  }
  
  void B(struct node *t)
  {
    if(t)
    {
      A(t->left);
      printf("%d", t->data);
      A(t->right);
    }
  }
  ```

- If you start with A then 1st level nodes will called A then second level
  will call B then third level will call A and so on.

### Number of binary trees possible
- **Unlabeled**  
  - 1 node = 1 tree
  - 2 node = 2 tree
  - 3 node = 5 tree
  - n node = `(2n C n) / (n+1)`

- **Labeled**  
  - n node = `( (2n C n) / (n+1) ) * n!`
 
- **All the BST with 3 nodes A, B, C which have preorder - ABC**
  - No. of BST - `( (2n C n) / (n+1) ) * n!` - 30
  - No. of BST unlabeled - `(2n C n) / (n+1)` - 5
  - Each tree can have only one preorder - ABC

- **Properties**  
  - n nodes - pre-order - `( (2n C n) / (n+1) )` binary tree.  
    Can't find any unique binary tree.

  - Given pre-order and post-order - more than one binary tree is possible.
  
  - Given pre-order, post-order and in-order we might not always get a **Unique binary tree**.

  - Given pre-order and in-order - unique binary tree is possible
  
  - Given post-order and in-order - unique binary tree is possible


### Construction of unique binary tree using in-order and pre-order
- Pre-order = ABC
- In-order = BAC

- First element of Pre-order is root

- And once you have root, from in-order left of that root element is
  left sub-tree and right of that root element is right sub-tree.

- In case post-order root is printed at the end. So, we have to come from right
  towards left.


### Recursive program to count the number of nodes
- **Equation**  
  ```
  Number of nodes = NN
  
  NN(T) = 1 + NN(Left) + NN(Right)  // If T is NULL return 0
  ```

- **Algo**
  ```c
  int NN(struct node *t)
  {
    if (t == NULL)
      return 0;
    return (1 + NN(t->left) + NN(t->right));
  }
  ```

### Recursive program to find out number of leaves in binary tree
- **Equation**  
  ```
  NL(t) = 1;  // T is leaf
        = NL(left) + NL(right)  // otherwise
  ```
- **Algo**  
  ```c
  int NL(struct node *t)
  {
    if (t == NULL)
      return 0;

    if (t->left == NULL and t->right == NULL)
      return 1;
    
    return NL(t->left) + NL(t->right);  
  } 
  ```

### Recursive program to find the full nodes
- **Equation**  
  ```
  FN(T) = 0; // T = NULL
        = 0; // T is leaf
        = FN(left) + FN(right) + 1  // if both left and right
        = FN(left) + FN(right)  // if one of left and right not present
  ```

- **Algo**  
  ```c
  int FN(struct node *t)
  {
    if(!t) return 0;
    if (!t->left && !t->right) return 0;

    return FN(t->left) + FN(t->right) + (t->left && t->right) ? 1 : 0;
  }
  ```
  
### Recursive program to find height of the tree
- **Equation**  
  ```
  H(T) = 0;  // T is empty
       = 0;  // T is leaf
       = 1 + max( HT(left) + HT(right) );
  ```

- **Algo**  
  ```c
  int H(struct node *t)
  {
    if(!t) return 0;
    if (!t->left && !t->right) return 0;
    int l = HT(t->left);
    int r = HT(t->right);
    return 1 + (l > r) ? l : r;
  }
  ```
  
### Binary Search Tree

- All the elements on left sub-tree will be less or equal
- And all the elements on right sub-tree will be greater or equal
- Traversing a BST in-order would give you elements in asc order.

#### Deleting a node from binary search tree
- Delete a leaf
  - Just delete
- Delete a non leaf with one child
  - Connect the child to it's parent
- Delete a non leaf with two child 
  1. Go to right sub tree and take the least element and put it in the
     place of deleted element. This least element is in-order successor.

  2. OR, go to the right sub-tree and take the greatest element.
     And replace it with the deleted element. in-order predecessor.

### Questions
#### Leaves in complete n-ary tree
```
A complete n-ary tree is one in which every node has 0 or n sons.
If x is the number of internal nodes of a complete n-ary tree,
then number of leaves in it is?
```

```
For 1 internal node - n children
For 2 internal nodes - n + (n-1) = 2n - 1 children
For 3 internal nodes - n + n + (n-2) = 3n - 2 children
For x internal nodes - n + n + (n-x-1) = xn - x - 1

leaf nodes with x internal nodes = xn - (x - 1)
                                 = x(n - 1) + 1
```

#### Leaf nodes in complete n-ary tree with k nodes.
- Based on previous example - Leaves(L) = Internal(I) * (n - 1) + 1
- L + I = k
- I(n-1) - L = -1
- I + I(n-1) = k-1
- I = k-1/n
- L = k - I = k - (k-1)/n
- L = nk - k + 1/n
- L = (n-1) * k + 1 / n

### Expression trees
- For abstract syntax tree in compiler design
- a + b
  ```
        +
      /   \
    a       b
  
  Pre-Order: +ab
  In-Order : a+b
  Post-Order: ab+
  ```
- a + b * c
  ```
        +
      /   \
    a       *
          /   \
        b       c
  
  Pre-Order: +a*bc
  In-Order: a+b*c+
  Post-Order: abc*+
  ```
- For unary expression a bit tricky
- -a
  ```
    -
     \
       a
  
  In-Order: -a
  // In-Order should match with given expression
  ```

- log a!
  ```
  log
     \
      !
    /
  a
  
  In-Order: log a!
  ```

### Various Tree representations
- **Left child right sibling representation (LCRS)**  

  If we have 10 children and one node can have less than 10 children
  at a time then defining 10 pointers is a waste.
  So every node will have left child and right sibling pointers.
  - Generally for n-ary tree.
  ```
             []
            /
           /
          [] -> [] -> []
         /
        /
       [] -> [] -> []
  ``` 

- **Array Representation - Binary tree**  
  - Root - i index
  - left - 2i  (left shift)
  - right - 2i + 1 (left shift and then OR it with 1)
  - parent - i/2  (right shift by 1)
  - Heaps are perfectly suitable for this (In most other there is space wastage).

- **Nested Form**  
  ```
  L-Root-R = (b a c)
  Root-L-R = a (bde) (cfg)
  ```
