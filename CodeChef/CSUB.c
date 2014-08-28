#include <stdio.h>

#define BUFSIZE 100001

int main()
{
	char s[BUFSIZE];
	int T, N, i;
	unsigned long long countOne;
	
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		scanf("%s", s);
		countOne = 0;
		for(i = 0; i < N; i++)
			if(s[i] == '1')
				countOne++;
		countOne = countOne * (countOne + 1) /2;
		printf("%llu\n", countOne);
	}
	return 0;
}

