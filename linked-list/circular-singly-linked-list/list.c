#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  float data;
  struct node *next;
};

Node* init() {
  return NULL;
}

void insertFirst(Node **head, int key, float data) {
  Node *node = (Node*) malloc(sizeof(Node));

  if (node == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(1);
  }

  node->key = key;
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

void insertLast(Node *head, int key, float data) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot insert last node.");
    exit(1);
  }

  Node *node = (Node*) malloc(sizeof(Node));

  if (node == NULL) {
    puts("Error: Unable to allocate memory.");
    exit(1);
  }

  node->key = key;
  node->data = data;
  node->next = head;

  Node *last = head;
  while (last->next != head)
    last = last->next;

  last->next = node;
}

bool isEmpty(Node *head) {
  return head == NULL;
}

Node* findLast(Node *head) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find last node.");
    exit(1);
  }

  Node *last = head;
  while (last->next != head)
    last = last->next;

  return last;
}

Node* findNode(Node *head, int key) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find node.");
    exit(1);
  }

  Node *current = head;
  while (current->next != head && current->key != key)
    current = current->next;

  if (current->key != key) {
    puts("Error: Not Found. Cannot find node.");
    exit(1);
  }

  return current;
}

void updateNode(Node *head, int key, float data) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot update node.");
    exit(1);
  }

  Node *current = head;
  while (current->next != head && current->key != key)
    current = current->next;

  if (current->key != key) {
    puts("Error: Not Found. Cannot update node.");
    exit(1);
  }

  current->data = data;
}

void removeFirst(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove first node.");
    exit(1);
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
    exit(1);
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

void removeNode(Node **head, int key) {
 if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(1);
  }

  Node *previous = NULL;
  Node *current = *head;
  while (current->next != *head && current->key != key) {
    previous = current;
    current = current->next;
  }

  if (current->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(1);
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
  if (node != NULL)
    printf("(%d, %.1f)\n", node->key, node->data);
}

void printList(Node *head) {
  if (head == NULL)
    return;

  Node *p = head;
  do {
    printf("(%d, %.1f); ", p->key, p->data);
    p = p->next;
  } while (p != head);

  putchar('\n');
}

void printReverseList(Node *head, Node *current) {
  if (current->next != head)
    printReverseList(head, current->next);
  printf("(%d, %.1f); ", current->key, current->data);
}

void printReverse(Node *head) {
  if (head == NULL)
    return;
  printReverseList(head, head);
  putchar('\n');
}

int length(Node *head) {
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

float sum(Node *head) {
  if (head == NULL)
    return 0;

  float sum = 0;
  Node *p = head;
  do {
    sum += p->data;
    p = p->next;
  } while (p != head);

  return sum;
}

void sortList(Node *head) {
  Node *current, *next;

  int i, j, k, tempKey;
  float tempData;

  int size = length(head);
  k = size;

  for (i = 0; i < size - 1; i++, k--) {
    current = head;
    next = current->next;

    for (j = 1; j < k; j++) {
      if (current->data > next->data) {
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;

        tempKey = current->key;
        current->key = next->key;
        next->key = tempKey;
      }

      current = current->next;
      next = next->next;
    }
  }
}
