#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/// @brief Creates list with intial capacity specified
/// @param intialCapacity Intial size of list
/// @return Pointer to list
List* createList(size_t intialCapacity)
{
   List* list = (List*)malloc(sizeof(List)); //creates space for list in memory
   list->data = (int*)malloc(intialCapacity* sizeof(int));
   list->size = 0; 
   list->capacity = intialCapacity; 
   return list;
}

/// @brief Adds specified item to the list
/// @param list Pointer to list
/// @param value Value you would like to add
void add(List* list, int value)
{
    //if the list is full
    if (list->size >= list->capacity)
    {
        //Double the capacity for efficiency
        //Less allocations = quicker
        list->capacity *= 2;
        //realloc allocates new memory and copies old data over
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
    
    //adds new element to list at next index
    list->data[list->size++] = value;
}

/// @brief Removes element at specified index
/// @param list Pointer to list struct
/// @param index Index of the element you want to remove
void removeAt(List* list, size_t index)
{
    //Check if index is valid
    if(index >= list->size)
    {
        printf("Index was out of range.");
        return; 
    }

    //loop through all elements starting from specified index 
    //move everything in thhe array down one slot
    for(size_t i = index; i < list->size-1; i++)
    {
        list->data[i] = list->data[i+1];
    }
    
    list->size --;
}


/// @brief Returns the size of the list
/// @param list Pointer to list
/// @return Number of elements in the list
size_t size(const List* list)
{
    return list->size;
}

/// @brief Frees memory of list struct once you are finished with it
/// @param list Pointer to list struct
void freeList(List* list)
{
    //free the array memory
    free(list->data);
    //free list struct memory
    free(list);
}