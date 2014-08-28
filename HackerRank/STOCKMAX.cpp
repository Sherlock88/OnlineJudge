#include <cstdio>

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)


void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


void scanintLL(long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int main()
{
	int i, T, N, maxProfit, A[50000];
	long long profit;
	
	scanint(T);
	while(T--)
	{
		scanint(N);
		profit = 0;
		FOR(i, N) scanint(A[i]);
		maxProfit = A[N - 1];
		for(i = N - 2; i >=0; i--)
			if(A[i] > maxProfit)
				maxProfit = A[i];
			else
				profit += maxProfit - A[i];

		printf("%lld\n", profit);		
	}
	
	return 0;
}