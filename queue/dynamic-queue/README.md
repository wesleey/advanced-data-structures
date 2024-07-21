# Dynamic Queue

## queue.c
```c
struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

struct queue {
  struct node *front;
  int unsigned size;
  int unsigned length;
};
```

## queue.h
**Creates a queue.**
```c
Queue* create(int unsigned size);
```
**Adds an element to the rear of the queue.**
```c
void enqueue(Queue *queue, unsigned int key, int value);
```
**Removes the element from the front of the queue.**
```c
void dequeue(Queue *queue);
```
**Print queue nodes.**
```c
void print(Queue *queue);
```
**Prints the data of a node.**
```c
void printNode(Node *node);
```
**Returns the element at the front of the queue without removing it.**
```c
Node* peek(Queue *queue);
```
**Checks if the queue is empty.**
```c
bool isEmpty(Queue *queue);
```
**Checks if the queue is full.**
```c
bool isFull(Queue *queue);
```
**Calculates the queue length.**
```c
unsigned int length(Queue *queue);
```
