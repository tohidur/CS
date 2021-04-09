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
