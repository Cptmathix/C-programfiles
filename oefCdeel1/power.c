#include <stdio.h>

int power(int a, int b)
{
	int result = 1;
	for(int i = 1; i<=b; i++)
	{
		result *= a;
	}
	return result;
}

int main()
{
	printf("%d\n", power(2, 4));
	return 0;
}


