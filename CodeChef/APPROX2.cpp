#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

#define gc getchar_unlocked

void scanintUS(unsigned short &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scanintUL(unsigned long &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

int main()
{
	unsigned short T, N, i, front, back, dupFront, dupBack;
	unsigned long K, n, pair;
	long absDiff, minDiff, absDiff2;
	vector<unsigned long> vtrNum;
	vtrNum.reserve(1000);
	
	scanintUS(T);
	while(T--)
	{
		scanintUS(N);
		scanintUL(K);
		vtrNum.clear();
		front = 0;
		back = N - 1;
		minDiff = 2000000001;
		pair = 0;
		
		for(i = 0; i < N; i++)
		{
			scanintUL(n);
			vtrNum.push_back(n);
		}
		
		sort(vtrNum.begin(), vtrNum.end());
		
		while((back - front) != 0)
		{
			absDiff = vtrNum[front] + vtrNum[back] - K;
			dupFront = 1; dupBack = 1;
			while((vtrNum[front] == vtrNum[front + 1]) && (front < back)) { front++; dupFront++; }
			
			absDiff2 = absDiff;
			
			if(dupFront > 1)
			{
				absDiff = vtrNum[front] + vtrNum[front - 1] - K;
				absDiff = (absDiff > 0) ? absDiff : -absDiff;
				if(absDiff < minDiff)
				{
					minDiff = absDiff;
					pair = dupFront * (dupFront - 1) / 2;
				}
				else
					if(absDiff == minDiff)
					{
						minDiff = absDiff;
						pair += dupFront * (dupFront - 1) / 2;
					}
			}
			
			if((back - front) == 0)
				break;
			while(vtrNum[back] == vtrNum[back - 1]) { back--; dupBack++; }
			
			if(dupBack > 1)
			{
				absDiff = vtrNum[back] + vtrNum[back + 1] - K;
				absDiff = (absDiff > 0) ? absDiff : -absDiff;
				if(absDiff < minDiff)
				{
					minDiff = absDiff;
					pair = dupBack * (dupBack - 1) / 2;
				}
				else
					if(absDiff == minDiff)
					{
						minDiff = absDiff;
						pair += dupBack * (dupBack - 1) / 2;
					}
			}
			
			absDiff = absDiff2;
			
			if(absDiff > 0)
				back--;
			else 
				if(absDiff < 0)
				{
					absDiff = -absDiff;
					front++;
				}
			if(absDiff < minDiff)
			{
				minDiff = absDiff;
				pair = dupFront * dupBack;
			}
			else
				if(absDiff == minDiff)
					pair += dupFront * dupBack;
			
			if(minDiff == 0)
				break;
		}
		printf("%lu %lu\n", minDiff, pair);
	}
	
	return 0;
}