#include "list.h"

#include <stdio.h>

int main()
{

    struct List* list = list_create();

	list_append(list, 1);
	list_append(list, 5);
    list_append(list, 7);
    list_append(list, 12);
    list_append(list, 15);
    
    list_insert_sorted(list, 0);
    
    list_print(list);
   
	list_print_reverse(list);
	
	list_print(list);

    list_delete(list);
    return 0;
}
