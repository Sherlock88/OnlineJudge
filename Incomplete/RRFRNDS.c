#include <stdio.h>
#include <string.h>

#define NODECOUNT 2000
#define gc getchar_unlocked
#define FOR(I, N) for(i = 0; i < N; i++)

char a[NODECOUNT][NODECOUNT + 10];
int q[NODECOUNT],visited[NODECOUNT], f = 0, r = -1;


void bfs(int v, int N)
{
    int i;
	
	FOR(i, N)
        if(a[v][i] && !visited[i])
            q[++r]=i;
    if(f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++], N);
    }
}


int main()
{
    int i, j,  N;
	char s[5];
	
    scanf("%d ", &N);
	FOR(i, N)
	{
		fgets(a[i], N + 1, stdin);
		scanf("%[^\n]%*c", s);
	}
	
	/*for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
			printf("%c ", a[i][j]);
		printf("\n");
	}*/
	
    FOR(i, N) { q[i] = 0; visited[i] = 0; }
    FOR(i, N)
	{
		if(!visited[i])
		{
			f = 0, r = -1;
			printf("Picked: %d\n", i);
			bfs(i, N);
			printf("\n The node which are reachable are:\n");
			FOR(i, N)
				if(visited[i])
					printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}