#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printl(int len, char hello[])
{
	for(int i = 0; i<=len; i++)
	{
		printf("%c\n", hello[i]);
	}
}

char* uppers(int len, char* hello[])
{
	char* HELLOstr = malloc(sizeof(char)*(len+1))
	int i;
	for(i = 0; i<=len; i++)
	{
		HELLOstr[i] = toupper(hello[i]);
		printf("%c\n", HELLOstr[i]);
	}
	HELLOstr[i]= '\0';
	return *HELLOstr;
}

int main()
{
   char hello[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
   printf("%s\n", hello);
   int len;
   len = strlen(hello);
   printf("%d\n", len);
   printl(len, hello);
   printf("%c\n", uppers(len, *hello));
   return 0;
}



