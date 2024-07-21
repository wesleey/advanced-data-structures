#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *list = create();

  insertFirst(&list, 1, 10);
  insertFirst(&list, 2, 20);
  insertFirst(&list, 3, 30);
  insertFirst(&list, 4, 40);
  insertLast(list, 5, 50);
  insertLast(list, 6, 60);

  printf("Empty list? ");
  puts(isEmpty(list) ? "True" : "False");

  printf("Original list: ");
  printList(list);

  printf("First node: ");
  printNode(list);

  printf("Last node: ");
  printNode(findLast(list));

  printf("Node with key 2: ");
  printNode(findNode(list, 2));

  printf("List after update node with key 2 to value 35: ");
  updateNode(list, 2, 35);
  printList(list);

  printf("List after remove first node: ");
  removeFirst(&list);
  printList(list);

  printf("List after remove last node: ");
  removeLast(&list);
  printList(list);

  printf("List after remove node with key 2: ");
  removeNode(&list, 2);
  printList(list);

  printf("To reverse list: ");
  reverseList(&list);
  printList(list);

  printf("List printed in reverse order: ");
  printReverse(list);

  printf("Sorted list in ascending order: ");
  sortList(list);
  printList(list);

  printf("List length: %d\n", length(list));
  printf("Sum of values: %d\n", sum(list));

  return 0;
}
