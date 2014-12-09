#include "list.h"

#include <stdio.h>

int main()
{
    // list = []
    struct List* list = list_create();
    // list.append(...)
    list_append(list, 5);
    list_append(list, 7);
    list_append(list, 12);
    list_append(list, 15);

	list_insert_sorted(list, 20);

    list_print(list);

    // del list
    list_delete(list);
    return 0;
}
