#include "list.h"

#include <stdio.h>

int main()
{

    struct DList* list = dlist_create();
    
    dlist_print(list);
    
    dlist_append(list, 5);
    dlist_append(list, 7);
    dlist_append(list, 8);
    dlist_print(list);
	dlist_print_reverse(list);
	
	dlist_remove(list, 1);
	dlist_print(list);
	dlist_print_reverse(list);
	
    dlist_delete(list);
    return 0;
}
