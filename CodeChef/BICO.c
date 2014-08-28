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


inline void scanintLL(long long *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}


inline void pascalTriangle(long long pascal[100][100])
{
	int i, j;
	long long fNum, sNum;
	
	FOR(i, 100) pascal[i][0] = pascal[i][i] = 1;
	FOR(i, 100)
	{
		for(j = 1; j <= ((i + 1) / 2); j++)
		{
			fNum = pascal[i - 1][j - 1];
			sNum = pascal[i - 1][j];
			if((fNum == -1) || (sNum == -1) || (sNum > (1000000000000 - fNum)))
				{ pascal[i][j] = -1; pascal[i][i - j] = -1; }
			else
				{ pascal[i][j] = fNum + sNum; pascal[i][i - j] = pascal[i][j]; }
		}
	}
}


int main()
{
	int T, R, C, i, numCoins;
	long long pascal[100][100], G, coins[50], coin;
	
	pascalTriangle(pascal);
	scanint(&T);
	while(T--)
	{
		scanint(&R);
		scanint(&C);
		scanintLL(&G);
		
		numCoins = 0;
		while(G > 0)
		{
			R = 99;
			while((pascal[R][C] > G) || (pascal[R][C] == -1)) R--;
			coin = pascal[R][C--];
			coins[numCoins++] = coin;
			G -= coin;
		}
		printf("%d\n", numCoins);
		FOR(i, numCoins) printf("%lld ", coins[i]);
		printf("\n");
	}
	return 0;
}