#include <stdlib.h>
#include <stdio.h>

#include "list.h"

// Create an empty list
//
// Python: list = []
struct List* list_create()
{
    struct List* list = malloc(sizeof(struct List));
    list->first = NULL;
    return list;
}

// Append the given value to the given list
//
// Python: list.append(value)
void list_append(struct List* list, int value)
{
    // create a new ListNode to store the value in
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;

    // if the list is empty, make the new node the first node
    if (list->first == NULL)
        list->first = node;
    else
    {
        // find the last node and set the new node as its next node
        struct ListNode* current = list->first;

        while (current->next != NULL)
            current = current->next;

        current->next = node;
    }
}

// Return the length of the given list (i.e., the number of values in it)
//
// Python: length = len(list)
int list_length(struct List* list)
{
    int length = 0;
    struct ListNode* current = list->first;

    while (current != NULL)
    {
        length++;
        current = current->next;
    }

    return length;
}

// Get the value of the element at the given index and store it in the memory
// location pointed to by value. If the given index is out of range, 0 is
// returned, otherwise 1 is returned.
//
// Python: value = list[i]
// (An IndexError would correspond to a return value of 0)
int list_get(struct List* list, int index, int* value)
{
    if (index < 0 || index >= list_length(list))
        return 0;

    struct ListNode* current = list->first;

    for (int i = 0; i < index; i++)
        current = current->next;

    *value = current->value;
    return 1;
}

// Delete the given list
//
// Python: del list
void list_delete(struct List* list)
{
    struct ListNode* current = list->first;

    while (current != NULL)
    {
        struct ListNode* previous = current;
        current = current->next;
        free(previous);
    }

    free(list);
}

// Print a human-readable representation of the given list
//
// Python: print(list)
void list_print(struct List* list)
{
    printf("[");

    struct ListNode* current = list->first;

    while (current != NULL)
    {
        printf("%d", current->value);

        // no comma after last value
        if (current->next != NULL)
            printf(", ");

        current = current->next;
    }

    printf("]\n");
}
// Python: del list[i]
int list_remove(struct List* list, int index)
{
	struct ListNode* current = list->first;
	
	if (index < 0 || index >= list_length(list))
		return 0;
		
	if (index == 0)
	{
		list->first = current->next;
		free(current);
	}
	else
	{
		for (int i = 0; i < index-1; i++)
			current = current->next;

		struct ListNode* previous = current->next;
		current->next = previous->next;
		free(previous);
	}

	return 1;
}

// Get the value of the last element and store it in the memory location pointed
// to by value. The last element is removed from the list. If the list is emtpy,
// 0 is returned, otherwise 1 is returned.
//
// Python: value = list.pop()
// (An IndexError would correspond to a return value of 0)
int list_pop(struct List* list, int* value)
{
	struct ListNode* current = list->first;
	if (current == NULL)
		return 0;
		
	int length = list_length(list);
		
    for (int i = 1; i < length-1; i++)
		current = current->next;
	
	struct ListNode* aftercurrent = current->next;
    *value = aftercurrent->value;
    current->next = NULL;
    free(aftercurrent);
    return 1;
}

// Prepend the value to the front of the list.
//
// Python: list.insert(0, value)
void list_prepend(struct List* list, int value)
{
	// create a new ListNode to store the value in
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;

    // if the list is empty, make the node the first node
    if (list->first == NULL)
        list->first = node;
    
    else
    {
        // place node at first place (list[0])
        struct ListNode* current = list->first;
        list->first = node;
        node->next = current;
    }
}

// Insert the element before the given index in the list. A negative index
// means the element should be added to the front (prepended). An index that
// is too high means the element should be added to the back (appended).
//
// Python: list.insert(index, value)
// (Note that the behavior for negative indices differs slightly in Python)
void list_insert(struct List* list, int index, int value)
{
	int length = list_length(list);
	
	// create a new ListNode to store the value in
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;

    // if the list is empty, make the node the first node
    if (list->first == NULL)
        list->first = node;
    
    else
    {
        struct ListNode* current = list->first;
        if (index == 0 || index < 0)
        {
			// place node at first place if index is negative or 0
			list->first = node;
			node->next = current;
		}
        else if (index > length-1)
        {
			// place node at last place if index is not in current list
			while (current->next != NULL)
				current = current->next;

			current->next = node;
		}
		else
		{
			// place node at requested index
			for (int i = 0; i < index-1; i++)
				current = current->next;

			struct ListNode* afternode = current->next;
			current->next = node;
			node->next = afternode;
		}
    }
}

// Insert the value at the correct position in a sorted list. Assume that the list
// is sorted from lowest to highest (ascending). The list must remain sorted!
void list_insert_sorted(struct List* list, int value)
{
	int length = list_length(list);
	
	// create a new ListNode to store the value in
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->value = value;
    node->next = NULL;

    // if the list is empty, make the node the first node
    if (list->first == NULL)
        list->first = node;
    
    
    else
    {
		// place node in sorted list (and keep the list sorted)
		struct ListNode* current = list->first;
		struct ListNode* previous = current;
		
		for (int i = 0; i < length-1; i++)
		{
			if (current->value > node->value)
			{
				list->first = node;
				node->next = current;
				break;
			}
			previous = current;
			current = current->next;
			if (current->value >= node->value)
			{
				previous->next = node;
				node->next = current;
				break;
			}
			if (current->next == NULL)
				current->next = node;			
		}	
	}
}

// remove all nodes with 'value'
void list_remove_all(struct List* list, int value)
{
	struct ListNode* current = list->first;
	
	while (current->value == value)
	{
		list->first = current->next;
		free(current);
		if (current->next != NULL)
			current = current->next;
	}
	
	struct ListNode* previous = current;
	while (current != NULL)
	{
		if (current->value == value)
		{
			previous->next = current->next;
			free(current);
		}
		else
			previous = current;
		
		current = current->next;
	}
}

// print list in reversed order
void list_print_reverse(struct List* list)
{
    reverse(list);
    list_print(list);
    reverse(list);
}

void reverse(struct List* list)
{
	struct ListNode* current = list->first;
	struct ListNode* previous = NULL;
	struct ListNode* currentafter;

    while (current != NULL) 
    {
        currentafter = current->next; 
        current->next = previous;  
        previous = current;
        current = currentafter;
    }
    list->first = previous;
}

