#include <stdio.h>
#include "list.h"

int main(int argc, char const *argv[])
{
    List* myList = createList(10);
    
    printf("IntialSize : %zu\n", size(myList));
    add(myList, 0);

    for(int i = 1; i < 10; i++)
    {
        add(myList, i);
    }

    removeAt(myList, 3);

    printf("After resize : %zu\n", size(myList));

    //print out list
    for(int i = 0; i < size(myList); i++ )
    {
        printf("%d", myList->data[i]);
        printf(",");
    }

    freeList(myList);
    return 0;
}
