#include <stdio.h>

int power(int a, int b)
{
	int result = 1;
	int i = 1;
	while (i<=b)
	{
		result *= a;
		i++;
	}
	return result;
}

int main()
{
	printf("%d\n", power(2, 4));
	return 0;
}


