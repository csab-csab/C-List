//prevents multiple inclusion errors
#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct 
{
    int* data; //pointer to array that actually holds data
    size_t size; //how many items are in the list
    size_t capacity; //how much room we have allocated
}List;

List* createList(size_t intialCapacity);
void add(List* list, int value);
void removeAt(List* list, size_t index);
size_t size(const List* list);
void freeList(List*);

#endif
