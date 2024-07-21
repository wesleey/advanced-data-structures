#include "list.h"

struct data {
  unsigned int key;
  int value;
};

struct node {
  struct data *data;
  struct node *next;
  struct node *prev;
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

  if (*head == NULL) {
    node->next = node;
    node->prev = node;
  } else {
    node->next = *head;
    node->prev = (*head)->prev;

    (*head)->prev->next = node;
    (*head)->prev = node;
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
  node->prev = head->prev;

  head->prev->next = node;
  head->prev = node;
}

Node* findLast(Node *head) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find last node.");
    exit(EXIT_FAILURE);
  }

  return head->prev;
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

  if (first->next == *head) {
    *head = NULL;
  } else {
    first->next->prev = first->prev;
    first->prev->next = first->next;
    *head = first->next;
  }

  free(first);
}

void removeLast(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove last node.");
    exit(EXIT_FAILURE);
  }

  Node *last = (*head)->prev;

  if (last == *head) {
    *head = NULL;
  } else {
    last->prev->next = *head;
    (*head)->prev = last->prev;
  }

  free(last);
}

void removeNode(Node **head, unsigned int key) {
 if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  Node *current = *head;
  while (current->next != *head && current->data->key != key)
    current = current->next;

  if (current->data->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(EXIT_FAILURE);
  }

  if (current == *head) {
    *head = current->next;
    current->prev->next = *head;
    (*head)->prev = current->prev;
  } else {
    current->prev->next = current->next;
    current->next->prev = current->prev;
  }

  free(current);
}

void reverseList(Node **head) {
  if (*head == NULL)
    return;

  Node *next;
  Node *current = *head;

  do {
    next = current->next;
    current->next = current->prev;
    current->prev = next;
    current = next;
  } while (current != *head);

  *head = current->next;
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

void printReverseList(Node *head) {
  Node *p = head->prev;
  do {
    printf("(%d, %d); ", p->data->key, p->data->value);
    p = p->prev;
  } while (p != head->prev);
}

void printReverse(Node *head) {
  if (head == NULL) return;
  printReverseList(head);
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
