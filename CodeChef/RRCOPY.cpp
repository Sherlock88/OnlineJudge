#include <algorithm>
#include <cstdio>

using namespace std;

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int main()
{
	int T, N, i, j,  A[100000];
	
	scanint(T);
	while(T--)
	{
		scanint(N);
		FOR(i, N) scanint(A[i]);
		sort(A, A + N);
		j = 0;
		for(i = 1; i < N; i++) if(A[i] != A[j]) A[++j] = A[i];
		printf("%d\n", ++j);		
	}
	return 0;
}