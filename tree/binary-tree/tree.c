#include "tree.h"

struct data {
  int key;
  int value;
};

struct node {
  struct data *data;
  struct node *left;
  struct node *right;
};

Node* create(Node *left, Node *right, int key, int value) {
  Node *node = (Node*) malloc(sizeof(Node));

  if (node == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(1);
  }

  Data *data = (Data*) malloc(sizeof(Data));
  data->key = key;
  data->value = value;

  node->data = data;
  node->left = left;
  node->right = right;

  return node;
}

Node* insertLeft(Node *root, Node *node) {
  if (root == NULL) {
    puts("Error: Empty tree. Cannot insert node.");
    exit(1);
  }

  Node *current = root;
  while (current->left != NULL) {
    current = current->left;
  }

  current->left = node;

  return current->left;
}

Node* insertRight(Node *root, Node *node) {
  if (root == NULL) {
    puts("Error: Empty tree. Cannot insert node.");
    exit(1);
  }

  Node *current = root;
  while (current->right != NULL) {
    current = current->right;
  }

  current->right = node;

  return current->right;
}

Node* find(Node *root, int key) {
  if (root == NULL)
    return NULL;

  if (root->data->key == key)
    return root;

  Node *left = find(root->left, key);

  if (left == NULL)
    return find(root->right, key);

  return left;
}

Node* update(Node *root, int key, int value) {
  Node *node = find(root, key);
  node->data->value = value;
  return node;
}

int contains(Node *root, int key) {
  return find(root, key) != NULL;
}

void preorderTraversal(Node *root) {
  if (root == NULL) return;
  printf("(%d, %d) ->", root->data->key, root->data->value);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
  if (root == NULL) return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("(%d, %d) ->", root->data->key, root->data->value);
}

void inorderTraversal(Node *root) {
  if (root == NULL) return;
  inorderTraversal(root->left);
  printf("(%d, %d) ->", root->data->key, root->data->value);
  inorderTraversal(root->right);
}
