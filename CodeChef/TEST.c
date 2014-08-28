#include <stdio.h>

int main()
{
	int i;
	do
	{
		scanf("%d", &i);
		if(i != 42)
			printf("%d\n", i);
		else
			return 0;
	}
	while(1);
	return 0;
}
				
