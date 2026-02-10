#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
   Type INT_TYPE;
   INT_TYPE.typeVal = INT;
   Type CHAR_TYPE;
   CHAR_TYPE.typeVal = CHAR;
    
    //Create a list of ints size 10
    List* myList = createList(10, INT_TYPE);
    
    List* myCharList = createList(1, CHAR_TYPE);
    
    char myMessage[] = {'H','e', 'l','l','o',' ', 'w', 'o','r','l','d'};

    printf("\nIntialSize(in elements) : %zu\n", listSize(myList));
    
    //we use a compund literal
    //equvielant to writing: 
    //int x = 5;
    //add(myList, &x); 
    listAdd(myList, &(int){5});

    for(int i = 1; i < 10; i++)
    {
        listAdd(myList, &i);
    }

    listRemoveAt(myList, 3);

    printf("After resize(size in elements):%zu\n", listSize(myList));

    int* data = (int*)myList->data;
    //print out list
    for(size_t i = 0; i < listSize(myList); i++ )
    {
       printf("%d", data[i]);
       printf(",");
    }

    //calculate size of array
    size_t length = sizeof(myMessage)/ sizeof(char);
    //add elemetns from char array into char list
    for (size_t i = 0; i < length; i++)
    {
       listAdd(myCharList, &myMessage[i]);
    }
    
    //create get() function
    char* charListData = (char*)listGetData(myCharList);

    for(size_t i = 0; i < listSize(myCharList); i++)
    {
      printf("%c", charListData[i]);
    }

    freeList(myList);
    freeList(myCharList);
    return 0;
}
