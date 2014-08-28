#include <algorithm>
#include <cstdio>

using namespace std;

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)

inline void scanintUL(unsigned long &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int main()
{
	unsigned long i, T, N[1000000];
	
	scanintUL(T);
	FOR(i, T) scanintUL(N[i]);
	sort(N, N + T);
	FOR(i, T) printf("%lu\n", N[i]);
	return 0;
}