#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "list.h"

// ==================== Enkelvoudige Gelinkte Lijst ====================

// Create an empty list
//
// Python: list = []
struct List* list_create()
{
	struct List* list = malloc(sizeof(struct List));
	list->first = NULL;
	return list;
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

// Get the value of the element at the given index and store it in the memory
// location pointed to by value. If the given index is out of range, 0 is
// returned, otherwise 1 is returned.
//
// Python: value = list[i]
// (An IndexError would correspond to a return value of 0)
int list_get(struct List* list, int index, int* value)
{
	struct ListNode* current = list->first;

	if (index < 0 || index >= list_length(list))
		return 0;

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

// Remove the element at the given index from the given list. If the given index
// is out of range, 0 is returned, otherwise 1 is returned.
//
// Python: del list[i]
// (An IndexError would correspond to a return value of 0)
int list_remove(struct List* list, int index)
{
	struct ListNode* current = list->first;
	
	if (index < 0 || index >= list_length(list))
		return 0;

	for (int i = 0; i < index-1; i++)
		current = current->next;

	struct ListNode* previous = current->next;
	current->next = previous->next;
	previous->next = NULL;
	free(previous);

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
	
	if (current->next == NULL)
	{
		free(current);
		list->first = NULL;
		return 1;
	}
	
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
	struct ListNode* current = list->first;
	
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

// Print the elements of the list in reverse order. For example, if the list contains
// the numbers 3, 7, and 1, it should print "[1, 7, 3]\n".
//
// Python: print(list[::-1])
void list_print_reverse(struct List* list)
{
	printf("[");
	
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
	
	current = list->first;
	while (current != NULL)		
	{
        printf("%d", current->value);

        // no comma after last value
        if (current->next != NULL)
            printf(", ");

        current = current->next;
    }

    printf("]\n");
    
    current = list->first;
    previous = NULL;
    while (current != NULL) 
    {
        currentafter = current->next; 
        current->next = previous;  
        previous = current;
        current = currentafter;
    }
    list->first = previous;
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
		for (int i = 0; i < index-1; i++)
			currentf = currentf->next;

		struct DListNode* previous = currentf->next;
		currentf->next = previous->next;
		previous->next->prev = currentf;
		free(previous);
	}
	else
	{
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


// ==================== Stacks ====================

// Create an empty stack
struct Stack* stack_create()
{
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->top = NULL;
	return stack;
}

// Push a new element on the stack
void stack_push(struct Stack* stack, int x)
{
	// create a new StackNode to store the value in
	struct StackNode* node = malloc(sizeof(struct StackNode));
	node->value = x;
	node->next = NULL;

	// if the stack is empty, make the new node the first node
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		struct StackNode* current = stack->top;
		node->next = current;
		stack->top = node;
	}
}

// Get the value of the last added element to the stack and store it in the
// memory location pointed to by value. If the stack is empty, 0 is returned,
// otherwise 1 is returned.
int stack_pop(struct Stack* stack, int *value)
{
	if (stack_isempty(stack))
		return 0;
	
	struct StackNode* current = stack->top;
	*value = current->value;
	stack->top = current->next;
    free(current);
    return 1;
}

// Returns 1 if the stack is empty (i.e. there are no elements to pop).
// Otherwise it returns 0.
int stack_isempty(struct Stack* stack)
{
	struct StackNode* current = stack->top;
	if (current == NULL)
		return 1;
	return 0;
}

// Delete the given stack
void stack_delete(struct Stack* stack)
{
	struct StackNode* current = stack->top;

	while (current != NULL)
	{
		struct StackNode* previous = current;
		current = current->next;
		free(previous);
	}

	free(stack);
}


// Evaluate the postfix expression given in parameter `formula`.
//
// Returns 0 if formula is an invalid postfix expression, and 1 if it is a valid
// postfix expression. The result is returned using the pointer `result`.
int evaluate(char* formula, int* result)
{
	int length = strlen(formula);
	
	if (length == 0)
	{
		puts("error: empty formula");
		return 0;
	}
	
	int val;
    char *pstr = formula;
    char character[10];
    
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->top = NULL;
	
	int check = 0;
	for (int i = 0; i < length && check != 1; i++)
	{
		strncpy(character, pstr, 1);
		if (character[0] == ' ')
			check = 1;
		else if (i+1 == length)
		{
			*result = atoi(formula);
			stack_delete(stack);
			return 1;
		}
		else
			pstr++;
    }
    
    pstr = formula;
    for (int i = 0; i < length; i++)
    {
		strncpy(character, pstr, 1);
		if (character[0] == '\0')
			break;
		int count;
		for (int x = 1; x != length; x++)
		{
			strncpy(character, pstr, 1);
			character[1] = '\0';
			if (character[0] == ' ') 
			{
				count = x;
				pstr -= count-1;
				break;
			}
			else
			{
				strncpy(character, pstr, 2);
				character[2] = '\0';
				if (character[1] == '\0')
				{
					count = x;
					pstr -= count-1;
					break;
				}
				pstr++;
			}
		}
		strncpy(character, pstr, count);
		pstr += count;
		character[count++] = '\0';
		val = atoi(character);
		
		if (val != 0)
		{
			stack_push(stack, val);
		}
		else
		{
			int value1;
			int value2;
			if (character[0] == '*')
			{
				if (stack_pop(stack, &value1) && stack_pop(stack, &value2))
					stack_push(stack, value1*value2);
				else
				{
					puts("error: incorrect formula");
					return 0;
				}
			}
			else if (character[0] == '/')
			{
				if (stack_pop(stack, &value1) && stack_pop(stack, &value2))
				{
					if (value1 != 0)
						stack_push(stack, value2/value1);
					else
					{
						puts("error: divide by zero");
						return 0;
					}
				}
				else 
				{
					puts("error: incorrect formula");
					return 0;
				};
			}
			else if (character[0] == '+')
			{
				if (stack_pop(stack, &value1) && stack_pop(stack, &value2))
					stack_push(stack, value1+value2);
				else
				{
					puts("error: incorrect formula");
					return 0;
				}
			}
			else
			{
				if (stack_pop(stack, &value1) && stack_pop(stack, &value2))
					stack_push(stack, value2-value1);
				else
				{
					puts("error: incorrect formula");
					return 0;
				}
			}
		}
	}
	stack_pop(stack, result);
	int empty;
	if (stack_pop(stack, &empty))
	{
		stack_delete(stack);
		puts("error: incorrect formula");
		return 0;
	}
	else
	{
		stack_delete(stack);
		return 1;
	}
}
