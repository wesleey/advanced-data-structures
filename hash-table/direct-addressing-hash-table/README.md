# Direct-addressing Hash Table

## table.c
```c
struct element {
  unsigned int key;
  int value;
};

struct table {
  Element **elements;
  unsigned int size;
  unsigned int length;
};
```

## table.h
**Create a table.**
```c
Table* create(unsigned int size);
```
**Inserts an element into the table.**
```c
unsigned int insert(Table *table, unsigned int key, int value);
```
**Computes the hash value for a given key.**
```c
unsigned int hashing(Table *table, unsigned int key);
```
**Finds an element in the table.**
```c
Element* find(Table *table, unsigned int key);
```
**Prints all table elements.**
```c
void print(Table *table);
```
**Prints element in the table.**
```c
void printElement(Element *element);
```
**Checks if the table is empty.**
```c
bool isEmpty(Table *table);
```
**Checks if the table is full.**
```c
bool isFull(Table *table);
```
**Returns the length of the table.**
```c
unsigned int length(Table *table);
```
