#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>

typedef struct node Node;

// Initializes the linked list
Node* init();

// Inserts a node at the beginning of the list
void insertFirst(Node **head, int key, float data);

// Inserts a node at the end of the list
void insertLast(Node *head, int key, float data);

// Checks if the list is empty
bool isEmpty(Node *head);

// Finds the last node of the list
Node* findLast(Node *head);

// Finds a node with the specified key
Node* findNode(Node *head, int key);

// Updates the data of a node with the specified key
void updateNode(Node *head, int key, float data);

// Removes the first node from the list
void removeFirst(Node **head);

// Removes the last node from the list
void removeLast(Node **head);

// Removes the node with the specified key
void removeNode(Node **head, int key);

// Reverses the order of nodes in the list
void reverseList(Node **head);

// Prints the data of a node
void printNode(Node *node);

// Prints all nodes in the list
void printList(Node *head);

// Prints all nodes in the list in reverse order
void printReverse(Node *head);

// Calculates the length of the list
int length(Node *head);

// Calculates the sum of data in the list
float sum(Node *head);

// Sorts the list based on data
void sortList(Node *head);

#endif // LIST_H_INCLUDED
