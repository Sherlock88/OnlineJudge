#include <stdio.h>
#include <string.h>

int main()
{
	int T, alpha[27], i, len, isSup;
	char s[401];
	
	scanf("%d", &T);
	while(T--)
	{
		for(i = 1; i <= 27; i++) alpha[i] = 0;
		scanf("%s",s);
		len = strlen(s);
		for(i = 0; i < len; i++)
			alpha[s[i] - 96]++;
		
		isSup = 1;
		for(i = 1; i < 27; i++)
			if(alpha[i] != 0 && alpha[i] != i)
			{
				isSup = 0;
				break;
			}
			
		if(isSup)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}