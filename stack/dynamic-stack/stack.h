#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct data Data;
typedef struct node Node;
typedef struct stack Stack;

// Creates a stack.
Stack* create(int unsigned size);

// Adds an element to the top of the stack.
void push(Stack *stack, unsigned int key, int value);

// Removes the top element from the stack.
void pop(Stack *stack);

// Print stack nodes.
void print(Stack *stack);

// Prints the data of a node.
void printNode(Node *node);

// Returns the top element without removing it.
Node* peek(Stack *stack);

// Checks if the stack is empty.
bool isEmpty(Stack *stack);

// Checks if the stack is full.
bool isFull(Stack *stack);

// Calculates the stack length.
unsigned int length(Stack *stack);

#endif // STACK_H_INCLUDED
