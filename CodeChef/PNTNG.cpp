#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

#define gc getchar_unlocked

using namespace std;

void scanintposull(unsigned long long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scanintposul(unsigned long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

class Pair
{	
	public:
	unsigned long long T;
	unsigned long C;
	
	Pair(unsigned long long T, unsigned long C) { this->T = T; this->C = C; }
};

bool compPair(Pair* p, Pair* q)
{
	return (p->C < q->C);
}

int main()
{
	unsigned long long N, M, T, Cost = 0, gridSize;
	unsigned long H, C, k;
	Pair* p;
	vector<Pair*> myPair;
	myPair.reserve(100000);
	
	scanintposull(N);
	scanintposull(M);
	scanintposul(H);
	gridSize = N * M;
	
	for(k = 0; k < H; k++)
	{
		scanintposull(T);
		scanintposul(C);
		myPair.push_back(new Pair(T, C));
	}
	
	sort(myPair.begin(), myPair.end(), compPair);
	
	k = 0;
	do
	{
		p = myPair[k];
		if(gridSize >= p->T)
		{
			Cost += p->T * p->C;
			gridSize -= p->T;
		}
		else
		{
			Cost += gridSize * p->C;
			gridSize = 0;
		}
		k++;
	}
	while((gridSize > 0) && (k < H));
	
	if(gridSize == 0)
		cout << Cost;
	else
		cout << "Impossible";

	return 0;
}