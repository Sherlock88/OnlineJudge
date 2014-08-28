#include <stdio.h>

#define BUFSIZE 1000001

int main()
{
	unsigned long t;
	int length;
	char str[BUFSIZE];
	
	scanf("%lu ", &t);
	while(t--)
	{
		scanf(" %s%n ", str, &length);
		if(length & 0x00000001)
			printf("Odd - ");
		else
			printf("Even - ");
		printf("%s:%d\n", str, length);
	}
	return 0;
}