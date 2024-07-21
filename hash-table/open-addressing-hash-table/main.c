#include "table.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Table *table = create(10);

  insert(table, 0, 0);
  insert(table, 10, 100);

  for (unsigned int i = 1; i <= 8; i++)
    insert(table, i, i * 10);

  printf("Empty table? ");
  puts(isEmpty(table) ? "True" : "False");

  printf("Full table? ");
  puts(isFull(table) ? "True" : "False");

  // puts("Expect maximum size violation error:");
  // insert(table, 50, 500);

  printf("Elements: ");
  print(table);

  printf("Element with key 6: ");
  printElement(find(table, 6));
  putchar('\n');

  printf("Element with key 8: ");
  printElement(find(table, 8));
  putchar('\n');

  printf("Element with key 10: ");
  printElement(find(table, 10));
  putchar('\n');

  printf("Length: %d\n", length(table));

  return 0;
}
