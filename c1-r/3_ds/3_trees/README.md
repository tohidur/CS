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
