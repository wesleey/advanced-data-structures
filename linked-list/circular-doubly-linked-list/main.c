#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *head = init();

  insertFirst(&head, 1, 10.5);
  insertFirst(&head, 2, 20.3);
  insertFirst(&head, 3, 30.7);
  insertFirst(&head, 4, 40.1);
  insertLast(head, 5, 50.9);
  insertLast(head, 6, 60.2);

  puts("Empty list?");
  isEmpty(head) ? puts("True") : puts("False");
  putchar('\n');

  puts("Original list:");
  printList(head);
  putchar('\n');

  puts("First node:");
  printNode(head);
  putchar('\n');

  puts("Last node:");
  printNode(findLast(head));
  putchar('\n');

  puts("Node with key 2:");
  printNode(findNode(head, 2));
  putchar('\n');

  updateNode(head, 2, 35.8);
  puts("List after update node with key 2:");
  printList(head);
  putchar('\n');

  removeFirst(&head);
  puts("List after remove first node:");
  printList(head);
  putchar('\n');

  removeLast(&head);
  puts("List after remove last node:");
  printList(head);
  putchar('\n');

  removeNode(&head, 2);
  puts("List after remove node with key 2:");
  printList(head);
  putchar('\n');

  reverseList(&head);
  puts("To reverse list:");
  printList(head);
  putchar('\n');

  puts("List printed in reverse order:");
  printReverse(head);
  putchar('\n');

  sortList(head);
  puts("Sorted list in ascending order:");
  printList(head);
  putchar('\n');

  printf("List length: %d\n", length(head));
  printf("Sum of values: %.1f\n", sum(head));

  return 0;
}
