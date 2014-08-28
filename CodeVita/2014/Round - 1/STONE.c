/* http://www.cs.umd.edu/~gordon/ysp/nim.pdf */

#include <stdio.h>

int main()
{
	int T, N, R;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		R = N % 5;
		if(R == 1 || R == 3 || R == 4)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}