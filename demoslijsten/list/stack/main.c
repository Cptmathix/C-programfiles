#include "list.h"

#include <stdio.h>

int main()
{
    struct Stack* stack = stack_create();
	stack_print(stack);
	stack_push(stack, 5);
	stack_print(stack);
	
	int value;
	if (stack_pop(stack, &value))
		printf("pop = %i\n", value);
	else
		puts("stack is empty");
	stack_print(stack);
	
	stack_delete(stack);
    return 0;
}
