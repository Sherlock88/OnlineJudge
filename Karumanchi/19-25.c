#include <stdio.h>


void displayMatrix(int M[20][100], int n, int T)
{
	int i, j;
	
	for(j = 0; j <= T; j++)
	{
		for(i = 0; i <= n; i++)
			printf("%d ", M[i][j]);
		printf("\n");
	}
}


int SubSetSum(int A[], int n, int T)
{
	int i, j, M[20][100];
	
	M[0][0] = 0;
	
	for(j = 1; j <= T; j++)
		M[0][j] = 0;
		
	for(i = 1; i <= n; i++)
		M[i][0] = 1;
	
	for(i = 1; i <= n; i++)
		for(j = 1; j <= T; j++)
			if(j >= A[i - 1])
				M[i][j] = M[i - 1][j] || M[i][j - A[i - 1]];
			else
				M[i][j] = M[i - 1][j];
	displayMatrix(M, n, T);
	return M[n][T];
}


int main()
{
	int A[] = {3, 2, 4, 19, 3, 7, 13, 10, 6, 11};
	printf("Exists: %d\n", SubSetSum(A, 10, 78));
	return 0;
}