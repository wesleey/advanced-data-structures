#include "list.h"

struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
};

Node* create(void) {
  return NULL;
}

void insertFirst(Node **head, unsigned int key, int value) {
  Node *node = (Node*) malloc(sizeof(Node));

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
  node->next = *head;

  *head = node;
}

void insertLast(Node *head, unsigned int key, int value) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot insert last node.");
    exit(EXIT_FAILURE);
  }

  Node *node = (Node*) malloc(sizeof(Node));

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

  Node *last = head;
  while (last->next != NULL)
    last = last->next;

  last->next = node;
}

Node* findLast(Node *head) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find last node.");
    exit(EXIT_FAILURE);
  }

  Node *last = head;
  while (last->next != NULL)
    last = last->next;

  return last;
}

Node* findNode(Node *head, unsigned int key) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find node.");
    exit(EXIT_FAILURE);
  }

  Node *current = head;
  while (current != NULL && current->data->key != key)
    current = current->next;

  return current;
}

void updateNode(Node *head, unsigned int key, int value) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot update node.");
    exit(EXIT_FAILURE);
  }

  Node *current = head;
  while (current->next != NULL && current->data->key != key)
    current = current->next;

  if (current->data->key != key) {
    puts("Error: Not found. Cannot update node.");
    exit(EXIT_FAILURE);
  }

  current->data->value = value;
}

void removeFirst(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove first node.");
    exit(EXIT_FAILURE);
  }

  Node *first = *head;
  *head = first->next;

  free(first);
}

void removeLast(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove last node.");
    exit(EXIT_FAILURE);
  }

  Node *last = *head;
  Node *previous = NULL;
  while (last->next != NULL) {
    previous = last;
    last = last->next;
  }

  if (last == *head)
    *head = NULL;
  else
    previous->next = NULL;

  free(last);
}

void removeNode(Node **head, unsigned int key) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  Node *previous = NULL;
  Node *current = *head;
  while (current->next != NULL && current->data->key != key) {
    previous = current;
    current = current->next;
  }

  if (current->data->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  if (current == *head)
    *head = current->next;
  else
    previous->next = current->next;

  free(current);
}

void reverseList(Node **head) {
  Node *next;
  Node *previous = NULL;
  Node *current = *head;

  while (current != NULL) {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  *head = previous;
}

void printNode(Node *node) {
  if (node == NULL) return;
  printf("(%d, %d)\n", node->data->key, node->data->value);
}

void printList(Node *head) {
  for (Node *p = head; p != NULL; p = p->next)
    printf("(%d, %d); ", p->data->key, p->data->value);
  putchar('\n');
}

void printReverseList(Node *head) {
  if (head == NULL) return;
  printReverseList(head->next);
  printf("(%d, %d); ", head->data->key, head->data->value);
}

void printReverse(Node *head) {
  printReverseList(head);
  putchar('\n');
}

bool isEmpty(Node *head) {
  return head == NULL;
}

unsigned int length(Node *head) {
  int length = 0;
  for (Node *p = head; p != NULL; p = p->next)
    length++;
  return length;
}

unsigned int sum(Node *head) {
  int sum = 0;
  for (Node *p = head; p != NULL; p = p->next)
    sum += p->data->value;
  return sum;
}

void sortList(Node *head) {
  Node *current, *next;

  int i, j, k, tempKey, tempData;

  int size = length(head);
  k = size;

  for (i = 0; i < size - 1; i++, k--) {
    current = head;
    next = current->next;

    for (j = 1; j < k; j++) {
      if (current->data->value > next->data->value) {
        tempData = current->data->value;
        current->data->value = next->data->value;
        next->data->value = tempData;

        tempKey = current->data->key;
        current->data->key = next->data->key;
        next->data->key = tempKey;
      }

      current = current->next;
      next = next->next;
    }
  }
}
