#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    strcpy(str, "1 2 - 5 - 15 5 / 5 + +");
    int length = strlen(str);
    str[length] = '\0';
    int result;
    
    if (evaluate(str, &result))
		printf("result = %i\n", result);
	else
		printf("error\n");

    return 0;
}
