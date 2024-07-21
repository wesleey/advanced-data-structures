#include "stack.h"

struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

struct stack {
  struct node *top;
  int unsigned size;
  int unsigned length;
};

Stack* create(int unsigned size) {
  Stack* stack = (Stack*) malloc(sizeof(Stack));

  if (stack == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  stack->top = NULL;
  stack->size = size;
  stack->length = 0;

  return stack;
}

void push(Stack *stack, unsigned int key, int value) {
  if (stack->length == stack->size) {
    puts("Error: Stack full. Cannot insert node.");
    exit(EXIT_FAILURE);
  }

  Node* node = (Node*) malloc(sizeof(Node));

  if (node == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  Data *data = (Data*) malloc(sizeof(Data));

  if (data == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  data->key = key;
  data->value = value;

  node->data = data;
  node->next = stack->top;

  stack->top = node;
  stack->length++;
}

void pop(Stack *stack) {
  if (stack->top == NULL) {
    puts("Error: Empty stack. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  Node *temp = stack->top;
  stack->top = temp->next;
  stack->length--;

  free(temp->data);
  free(temp);
}

void print(Stack *stack) {
  for (Node *node = stack->top; node != NULL; node = node->next)
    printNode(node);
  putchar('\n');
}

void printNode(Node *node) {
  printf("(%d, %d); ", node->data->key, node->data->value);
}

Node* peek(Stack *stack) {
  return stack->top;
}

bool isEmpty(Stack *stack) {
  return stack->length == 0 && stack->top == NULL;
}

bool isFull(Stack *stack) {
  return stack->length == stack->size;
}

unsigned int length(Stack *stack) {
  return stack->length;
}
