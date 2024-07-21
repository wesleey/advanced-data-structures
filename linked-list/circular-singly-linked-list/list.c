#include "list.h"

struct data {
  unsigned  key;
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

  if (*head == NULL)
    node->next = node;
  else {
    node->next = *head;

    Node *last = *head;
    while (last->next != *head)
      last = last->next;

    last->next = node;
  }

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
  node->next = head;

  Node *last = head;
  while (last->next != head)
    last = last->next;

  last->next = node;
}

Node* findLast(Node *head) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find last node.");
    exit(EXIT_FAILURE);
  }

  Node *last = head;
  while (last->next != head)
    last = last->next;

  return last;
}

Node* findNode(Node *head, unsigned int key) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find node.");
    exit(EXIT_FAILURE);
  }

  Node *current = head;
  while (current->next != head && current->data->key != key)
    current = current->next;

  if (current->data->key != key) {
    puts("Error: Not Found. Cannot find node.");
    exit(EXIT_FAILURE);
  }

  return current;
}

void updateNode(Node *head, unsigned int key, int value) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot update node.");
    exit(EXIT_FAILURE);
  }

  Node *current = head;
  while (current->next != head && current->data->key != key)
    current = current->next;

  if (current->data->key != key) {
    puts("Error: Not Found. Cannot update node.");
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

  if (first->next == *head)
    *head = NULL;
  else {
    Node *last = *head;
    while (last->next != *head)
      last = last->next;

    *head = first->next;
    last->next = *head;
  }

  free(first);
}

void removeLast(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove last node.");
    exit(EXIT_FAILURE);
  }

  Node *last = *head;
  Node *previous = NULL;
  while (last->next != *head) {
    previous = last;
    last = last->next;
  }

  if (last == *head)
    *head = NULL;
  else
    previous->next = last->next;

  free(last);
}

void removeNode(Node **head, unsigned int key) {
 if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  Node *previous = NULL;
  Node *current = *head;
  while (current->next != *head && current->data->key != key) {
    previous = current;
    current = current->next;
  }

  if (current->data->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  if (current == *head) {
    Node *last = *head;
    while (last->next != *head)
      last = last->next;

    *head = current->next;
    last->next = *head;
  }
  else
    previous->next = current->next;

  free(current);
}

void reverseList(Node **head) {
  if (*head == NULL)
    return;

  Node *last = *head;
  while (last->next != *head)
    last = last->next;

  Node *next;
  Node *previous = last;
  Node *current = *head;

  do {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  } while (current != *head);

  *head = previous;
}

void printNode(Node *node) {
  if (node == NULL) return;
  printf("(%d, %d)\n", node->data->key, node->data->value);
}

void printList(Node *head) {
  if (head == NULL)
    return;

  Node *p = head;
  do {
    printf("(%d, %d); ", p->data->key, p->data->value);
    p = p->next;
  } while (p != head);

  putchar('\n');
}

void printReverseList(Node *head, Node *current) {
  if (current->next != head)
    printReverseList(head, current->next);
  printf("(%d, %d); ", current->data->key, current->data->value);
}

void printReverse(Node *head) {
  if (head == NULL) return;
  printReverseList(head, head);
  putchar('\n');
}

bool isEmpty(Node *head) {
  return head == NULL;
}

unsigned int length(Node *head) {
  if (head == NULL)
    return 0;

  int length = 0;
  Node *p = head;
  do {
    length++;
    p = p->next;
  } while (p != head);

  return length;
}

unsigned int sum(Node *head) {
  if (head == NULL)
    return 0;

  int sum = 0;
  Node *p = head;
  do {
    sum += p->data->value;
    p = p->next;
  } while (p != head);

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
