#include <stdio.h>

unsigned reverse(unsigned rev)
{
	unsigned reversed = 0;
	while(rev)
	{
		reversed = reversed*10 + rev%10;
		rev = rev/10;
	}
	return reversed;
}

int main()
{
	int n, i, a, b;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", reverse(reverse(a) + reverse(b)));
	}
	return 0;
}
				
