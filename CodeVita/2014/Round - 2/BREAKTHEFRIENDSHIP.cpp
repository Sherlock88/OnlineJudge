#include <iostream>
#include <cstdio>
#include <queue>

#define FRIENDS 50
#define NOCOLOR -1

int connections[FRIENDS][FRIENDS];

using namespace std;

int isB(int connections[][FRIENDS])
{
    int c[FRIENDS], k, v, u;
	queue <int> qu;
	
	c[0] = 1;
	
    for(k = 1; k < FRIENDS; k++)
        c[k] = NOCOLOR;
 
    qu.push(0);
 
    while(!qu.empty())
    {
        u = qu.front();
        qu.pop();

        for(v = 0; v < FRIENDS; v++)
        {
            if(c[v] == NOCOLOR && connections[u][v])
            {
                c[v] = 1 - c[u];
                qu.push(v);
            }
 
            else
				if(c[v] == c[u] && connections[u][v])
					return 0;
        }
    }
 
    return 1;
}
 

int main()
{
    int N, M, k, i, j;
	scanf("%d %d", &N, &M);
	
	for(k = 0; k < M; k++)
	{
		scanf("%d %d", &i, &j);
		i--; j--;
		connections[i][j] = 1;
		connections[j][i] = 1;
	}

    isB(connections) ? printf("Yes\n") : printf("No\n");
    return 0;
}