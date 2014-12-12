#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

// ==================== Stacks ====================

// Create an empty stack
struct Stack* stack_create()
{
	struct Stack* stack = malloc(sizeof(struct Stack));
	stack->top = NULL;
	return stack;
}

void stack_print(struct Stack* stack)
{
	printf("[");

	struct StackNode* current = stack->top;

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
			puts("note: if this is not the correct result pls use spaces in your formula");
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
		puts("#######################");
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
		printf("character = %s\n", character);
		val = atoi(character);
		
		if (val != 0)
		{
			stack_push(stack, val);
			stack_print(stack);
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
			stack_print(stack);
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

