#include <stdio.h>

int main()
{
	long i,n,s=0,m=0,k,l;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%ld",&k);
		if(k==0)
		{
			l=i-s;
			s=i+1;
			if(l>m)	m=l;
		}
	}
	l=n-s;
	if(l>m)	m=l;
	printf("%ld",m);
	return 0;
}