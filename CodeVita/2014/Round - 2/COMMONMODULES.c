#include <stdio.h>
#include <stdlib.h>


int main()
{
	int N, M, Q, u, v, i, j, k, change = 1, common[50] = {0}, Modules[51][51] = {{0}}, commonDependency, isCommon;
		
	scanf("%d %d", &N, &M);
	
	for(i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		Modules[u][v] = 1;
	}
	
	while(change)
	{
		change = 0;
		
		for(i = 1; i <= N; i++)
		{
			for(j = 1; j <= N; j++)
				if(Modules[i][j])
				{
					for(k = 1; k <= N; k++)
						if(!Modules[i][k] && Modules[j][k])
						{
							Modules[i][k] = 1;
							change = 1;
						}
				}
		}
	}
	
	scanf("%d", &Q);
	for(i = 0; i < Q; i++)
		scanf("%d" ,&common[i]);
	
	/*for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= N; j++)
			printf("%d ", Modules[i][j]);
		printf("\n");
	}*/
	
	isCommon = 0;
	for(i = 1; i <= N; i++)
	{
		commonDependency = 1;
		for(j = 0; j < Q; j++)
			if(!Modules[common[j]][i])
			{
				commonDependency = 0;
				break;
			}
		if(commonDependency)
		{
			printf("%d ", i);
			isCommon = 1;
		}
	}
	if(!isCommon)
		printf("-1");
	printf("\n");
	
	return 0;
}