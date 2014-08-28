#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked
#define ABS(X) ((X > 0) ? X : -X))
#define DIFF(X, Y) ((X >= Y) ? (X - Y) : (Y - X))
#define MIN(X, Y) ((X > Y) ? Y : X))
#define FOR(I, N) for(i = 0; i < N; i++)

void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    int neg = 0;
    for(;((c < 48 || c > 57) && c != '-'); c = gc());
    if(c == '-') { neg = 1; c = gc(); }
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
    if(neg) *x = -(*x);
}

void scanintUL(unsigned long *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}

int main()
{
	int T;
	
	scanint(&T);
	while(T--)
	{
	}
	return 0;
}