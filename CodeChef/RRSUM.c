#include <stdio.h>

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)


void scanint(unsigned long *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}

int main()
{
	unsigned long M, N, q, Min, Max, Mid, c;
	
	scanint(&N);
	scanint(&M);
	Min = N + 2;
	Max = 3 * N;
	Mid = 2 * N + 1;
	while(M--)
	{
		scanint(&q);
		if(q < Min)
			c = 0;
		else
			if(q <= Mid)
				c = q - Min + 1;
			else
				c = Max - q + 1;
		printf("%lu\n", c);
	}
	return 0;
}