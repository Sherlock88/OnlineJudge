#include <stdio.h>
#include <string.h>

int main()
{
	int T, alpha[27], i, len, deficit, extra, cost;
	char s[401];
	
	scanf("%d", &T);
	while(T--)
	{
		deficit = 0;
		extra = 0;
		cost = 0;
		
		for(i = 1; i <= 27; i++) alpha[i] = 0;
		scanf("%s",s);
		len = strlen(s);
		
		for(i = 0; i < len; i++)
			alpha[s[i] - 96]++;
		
		for(i = 1; i < 27; i++)
			if(alpha[i] != 0 && alpha[i] != i)
			{
				if(alpha[i] > i)
					extra += alpha[i] - i;
				else
					deficit += i - alpha[i];
			}
		
		if(deficit >= extra)
			cost = extra + (deficit - extra) * 2;
		else
			cost = deficit + (extra - deficit) * 3;
		
		printf("%d\n", cost);
	}
	return 0;
}