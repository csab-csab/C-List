//prevents multiple inclusion errors
#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct 
{
    //The type of data you want to store in the list
    enum type{
        CHAR, 
        INT,
        FLOAT,
        DOUBLE,
        LONG
    }typeVal;
}Type;

typedef struct 
{
    Type typeOfList; //the data type the list will hold
    void* data; //pointer to array that actually holds data
    size_t elementSize; //size of element, based on type, makes resizing list easier
    size_t size; //how many items are in the list
    size_t capacity; //how much room we have allocated
}List;




List* createList(size_t intialCapacity, Type type);
void add(List* list, void* data);
void removeAt(List* list, size_t index);
size_t size(const List* list);
void freeList(List*);

#endif
