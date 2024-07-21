#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Queue *queue = create(10);

  for (unsigned int i = 1; i <= 10; i++)
    enqueue(queue, i, i * 10);

  printf("Empty queue? ");
  puts(isEmpty(queue) ? "True" : "False");

  printf("Full queue? ");
  puts(isFull(queue) ? "True" : "False");

  // puts("Expect maximum size violation error:");
  // enqueue(queue, 50, 500);

  printf("Original queue: ");
  print(queue);

  for (unsigned int i = 0; i < 5; i++)
    dequeue(queue);

  printf("Queue after remove 5 nodes: ");
  print(queue);

  printf("Element at the front: ");
  printNode(peek(queue));
  putchar('\n');

  printf("Length: %d", length(queue));

  return 0;
}
