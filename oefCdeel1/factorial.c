#include <stdio.h>

int factorial(int n)
{
	int result = 0;

	while(n >= 0)
	{
		n--;
		result *= n;
	}
    
	return result;
}

int main()
{
	printf("factorial(3) = %d\n", factorial(3));
	return 0;
}
