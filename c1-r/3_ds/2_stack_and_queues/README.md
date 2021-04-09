### Stack

- **Implement stack using Array**  
  Using stack with array is more time efficient but we have to know the size before hand.  
  ```c
  int stack[max];
  
  int top = -1;
  
  void push(int item)
  {
    if (top == max-1)
        printf("overflow");
    else {
        stack[++top] = item;
    }
  }
  
  int pop() {
    if (top == -1) {
      printf("underflow");
      return -1;
    } else {
        return stack[top--];
    }
  }
  ```

- **Implement Stack using Linked List**  
  ```c
  struct node {
    int i;
    struct node *link;
  };
  
  void push(int item)
  {
    stuct node *p = (struct node*) malloc(sizeof(struct node));
    if(p == NULL) {
      printf("malloc error");
      return;
    }
  
    p->i = item;
    p->link = head;
    head = p;
  }
  
  int pop()
  {
    if (head == NULL) {
        printf("undeflow");
        return -1;
    }
 
    struct node *p; 
    int item = head->i;
    p = head;
    head = head->link;
    free(p);
  }
  ```

### Queues

- **Implement Queue using Circular Array**  
  - Circular is because to utilize space in case of deletion.  
  - For this we have to keep one cell empty to denote beginning and end.  

  ```c
  void enqueue(item)
  {
    rear = (rear + 1) mod n;
    if (front == rear)
    {
        printf('Q is full');
        if (rear == 0) {
          rear = n - 1;
        } else {
          rear = rear - 1;
        }
        return;
    } else {
        q[rear] = item;
        return;
    }
  }
 
  int dequeue() {
    if (front = rear)
    {
        printf("q is empty");
        return -1;
    } else {
        front = (front + 1) mod n;
        item = q[front];
        return item;
    }
  } 
  ```

- **Implement a Queue using two stack**  
  ```c
  void insert(Q, x) {
    push(s1, x);
  }

  void delete(Q) {
    if stack_empty(s2) {
      if stack_empty(s1) {
        printf("Q is empty");
        return;
      } else {
        while(!stack_empty(s1)) {
            x = pop(s1);
            push(s2, x);
        }
      }
    }
    x = pop(s2);
  }
  ```

- **Implementing a Queue using one stack**  
  Question:  
  Suppose a stack implementation supports, in addition to push and pop, an operation "reverse" which  
  reverses the order of elements on the stack.  
  
  Implement a queue using the above stack, show how to implement "Enqueue" using a single operation and  
  dequeue using a sequence of 3 operations.  

  ```
  enqueue - push
  dequeue - reverse | pop | reverse
  ```

### Infix to postfix conversion algo
```
Infix = a + b
Postfix = a b +

Infix = a + b * c
Postfix = abc*+   // Based on operator precedence

Infix = a + b - c
Postfix = abc+-   // Based on associativity

Infix = a + (b - c)
Postfix = abc-+
```

- **Algo**  
```
a. Create a stack
   // Only the operators will be pushed to the stack not operands

b. for each character 't' in the i/p
   {
     if ('t' in an operand)
        output 't';
     else if ('t' is a right parenthesis)
     {
        pop and output tokens until a left parenthesis is popped (but don't o/p)
        postfix output don't have parenthesis
     }
     else { // 't' is a operator or left parenthesis
       pop and o/p tokens until one of lower priority than 't' is encountered
       or a left parenthesis is encountered or the stack is empty

       push t
     }
   }

   // Left parenthesis will always go into the stack
   // + < (  OR ( < +  OR ( < -

c. pop and o/p all tokens until the stack is empty

// T(n) - O(n)
// S(n) - O(n)
```

### Postfix evaluation algo
- Why do we need postfix?  
  Evaluation an expression can be done very easily.  
  Convert - O(n).  
  Evaluating - O(n).  
  
  Without postfix - evaluation can take O(n^2) or even more.

- **Algo**  
  ```
  1. Scan the postfix string from left to right.

  2. Initialize an empty stack.

  3. Repeat steps 4 and 5 till all the characters are scanned

  4. If the scanned character is an operand, push it onto the stack
  
  5. If the scanned cahracter is an operator, and if the operator is
     unary then pop and element from the stack. If the opetator is binary, the pop
     two elements from the stack. After popping the elements, apply opetator to those
     popped elements. Push the result on to the stack.
  
  6. After all the elements are scanned, the result will be in the stack.
 
  // EX 
  321*+
  ------
  [3, 2, 1]
  2    *   1
  op2     op1
  [3, 2]
  -----------
  3 + 2
  5
  [5] 
  ```
