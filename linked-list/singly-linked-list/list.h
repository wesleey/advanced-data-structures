#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data Data;
typedef struct node Node;

// Creates a linked list.
Node* create(void);

// Inserts a node at the beginning of the list.
void insertFirst(Node **head, unsigned int key, int value);

// Inserts a node at the end of the list.
void insertLast(Node *head, unsigned int key, int value);

// Finds the last node of the list.
Node* findLast(Node *head);

// Finds a node with the specified key.
Node* findNode(Node *head, unsigned int key);

// Updates the value of a node with the specified key.
void updateNode(Node *head, unsigned int key, int value);

// Removes the first node from the list.
void removeFirst(Node **head);

// Removes the last node from the list.
void removeLast(Node **head);

// Removes the node with the specified key.
void removeNode(Node **head, unsigned int key);

// Reverses the order of nodes in the list.
void reverseList(Node **head);

// Prints all nodes in the list.
void printList(Node *head);

// Prints all nodes in the list in reverse order.
void printReverse(Node *head);

// Prints the data of a node.
void printNode(Node *node);

// Checks if the list is empty.
bool isEmpty(Node *head);

// Calculates the length of the list.
unsigned int length(Node *head);

// Calculates the sum of the values ​​in the list.
unsigned int sum(Node *head);

// Sorts the list based on values ​​in ascending order.
void sortList(Node *head);

#endif // LIST_H_INCLUDED
