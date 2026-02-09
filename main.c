#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
   Type INT_TYPE;
   INT_TYPE.typeVal = INT;
    
    //Create a list of ints size 10
    List* myList = createList(10, INT_TYPE);
    
    printf("IntialSize : %zu\n", size(myList));
    //we use a compund literal
    //equvielant to writing: 
    //int x = 5;
    //add(myList, &x); 
    add(myList, &(int){5});

    for(int i = 1; i < 10; i++)
    {
        add(myList, &i);
    }

    //removeAt(myList, 3);

    printf("After resize : %zu\n", size(myList));

    int* data = (int*)myList->data;
    //print out list
    for(int i = 0; i < size(myList); i++ )
    {
       printf("%d", data[i]);
       printf(",");
    }

    freeList(myList);
    return 0;
}
