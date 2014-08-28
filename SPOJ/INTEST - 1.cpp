/*
* http://abhisharlives.blogspot.in/2012/06/really-fast-io-methods-for-programming.html
* http://www.spoj.pl/problems/INTEST
* http://www.spoj.pl/problems/INOUTEST
*/

#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int cnt=0;
	while(n--)
	{
		int num;
		scanf("%d",&num);
		if(num%k==0)cnt++; 
	}    
	printf("%d",cnt);
	return 0;
}