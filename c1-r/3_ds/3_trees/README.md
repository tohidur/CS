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
