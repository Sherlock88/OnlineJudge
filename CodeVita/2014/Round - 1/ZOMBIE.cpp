#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

int main()
{
	int K,N,T,E[50],P,D,i;
	scanf("%d",&K);
	while(K--)
	{
		scanf("%d %d",&N,&T);
		for(i=0;i<N;i++)
			scanf("%d",&E[i]);
		sort(E,E+N);
		scanf("%d %d",&P,&D);

		for(i=0;i<N;i++)
		{
			if(P>=E[i])
				P=P+(P - E[i]);
			if((i+1)<=T)
			{
				if(P>=D)
				{
					printf("Yes\n");
					break;
				}
			}
			else
			{
				printf("No\n");
				break;
			}
		}
	}
	return 0;
}