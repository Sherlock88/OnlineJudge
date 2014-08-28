#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define gc getchar_unlocked
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
	int T, B, LS, sqB, sqLS;
	float RSMin, RSMax;
	
	scanint(&T);
	while(T--)
	{
		scanint(&B);
		scanint(&LS);
		sqB = B * B;
		sqLS = LS * LS;
		RSMin = sqrtf(sqLS - sqB);
		RSMax = sqrtf(sqLS + sqB);
		printf("%f %f\n", RSMin, RSMax);
	}
	return 0;
}