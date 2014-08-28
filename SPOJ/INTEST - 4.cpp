#include <stdio.h>

using namespace std;

#define BUF 65536

char ibuf[BUF];
int ipt = BUF;

int read_uint()
{
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}

	int n = 0;

	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF)
	{
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}


int main()
{
    int t=0,n,k,cnt=0;
    int c,j;
    n = read_uint();
	k = read_uint();
	while(n--)
	{
		t = read_uint();
		if(t%k == 0) cnt++; 
	}
    printf("%d",cnt);    
    return 0;
}