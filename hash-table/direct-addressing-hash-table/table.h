#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element Element;
typedef struct table Table;

// Create a table.
Table* create(unsigned int size);

// Inserts an element into the table.
unsigned int insert(Table *table, unsigned int key, int value);

// Computes the hash value for a given key.
unsigned int hashing(Table *table, unsigned int key);

// Finds an element in the table.
Element* find(Table *table, unsigned int key);

// Prints all table elements.
void print(Table *table);

// Prints element in the table.
void printElement(Element *element);

// Checks if the table is empty.
bool isEmpty(Table *table);

// Checks if the table is full.
bool isFull(Table *table);

// Returns the length of the table.
unsigned int length(Table *table);

#endif // TABLE_H_INCLUDED
