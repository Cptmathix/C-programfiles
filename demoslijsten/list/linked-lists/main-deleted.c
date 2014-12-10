	list_append(list, 5);
    list_append(list, 5);
    list_append(list, 5);
    list_append(list, 5);
    list_append(list, 5);	

    // list.append(...)
    list_append(list, 5);
    list_append(list, 7);
    list_append(list, 12);
    list_append(list, 15);
    
    // list.pop(...)
    list_remove(list, 2);
	
    // print(list)
    list_print(list);
    
    int last;
	if(list_pop(list, &last))
		printf("%d\n", last);
	else
		puts("an error occured");
		
	// print(list)
    list_print(list);

	list_prepend(list, 1);
	// print(list)
    list_print(list);
	list_append(list, 15);
	// print(list)
    list_print(list);
	
	list_insert(list, 0, 4);
	
	// print(list)
    list_print(list);
    
	list_insert(list, 1, 18);
	
	// print(list)
    list_print(list);
    
	list_insert(list, 6, 28);
	
	// print(list)
    list_print(list);

    // del list
    list_delete(list);

	int i = 1;

    // try:
    //     value = list[i]
    //     print(...)
    // except IndexError:
    //     print('Index out of range')

    int value;
    if (list_get(list, i, &value))
        printf("list[%d] = %d\n", i, value);
    else
        puts("Index out of range");

	printf("%d\n", list_length(list));
