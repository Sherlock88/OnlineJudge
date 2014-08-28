#include <iostream>
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

struct Pair
{
	int index, Xval;
};

int compPair(Pair* a, Pair* b)
{
	return (a->Xval < b->Xval);
}

int main()
{
	int N, K, P, A, B, t, i, curIndex, toIndex, curPos;
	Pair* pos[100000];
	int posToIndex[100000], nextDeadEnd[100000], lastDeadEnd;
	bool canSend, isNextReachable[100000];
	
	scanint(N);
	scanint(K);
	scanint(P);
	FOR(i, N) { pos[i] = new Pair(); pos[i]->index = i; scanint(pos[i]->Xval); }
	sort(pos, pos + N, compPair);
	FOR(i, N) posToIndex[pos[i]->index] = i;
	
	lastDeadEnd = N - 1;
	nextDeadEnd[N - 1] = N - 1;
	for(i = N - 2; i >= 0; i--)
	{
		if((pos[i + 1]->Xval - pos[i]->Xval) > K)
			lastDeadEnd = i;
		nextDeadEnd[i] = lastDeadEnd;
	}
	
	while(P--)
	{
		scanint(A);
		scanint(B);
		
		A = posToIndex[A - 1];
		B = posToIndex[B - 1];
		if(B < A) { t = A; A = B; B = t; }
		
		canSend = true;
		for(i = A; i < B; i++)
		{
			if(nextDeadEnd[A] < B)
			{
				canSend = false;
				break;
			}
		}

		if(canSend)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}