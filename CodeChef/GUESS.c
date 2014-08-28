#include <stdio.h>

int main()
{
	unsigned long t,i;
	unsigned long long m,n,z;
	scanf("%lu",&t);
	for(i=0;i<t;i++)
	{
		scanf("%llu %llu",&m,&n);
		if(!((m%2!=0) && (n%2!=0))) { printf("1/2\n"); continue; }
		z=m*n;
		printf("%llu/%llu\n",z/2,z);
	}
	return 0;
}