#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct data Data;
typedef struct node Node;

// Creates a node in the tree
Node* create(Node *left, Node *right, int key, int value);

// Inserts a node into the tree on the left
Node* insertLeft(Node *root, Node *node);

// Inserts a node into the tree on the right
Node* insertRight(Node *root, Node *node);

// Finds a node in the tree
Node* find(Node *root, int key);

// Updates a tree node
Node* update(Node *root, int key, int value);

// Check if a key is contained in the tree
int contains(Node *root, int key);

// Prints in preorder
void preorderTraversal(Node *root);

// Prints in postorder
void postorderTraversal(Node *root);

// Prints in inorder
void inorderTraversal(Node *root);

#endif // TREE_H_INCLUDED
