#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  float data;
  struct node *next;
  struct node *prev;
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
  node->prev = head->prev;

  head->prev->next = node;
  head->prev = node;
}

bool isEmpty(Node *head) {
  return head == NULL;
}

Node* findLast(Node *head) {
  if (head == NULL) {
    puts("Error: Empty list. Cannot find last node.");
    exit(1);
  }

  return head->prev;
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
    exit(1);
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

void removeNode(Node **head, int key) {
 if (*head == NULL) {
    puts("Error: Empty list. Cannot remove node.");
    exit(1);
  }

  Node *current = *head;
  while (current->next != *head && current->key != key)
    current = current->next;

  if (current->key != key) {
    puts("Error: Not found. Cannot remove node.");
    exit(1);
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

void printReverseList(Node *head) {
  Node *p = head->prev;
  do {
    printf("(%d, %.1f); ", p->key, p->data);
    p = p->prev;
  } while (p != head->prev);
}

void printReverse(Node *head) {
  if (head == NULL)
    return;
  printReverseList(head);
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
