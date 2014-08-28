#include <stdio.h>

int main()
{
	char str[200001];
	int length, q, strPtr, substrPtr;
	
	scanf("%s%n", str, &length);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d", &substrPtr);
		strPtr = length - 1;
		substrPtr--;
		while((str[strPtr] == str[substrPtr]) && (substrPtr >= 0)) { strPtr--; substrPtr--;	}
		printf("%d\n", length - strPtr - 1);
	}
	return 0;
}