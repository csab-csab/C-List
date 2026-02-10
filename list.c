#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memcpy()
#include "list.h"

/// @brief Creates list with intial capacity specified
/// @param intialCapacity Intial size of list
/// @param type Data type of list
/// @return Pointer to list
List* createList(size_t intialCapacity, Type type)
{
   List* list = (List*)malloc(sizeof(List)); //creates space for list in memory

   //Assign element size in bytes, which later gets used to allocate correct amount of memory
   switch (type.typeVal)
   {
        case CHAR:
            list->elementSize = sizeof(char);
            printf("created list with data type: CHAR.\n ");
            break;
        case INT:
            list->elementSize = sizeof(int);
            printf("created list with data type: INT.\n");
            break;
        case FLOAT:
            list->elementSize = sizeof(float);
            printf("created list with data type: FLOAT.\n");
            break;
        case DOUBLE:
            list->elementSize = sizeof(double);
            printf("created list with data type: DOUBLE.\n");
            break;
        case LONG:
            list->elementSize = sizeof(long);
            printf("created list with data type: LONG.\n");
            break; 
        default:
            free(list);
            printf("Error: Tried creating list with unsopported type!");
            return NULL;
    }
   

   list->typeOfList = type;
   list->data = malloc(intialCapacity * list->elementSize);
   list->size = 0; 
   list->capacity = intialCapacity; 

   printf("\nSize: %zu bytes", intialCapacity * list->elementSize);
   return list;
}

/// @brief Adds specified item to the list
/// @param list Pointer to list
/// @param value Value you would like to add
void listAdd(List* list, void* value)
{
    //if the list is full
    if (list->size >= list->capacity)
    {
        //Double the capacity for efficiency
        //Less allocations = quicker
        list->capacity *= 2;
        //realloc allocates new memory and copies old data over
        list->data = realloc(list->data, list->capacity * list->elementSize);
    }
    
    //calculate the memory address for the next element
    //We cast to a char so we can do pointer arithematic
    //We use char specifically because it's size is 1 byte
    void* destination = (char*)list->data + (list->size * list->elementSize);
    printf("Destination address:%p\n", destination);
    //Copy data to the correct memory address
    memcpy(destination, value, list->elementSize);
    list->size++;
}

/// @brief Removes element at specified index
/// @param list Pointer to list struct
/// @param index Index of the element you want to remove
void listRemoveAt(List* list, size_t index)
{
    //Check if index is valid
    if(index >= list->size)
    {
        printf("Index was out of range.");
        return; 
    }
    
    //Rather than looping through each element and moving elemetns one by one,
    //we get the whole block of the remaining elements after the index of the one 
    //we need to remove and copy it over to the address of the element we want
    //to remove
    size_t numberOfElementsToMove = list->size-index-1;
    size_t bytesToMove = numberOfElementsToMove * list->elementSize;
    void* destination = (char*)list->data + (index*list->elementSize);
    void* source = (char*)list->data + ((index+1)*list->elementSize);
    //Technically not needed but good anyway
    //this doesnt run if we remove the last element of the array
    //because there is nothing to copy over
    if(bytesToMove>0)
    {
        memmove(destination, source, bytesToMove);
    }

    printf("Destination address:%p, Source Address:%p, Number of elements to move: %zu, Number of bytes to move: %zu\n", 
        destination, source, numberOfElementsToMove, bytesToMove);
    list->size --;
}


/// @brief Returns the size of the list
/// @param list Pointer to list
/// @return Number of elements in the list
size_t listSize(const List* list)
{
    return list->size;
}

/// @brief Gets data contained in list. (Please note: you have to cast to the correct type yourself.)
/// @param list 
/// @return Returns void pointer to the start of the block of memory where the data 
///for the list lives
void* listGetData(const List* list)
{
    return list->data;
}

/// @brief Clears list of all its elements
/// @param list 
void listClear(List* list)
{
    list->size = 0;
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