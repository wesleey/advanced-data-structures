# Dynamic Stack

## stack.c
```c
struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

struct stack {
  struct node *top;
  int unsigned size;
  int unsigned length;
};
```

## stack.h
**Creates a stack.**
```c
Stack* create(int unsigned size);
```
**Adds an element to the top of the stack.**
```c
void push(Stack *stack, unsigned int key, int value);
```
**Removes the top element from the stack.**
```c
void pop(Stack *stack);
```
**Print stack nodes.**
```c
void print(Stack *stack);
```
**Prints the data of a node.**
```c
void printNode(Node *node);
```
**Returns the top element without removing it.**
```c
Node* peek(Stack *stack);
```
**Checks if the stack is empty.**
```c
bool isEmpty(Stack *stack);
```
**Checks if the stack is full**
```c
bool isFull(Stack *stack);
```
**Calculates the stack length.**
```c
unsigned int length(Stack *stack);
```
