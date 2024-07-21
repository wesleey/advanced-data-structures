#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data Data;
typedef struct node Node;
typedef struct queue Queue;

// Creates a queue.
Queue* create(int unsigned size);

// Adds an element to the rear of the queue.
void enqueue(Queue *queue, unsigned int key, int value);

// Removes the element from the front of the queue.
void dequeue(Queue *queue);

// Print queue nodes.
void print(Queue *queue);

// Prints the data of a node.
void printNode(Node *node);

// Returns the element at the front of the queue without removing it.
Node* peek(Queue *queue);

// Checks if the queue is empty.
bool isEmpty(Queue *queue);

// Checks if the queue is full.
bool isFull(Queue *queue);

// Calculates the queue length.
unsigned int length(Queue *queue);

#endif // QUEUE_H_INCLUDED
