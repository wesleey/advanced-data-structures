#include "table.h"

struct data {
  int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

struct table {
  struct node **elements;
  unsigned int size;
  unsigned int length;
};

Table* create(unsigned size) {
  Table *table = (Table*) malloc(sizeof(Table));

  if (table == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  table->elements = (Node**) malloc(size * sizeof(Node*));

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

  Data *data = (Data*) malloc(sizeof(Data));

  if (data == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  data->key = key;
  data->value = value;

  Node *node = (Node*) malloc(sizeof(Node));

  if (node == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  int hash = hashing(table, key);

  node->data = data;
  if (table->elements[hash] == NULL)
    node->next = NULL;
  else
    node->next = table->elements[hash];

  table->elements[hash] = node;
  table->length++;

  return hash;
}

unsigned int hashing(Table *table, unsigned int key) {
  return key % table->size;
}

Node* find(Table *table, unsigned int key) {
  if (table == NULL) {
    puts("Error: Empty table. Cannot find node.");
    exit(EXIT_FAILURE);
  }

  unsigned int hash = hashing(table, key);

  Node *node = table->elements[hash];
  while (node != NULL && node->data->key != key)
    node = node->next;

  return node;
}

void print(Table *table) {
  if (length(table) == 0)
    return;

  Node *node;
  for (unsigned int i = 0; i < table->size; i++)
    for (node = table->elements[i]; node != NULL; node = node->next)
      printElement(node);

  putchar('\n');
}

void printElement(Node *node) {
  if (node == NULL) return;
  printf("(%d, %d); ", node->data->key, node->data->value);
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
