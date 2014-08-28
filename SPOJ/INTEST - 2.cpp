/*
* http://abhisharlives.blogspot.in/2012/06/really-fast-io-methods-for-programming.html
* http://www.spoj.pl/problems/INTEST
* http://www.spoj.pl/problems/INOUTEST
*/

#include <iostream>
#include <cstdio>

#define gc getchar_unlocked

void scanintpos(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main()
{   

    int n,k;
    scanint(n);
    scanint(k);
    int cnt=0;
    while(n--)
    {
		int num;
		scanint(num);
		if(num%k==0)cnt++; 
    }    
    printf("%d",cnt);
    return 0;             
}