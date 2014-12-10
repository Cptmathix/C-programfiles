#include <stdlib.h>
#include <stdio.h>

#include "list.h"

// ==================== Dubbel Gelinkte Lijst ====================

// Create an empty list
//
// Python: list = []
struct DList* dlist_create()
{
	struct DList *dlist = malloc(sizeof(struct DList));
	dlist->first = NULL;
	dlist->last = NULL;
	dlist->length = 0;
	return dlist;
}

// Print a human-readable representation of the given list
//
// Python: print(list)
void dlist_print(struct DList* dlist)
{
	printf("[");

	struct DListNode* current = dlist->first;

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

// Delete the given list
//
// Python: del list
void dlist_delete(struct DList *dlist)
{
	struct DListNode* curr = dlist->first;

	while (curr != NULL) {
		struct DListNode* todel = curr;
		curr = curr->next;
		free(todel);
	}
	
	free(dlist);
}

// Print the elements of the list in reverse order. For example, if the list contains
// the numbers 3, 7, and 1, it should print "[1, 7, 3]\n".
//
// Python: print(list[::-1])
void dlist_print_reverse(struct DList* dlist)
{
	printf("[");

	struct DListNode* current = dlist->last;

	while (current != NULL)
	{
		printf("%d", current->value);

		// no comma after last value
		if (current->prev != NULL)
			printf(", ");

		current = current->prev;
	}

	printf("]\n");
}

// Return the length of the given list (i.e., the number of values in it)
//
// Python: length = len(list)
int dlist_length(struct DList* dlist)
{
	int length = dlist->length;
	return length;
}

// Get the value of the element at the given index and store it in the memory
// location pointed to by value. If the given index is out of range, 0 is
// returned, otherwise 1 is returned.
//
// Python: value = list[i]
// (An IndexError would correspond to a return value of 0)
int dlist_get(struct DList* dlist, int index, int* value)
{
	int length = dlist_length(dlist);
	
	if (index < 0 || index >= length)
        return 0;
	
	if (0 + index <= length - index)
	{
		struct DListNode* current = dlist->first;

		for (int i = 0; i < index; i++)
			current = current->next;

		*value = current->value;
	}
	else
	{
		struct DListNode* current = dlist->last;

		for (int i = length; i > index; i--)
			current = current->prev;

		*value = current->value;
	}
	return 1;
}

// Append the given value to the given list
//
// Python: list.append(value)
void dlist_append(struct DList* dlist, int value)
{
	// create a new DListNode to store the value in
    struct DListNode* node = malloc(sizeof(struct DListNode));
    node->value = value;
    node->prev = NULL;
    node->next = NULL;

    // if the list is empty, make the new node the first node
    if (dlist->first == NULL)
    {
        dlist->first = node;
        dlist->last = node;
        dlist->length = 1;
	}
    else
    {
        // find the last node and set the new node as its next node
        struct DListNode* current = dlist->last;

        current->next = node;
        node->prev = current;
        dlist->last = node;
        dlist->length += 1;
    }
}

// Insert the element before the given index in the list. A negative index
// means the element should be added to the front (prepended). An index that
// is too high means the element should be added to the back (appended).
//
// Python: list.insert(index, value)
// (Note that the behavior for negative indices differs slightly in Python)
void dlist_insert(struct DList* dlist, int index, int value)
{
	int length = dlist_length(dlist);
	
	// create a new ListNode to store the value in
    struct DListNode* node = malloc(sizeof(struct DListNode));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;

    // if the list is empty, make the node the first node
    if (dlist->first == NULL)
    {
        dlist->first = node;
        dlist->last = node;
        dlist->length = 1;
	}
    
    else
    {
        struct DListNode* currentf = dlist->first;
        struct DListNode* currentl = dlist->last;
        if (index == 0 || index < 0)
        {
			// place node at first place if index is negative or 0
			dlist->first = node;
			node->next = currentf;
			currentf->prev = node;
		}
        else if (index > length-1)
        {
			// place node at last place if index is not in current list
			dlist->last = node;
			node->prev = currentl;
			currentl->next = node;
		}
		else if(0 + index <= length - index)
		{
			// place node at requested index
			for (int i = 0; i < index-1; i++)
				currentf = currentf->next;

			struct DListNode* afternode = currentf->next;
			currentf->next = node;
			node->prev = currentf;
			node->next = afternode;
			afternode->prev = node;
		}
		else
		{
			// place node at requested index
			for (int i = length; i > index+1; i--)
				currentl = currentl->prev;

			struct DListNode* afternode = currentl->prev;
			currentl->prev = node;
			node->next = currentl;
			node->prev = afternode;
			afternode->next = node;
		}
		dlist->length += 1;
    }
}


// Remove the element at the given index from the given list. If the given index
// is out of range, 0 is returned, otherwise 1 is returned.
//
// Python: del list[i]
// (An IndexError would correspond to a return value of 0)
int dlist_remove(struct DList* dlist, int index)
{
	int length = dlist_length(dlist);
	struct DListNode* currentf = dlist->first;
	struct DListNode* currentl = dlist->last;
	
	if (index < 0 || index >= length)
		return 0;
		
	if (index == 0)
	{
		dlist->first = currentf->next;
		currentf->next->prev = NULL;
		free(currentf);
	}
	else if (index == length-1)
	{
		dlist->last = currentl->prev;
		currentl->prev->next = NULL;
		free(currentl);
	}
	else if (0 + index <= length - index)
	{
		printf("first\n");
		for (int i = 0; i < index-1; i++)
			currentf = currentf->next;

		struct DListNode* previous = currentf->next;
		currentf->next = previous->next;
		previous->next->prev = currentf;
		free(previous);
	}
	else
	{
		printf("last\n");
		for (int i = length; i > index+1; i--)
			currentl = currentl->prev;

		struct DListNode* previous = currentl->prev;
		currentl->prev = previous->prev;
		previous->prev->next = currentl;
		free(previous);
	}
	
	dlist->length -= 1;
	return 1;
}

