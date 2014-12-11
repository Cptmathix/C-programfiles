#include "list.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    strcpy(str, "70 -7 + -");
    int length = strlen(str);
    str[length] = '\0';
    int result;
    if (evaluate(str, &result))
		printf("result = %i\n", result);
	else
		printf("an error occurred, couldn't get a result.\n");

    return 0;
}
