#include <stdio.h>


int f(int n)
{
	int T[n + 1], sum = 0, i;
	
	T[0] = T[1] = 2;
	for(i = 2; i <= n; i++)
	{
		sum += 2 * T[i - 1] * T[i - 2];
		T[i] = sum;
	}
	
	return sum;
}


int main()
{
	int n;
	
	printf("Enter n: ");
	scanf("%d", &n);
	printf("T: %d\n", f(n));
	return 0;
}