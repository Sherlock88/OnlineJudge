#include <stdio.h>

int main()
{
	int t;
	unsigned long long a, b, c, n, f, d, i;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%llu%llu%llu", &a, &b, &c);
		n = 2 * c / (a + b);
		f = a - 2 * ((b - a) / (n - 5));
		d = (b - a) / (n - 5);
		printf("%llu\n", n);
		for(i = 0; i < n; i++)
		{
			printf("%llu ", f);
			f += d;
		}
	}
	return 0;
}