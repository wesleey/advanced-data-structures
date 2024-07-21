#include "queue.h"

struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

struct queue {
  struct node *front;
  int unsigned size;
  int unsigned length;
};

Queue* create(int unsigned size) {
  Queue* queue = (Queue*) malloc(sizeof(Queue));

  if (queue == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(EXIT_FAILURE);
  }

  queue->front = NULL;
  queue->size = size;
  queue->length = 0;

  return queue;
}

void enqueue(Queue *queue, unsigned int key, int value) {
  if (queue->length == queue->size) {
    puts("Error: Queue full. Cannot insert node.");
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
  node->next = NULL;

  if (queue->front == NULL) {
    queue->front = node;
  } else {
    Node *last = queue->front;
    while (last->next != NULL)
      last = last->next;
    last->next = node;
  }

  queue->length++;
}

void dequeue(Queue *queue) {
  if (queue->front == NULL) {
    puts("Error: Empty queue. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  Node *temp = queue->front;
  queue->front = temp->next;
  queue->length--;

  free(temp->data);
  free(temp);
}

void print(Queue *queue) {
  for (Node *node = queue->front; node != NULL; node = node->next)
    printNode(node);
  putchar('\n');
}

void printNode(Node *node) {
  printf("(%d, %d); ", node->data->key, node->data->value);
}

Node* peek(Queue *queue) {
  return queue->front;
}

bool isEmpty(Queue *queue) {
  return queue->length == 0 && queue->front == NULL;
}

bool isFull(Queue *queue) {
  return queue->length == queue->size;
}

unsigned int length(Queue *queue) {
  return queue->length;
}
