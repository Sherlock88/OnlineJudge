#include <stdio.h>
#include <string.h>

#define gc getchar_unlocked


inline void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}


int main()
{
	int n, DP[1001], T, N, K, i, j, diff;
	
	scanint(&T);
	while(T--)
	{
		scanint(&N);
		scanint(&K);
		memset(DP, 0, sizeof(DP));
		DP[0] = 1;
		
		for(i = 0; i < N; i++)
		{
			scanint(&n);
			if(n <= K && !DP[K])
			{
				diff = K - n;
				for(j = diff; j >= 0 && !DP[K]; j--)
					if(DP[j] && (j <= diff))
						DP[j + n] = 1;
			}
		}
		printf("%d\n", DP[K]) ;
	}
	return 0;
}