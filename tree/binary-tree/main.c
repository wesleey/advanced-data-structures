#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *root = create(NULL, NULL, 1, 1);

  // Left
  Node *two = insertLeft(root, create(NULL, NULL, 2, 2));
  insertLeft(root, create(NULL, NULL, 3, 3));

  Node *four = insertRight(two, create(NULL, NULL, 4, 4));
  insertLeft(four, create(NULL, NULL, 5, 5));

  // Right
  insertRight(root, create(NULL, NULL, 6, 6));
  insertRight(root, create(NULL, NULL, 7, 7));

  printf("Preorder Traversal: ");
  preorderTraversal(root);
  putchar('\n');

  printf("Postorder Traversal: ");
  postorderTraversal(root);
  putchar('\n');

  printf("Inorder Traversal: ");
  inorderTraversal(root);
  putchar('\n');

  if (contains(root, 2))
    puts("Key 2 is contained in the tree.");

  if (!contains(root, 10))
    puts("Key 10 is not contained in the tree.");

  printf("Node with key 2: ");
  preorderTraversal(find(root, 2));
  putchar('\n');

  printf("Node with key 6: ");
  preorderTraversal(find(root, 6));
  putchar('\n');

  puts("Tree after update node with key 2 to value 200: ");
  update(two, 2, 200);
  preorderTraversal(root);
  putchar('\n');

  puts("Tree after update node with key 4 to value 400: ");
  update(two, 4, 400);
  preorderTraversal(root);
  putchar('\n');

  return 0;
}
