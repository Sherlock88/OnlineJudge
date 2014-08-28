#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked
#define DIFF(X, Y) ((X >= Y) ? (X - Y) : (Y - X))
#define FOR(I, N) for(i = 0; i < N; i++)

void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}

int main()
{
	int i, T, N, b, n, d1, d2, S;
	
	scanint(&T);
	while(T--)
	{
		scanint(&N);
		S = 0;
		scanint(&n);
		FOR(i, N-1)
		{
			scanint(&b);
			d1 = DIFF(1, n);
			d2 = DIFF(b, n);
			if(d1 > d2)
			{
				n = 1;
				S += d1;
			}
			else
			{
				n = b;
				S += d2;
			}
		}
		printf("%d\n", S);
	}
	return 0;
}