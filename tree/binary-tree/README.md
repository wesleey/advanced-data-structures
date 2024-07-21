# Binary Tree

## tree.c
```c
struct data {
  int key;
  int value;
};

struct node {
  struct data *data;
  struct node *left;
  struct node *right;
};
```

## tree.h
**Creates a node in the tree.**
```c
Node* create(Node *left, Node *right, int key, int value);
```
**Inserts a node into the tree on the left.**
```c
Node* insertLeft(Node *root, Node *node);
```
**Inserts a node into the tree on the right.**
```c
Node* insertRight(Node *root, Node *node);
```
**Finds a node in the tree.**
```c
Node* find(Node *root, int key);
```
**Updates a tree node.**
```c
Node* update(Node *root, int key, int value);
```
**Check if a key is contained in the tree.**
```c
int contains(Node *root, int key);
```
**Prints in preorder.**
```c
void preorderTraversal(Node *root);
```
**Prints in postorder.**
```c
void postorderTraversal(Node *root);
```
**Prints in inorder.**
```c
void inorderTraversal(Node *root);
```
