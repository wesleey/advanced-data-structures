# Doubly Linked List

## list.c
```c
struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
  struct node *prev;
};
```

## list.h
**Creates a linked list.**
```c
Node* create(void);
```
**Inserts a node at the beginning of the list.**
```c
void insertFirst(Node **head, unsigned int key, int value);
```
**Inserts a node at the end of the list.**
```c
void insertLast(Node *head, unsigned int key, int value);
```
**Finds the last node of the list.**
```c
Node* findLast(Node *head);
```
**Finds a node with the specified key.**
```c
Node* findNode(Node *head, unsigned int key);
```
**Updates the value of a node with the specified key.**
```c
void updateNode(Node *head, unsigned int key, int value);
```
**Removes the first node from the list.**
```c
void removeFirst(Node **head);
```
**Removes the last node from the list.**
```c
void removeLast(Node **head);
```
**Removes the node with the specified key.**
```c
void removeNode(Node **head, unsigned int key);
```
**Reverses the order of nodes in the list.**
```c
void reverseList(Node **head);
```
**Prints all nodes in the list.**
```c
void printList(Node *head);
```
**Prints all nodes in the list in reverse order.**
```c
void printReverse(Node *head);
```
**Prints the value of a node.**
```c
void printNode(Node *node);
```
**Checks if the list is empty.**
```c
bool isEmpty(Node *head);
```
**Calculates the length of the list.**
```c
unsigned int length(Node *head);
```
**Calculates the sum of the values ​​in the list.**
```c
unsigned int sum(Node *head);
```
**Sorts the list based on values ​​in ascending order.**
```c
void sortList(Node *head);
```
