#include <stdio.h>

#define gc getchar_unlocked

void scanintUS(unsigned short *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

void scanintULL(unsigned long long *x)
{
    register int c = gc();
    *x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

int main()
{
	unsigned short T;
	unsigned long long flags, N;
	
	scanintUS(&T);
	while(T--)
	{
		scanintULL(&N);
		flags = 2*N*N*N*N - 7*N*N*N + 9*N*N - 4*N;
		printf("%llu\n", flags);
	}
	return 0;
}
