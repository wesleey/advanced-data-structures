# Circular Singly Linked List

## list.c
```c
struct node {
  int key;
  float data;
  struct node *next;
};
```

## list.h
**Initializes the linked list.**
```c
Node* init();
```
**Inserts a node at the beginning of the list.**
```c
void insertFirst(Node **head, int key, float data);
```
**Inserts a node at the end of the list.**
```c
void insertLast(Node *head, int key, float data);
```
**Checks if the list is empty.**
```c
bool isEmpty(Node *head);
```
**Finds the last node of the list.**
```c
Node* findLast(Node *head);
```
**Finds a node with the specified key.**
```c
Node* findNode(Node *head, int key);
```
**Updates the data of a node with the specified key.**
```c
void updateNode(Node *head, int key, float data);
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
void removeNode(Node **head, int key);
```
**Reverses the order of nodes in the list.**
```c
void reverseList(Node **head);
```
**Prints the data of a node.**
```c
void printNode(Node *node);
```
**Prints all nodes in the list.**
```c
void printList(Node *head);
```
**Prints all nodes in the list in reverse order.**
```c
void printReverse(Node *head);
```
**Calculates the length of the list.**
```c
int length(Node *head);
```
**Calculates the sum of data in the list.**
```c
float sum(Node *head);
```
**Sorts the list based on data.**
```c
void sortList(Node *head);
```
