#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked
#define V 20                      /* size of matrix */

int paths = 0;

inline void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    for(;(c < 48 || c > 57); c = gc());
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
}


inline int isSafe(int N, int x,int y,int G[V][V],int Sol[V][V])         /* to check the safe move */
{
    if(x>=0 && y>=0 && !G[x][y] && !Sol[x][y])
        return 1;
    else
        return 0;
}


inline int MazeRecur(int N, int G[V][V], int Sol[V][V], int x, int y, int a, int b)   			/* checking for the path to our exit point */
{	
    if(isSafe(N,x,y,G,Sol))
    {   
		if(x==a && y==b)
		{
			Sol[x][y]=1;
			paths++;
			Sol[x][y]=0;
			return 1;
		}
		
		Sol[x][y]=1;
        MazeRecur(N,G,Sol,x,y+1, a, b);                                   /* right move possible */
        MazeRecur(N,G,Sol,x+1,y, a, b);                                   /* down move possible */
        MazeRecur(N,G,Sol,x,y-1, a, b);                                   /* left move possible */
        MazeRecur(N,G,Sol,x-1,y, a, b);                                   /* up move possible */
        Sol[x][y]=0;
    }
    return 0;
}


int main()
{
	int N, i, j, G[V][V], Sol[V][V];
	
	scanint(&N);
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			scanint(&G[i][j]);	
		
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
			Sol[i][j] = 0;

	MazeRecur(N, G, Sol, 0, 0, N-1, N-1);
	printf("%d\n", paths);

    return 0;
}
