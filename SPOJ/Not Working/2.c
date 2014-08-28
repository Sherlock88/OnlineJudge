#include <stdio.h>
#include <math.h>

int isPrime(unsigned n)
{
	int i;
	if(n==1)
		return 0;
	for(i = 2; i <= sqrt(n); i++)
		if(!(n%i))
			return 0;
	return 1;
}


int main()
{
	int t, m, n, i, j;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		scanf("%d%d",  &m, &n);
		for(j = m; j <= n; j++)
			if(isPrime(j))
				printf("%d\n", j);
		printf("\n");
	}
	return 0;
}