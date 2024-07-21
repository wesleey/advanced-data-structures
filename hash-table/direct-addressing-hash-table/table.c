#include "table.h"

struct element {
  unsigned int key;
  int value;
};

struct table {
  Element **elements;
  unsigned int size;
  unsigned int length;
};

Table* create(unsigned int size) {
  Table *table = (Table*) malloc(sizeof(Table));

  if (table == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  table->elements = (Element**) malloc(size * sizeof(Element*));

  if (table->elements == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  for (unsigned int i = 0; i < size; i++)
    table->elements[i] = NULL;

  table->size = size;
  table->length = 0;

  return table;
}

unsigned int insert(Table *table, unsigned int key, int value) {
  if (table == NULL) {
    puts("Error: Empty table. Cannot insert node.");
    exit(EXIT_FAILURE);
  }

  if (table->length == table->size) {
    puts("Error: Table full. Cannot insert node.");
    exit(EXIT_FAILURE);
  }

  int hash = hashing(table, key);

  if (table->elements[hash] != NULL) {
    printf("Error: Collision. Element with hash %d already exists.", hash);
    exit(EXIT_FAILURE);
  }

  Element *element = (Element*) malloc(sizeof(Element));

  if (element == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  element->key = key;
  element->value = value;

  table->elements[hash] = element;
  table->length++;

  return hash;
}

unsigned int hashing(Table *table, unsigned int key) {
  return key % table->size;
}

Element* find(Table *table, unsigned int key) {
  if (table == NULL) {
    puts("Error: Empty table. Cannot find node.");
    exit(EXIT_FAILURE);
  }

  unsigned int hash = hashing(table, key);
  Element *element = table->elements[hash];

  if (element == NULL || element->key != key)
    return NULL;

  return element;
}

void print(Table *table) {
  if (length(table) == 0)
    return;

  Element* element;
  for (unsigned int i = 0; i < table->size; i++)
    printElement(table->elements[i]);

  putchar('\n');
}

void printElement(Element *element) {
  if (element == NULL) return;
  printf("(%d, %d); ", element->key, element->value);
}

bool isEmpty(Table *table) {
  return table->length == 0;
}

bool isFull(Table *table) {
  return table->length == table->size;
}

unsigned int length(Table *table) {
  return table->length;
}
