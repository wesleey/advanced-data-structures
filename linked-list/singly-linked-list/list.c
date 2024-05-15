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
  node->next = *head;

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
  node->next = NULL;

  Node *last = head;
  while (last->next != NULL)
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
  while (last->next != NULL)
    last = last->next;

  return last;
}

Node* findNode(Node *head, int key) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find node.");
    exit(1);
  }

  Node *current = head;
  while (current != NULL && current->key != key)
    current = current->next;

  return current;
}

void updateNode(Node *head, int key, float data) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot update node.");
    exit(1);
  }

  Node *current = head;
  while (current->next != NULL && current->key != key)
    current = current->next;

  if (current->key != key) {
    puts("Error: Not found. Cannot update node.");
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
  *head = first->next;

  free(first);
}

void removeLast(Node **head) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove last node.");
    exit(1);
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

void removeNode(Node **head, int key) {
  if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(1);
  }

  Node *previous = NULL;
  Node *current = *head;
  while (current->next != NULL && current->key != key) {
    previous = current;
    current = current->next;
  }

  if (current->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(1);
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
  if (node != NULL)
    printf("(%d, %.1f)\n", node->key, node->data);
}

void printList(Node *head) {
  for (Node *p = head; p != NULL; p = p->next)
    printf("(%d, %.1f); ", p->key, p->data);
  putchar('\n');
}

void printReverseList(Node *head) {
  if (head == NULL)
    return;
  printReverseList(head->next);
  printf("(%d, %.1f); ", head->key, head->data);
}

void printReverse(Node *head) {
  printReverseList(head);
  putchar('\n');
}

int length(Node *head) {
  int length = 0;
  for (Node *p = head; p != NULL; p = p->next)
    length++;
  return length;
}

float sum(Node *head) {
  float sum = 0;
  for (Node *p = head; p != NULL; p = p->next)
    sum += p->data;
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
