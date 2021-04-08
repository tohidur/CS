### Single linked list
```c
struct node
{
    char data
    struct node *link;
};

struct node *p;
p = head -> link -> link;
```

- **Insert to a SLL**  
  ```c
  struct node *new = (struct node *) malloc(sizeof(struct node));
  new->link = NULL;

  // Insert at the beginning
  new->link = head;
  head = new;
  
  // Insert at the end
  struct node *t;
  t = head;
  while(t->link != NULL)
  {
    t = t->link;
  }
  t->link = new;
  t->link = NULL;
  
  // Insert a node after a node (say after 2)
  struct node *t = head;
  while (t->i != 2) {
    t = t->link;
  }
  new->link = t->link;
  t->link = new;
  ```

- **Delete from SSL**  
  ```
  // From beginning
  if (head == NULL) {
    return;
  } else if (head->link == NULL) {
    free(head);
    head = NULL;
    return;
  } else {
      struct node *t = head;
      head = head->link;
      free(t);
      return head;
  }

  // From the end
  struct node *t = head;
  while (t->link->link != NULL) {
    t = t->link;
  }
  free(t->link);
  t->link = NULL;
  
  // Delete from middle
  struct node *t = head;
  while (t->link->i != 3) {
    t = t->link;
  }
  struct node *k = t->link->link;
  free(t->link);
  t->link = k;
  ```
  
### Reversing a Linked List
- **Iterative**  
  ```c
  struct node {
    int i;
    struct node *next;
  }
  
  struct node* reverse(struct node *cur) {
    struct node *prev = NULL, *nextNode = NULL;
    while(cur) {
        nextNode = cur -> next;
        cur->next = prev;
        prev = cur;
        cur = nextNode;
    }
    return prev;
  }
  ```

- **Recursion**  
  ```c
  struct node *head;
  void reverse(struct node *prev, struct node *cur)
  {
    if (cur) {
        reverser(cur, cur->next);
        cur->next = prev;
    } else {
        head = prev;
    }
  }
  
  int main()
  {
    reverse(NULL, head);
    return 0;
  }
  ```

### Circular Linked List

```
    ----------------------------------
    |                                |
  [3| ]---->[a| ]--->[b| ]---->[c| ]--
sentinel
  head
  
while(p->next != head)
```

### Double Linked List
```c
struct node
{
    int i;
    struct node *prev;
    struct node *next;
};
```
