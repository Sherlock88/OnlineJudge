#include <stdio.h>

#define gc getchar_unlocked

void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {c=gc();}
    for(;c>47 && c<58;c = gc()) {*x = ((*x)<<1) + ((*x)<<3) + c - 48;}
}

int main()
{
	int x, y, d, e, T, step;
	
	scanint(&T);
	while(T--)
	{
		scanint(&x);
		scanint(&y);
		
		if(x > y)
		{
			step = y << 1;
			d = x - y;
			e = d >> 1;
			if(d & 0x00000001) e++;
		}
		else
		{
			step = x << 1;
			d = y - x;
			e = d >> 1;
		}
		e = e << 1;
		step += d + e;
		printf("%d\n", step);
	}
	return 0;
}