#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)


inline void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}


int main()
{
	int T, N, K, i, evens, n;
	
	scanint(&T);
	while(T--)
	{
		scanint(&N);
		scanint(&K);
		evens = 0;
		FOR(i, N)
		{
			scanint(&n);
			if(!(n & 0x00000001)) evens++;
		}
		if(K == 0 && evens == N)
			printf("NO\n");
		else
			if(K <= evens)
				printf("YES\n");
			else
				printf("NO\n");
	}
	return 0;
}