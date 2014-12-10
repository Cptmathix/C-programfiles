#include "list.h"

#include <stdio.h>

int main()
{

    struct DList* list = dlist_create();
    
    dlist_print(list);
    printf("list length = %d\n", dlist_length(list));
    dlist_append(list, 5);
    printf("list length = %d\n", dlist_length(list));
    dlist_append(list, 7);
    printf("list length = %d\n", dlist_length(list));
    dlist_append(list, 8);
    printf("list length = %d\n", dlist_length(list));
    dlist_print(list);
	dlist_print_reverse(list);
	
	dlist_remove(list, 1);
	printf("list length = %d\n", dlist_length(list));
	dlist_print(list);
	dlist_print_reverse(list);
	dlist_insert(list, 0, 5);
	printf("list length = %d\n", dlist_length(list));
	dlist_print(list);
	dlist_print_reverse(list);
	
    dlist_delete(list);
    return 0;
}
