/* http://technofrendzz.blogspot.in/2014/02/program-to-solve-maze-problem.html */

#include<stdio.h>

#define V 350                      /* size of matrix */
int N;

int isSafe(int x,int y,int G[V][V],int Sol[V][V])         /* to check the safe move */
{
    if(x>=0 && x<N && y>=0&&y<N && G[x][y]==1 && !Sol[x][y])
        return 1;
    else
        return 0;
}


int MazeRecur(int G[V][V], int Sol[V][V], int x,int y, int a, int b)   			/* checking for the path to our exit point */
{
    if(x==a && y==b)
    {
        Sol[x][y]=1;
        return 1;
    }
	
    if(isSafe(x,y,G,Sol)==1)
    {   
		Sol[x][y]=1;
        if(MazeRecur(G,Sol,x,y+1, a, b)==1)                                    /* right move possible */
            return 1;
        if(MazeRecur(G,Sol,x+1,y, a, b)==1)                                   /* down move possible */
            return 1;
        if(MazeRecur(G,Sol,x,y-1, a, b)==1)                                    /* left move possible  */
            return 1;
        if(MazeRecur(G,Sol,x-1,y, a, b)==1)                                   /* up move possible   */
            return 1;
        Sol[x][y]=0;
    }
    return 0;
}


int main()
{
	int i, j, k, G[V][V], Sol[V][V], R, firstX, firstY, X, Y, isReachable = 1;
	char cell;
	
	scanf(" %d ", &N);
	for(i = 0; i < N; i++)
		for(j = 0; j < N; j++)
		{
			scanf(" %c ", &cell);
			G[i][j] = (cell == 'O') ? 1 : 0;
		}
			
	scanf("%d", &R);
	scanf("%d %d", &firstX, &firstY);
	firstX--; firstY--;
	
	for(k = 1; k < R; k++)
	{
		scanf("%d %d", &X, &Y);
		X--; Y--;
		
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				Sol[i][j] = 0;
			
		if(MazeRecur(G,Sol,firstX,firstY,X,Y)==0)
		{
			isReachable = 0;
			break;
		}
	}
	
	if(isReachable)
		printf("Yes\n");
	else
		printf("No\n");
	
    /*if(MazeRecur(G,Sol,0,0,0,1)==1)
    {
        printf("Solution Exists\n");
        for(i=0; i<V; i++)
        {
            for(j=0; j<V; j++)
                printf("%d\t",sol[i][j]);
            printf("\n");
        }
    }
    else
        printf("No Solution Exists");*/

    return 0;
}
