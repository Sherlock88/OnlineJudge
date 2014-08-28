#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)


void scanint(unsigned long &x)
{
    register int c = gc();
    x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { x = (x << 1) + (x << 3) + c - 48; }
}


int main()
{
	unsigned long i, N, A[300000], f, s, x, y;
	
	scanint(N);
	FOR(i, N) scanint(A[i]);
	sort(A, A + N);
	
	f = A[N - 1];
	s = A[N - 2];
	x = log2(f);
	y = pow(2, x);
	
	//printf("%lu %lu %lu %lu\n", f, s, x, y);
	while(f == y && N > 2)
	{
		f = s;
		N--;
		s = A[N - 2];
		//printf("%lu %lu %lu\n", f, s, N);
		x = log2(f);
		y = pow(2, x);
	}
	printf("%lu\n", f & s);
	return 0;
}