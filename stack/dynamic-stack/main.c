#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Stack *stack = create(10);

  for (unsigned int i = 1; i <= 10; i++)
    push(stack, i, i * 10);

  printf("Empty stack? ");
  puts(isEmpty(stack) ? "True" : "False");

  printf("Full stack? ");
  puts(isFull(stack) ? "True" : "False");

  // puts("Expect maximum size violation error:");
  // push(stack, 50, 500);

  printf("Original stack: ");
  print(stack);

  for (unsigned int i = 0; i < 5; i++)
    pop(stack);

  printf("Stack after remove 5 nodes: ");
  print(stack);

  printf("Top element: ");
  printNode(peek(stack));
  putchar('\n');

  printf("Length: %d", length(stack));

  return 0;
}
