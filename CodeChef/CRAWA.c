#include <stdio.h>
#include <stdlib.h>

#define gc getchar_unlocked


inline void scanint(int *x)
{
    register int c = gc();
    *x = 0;
    int neg = 0;
    for(;((c < 48 || c > 57) && c != '-'); c = gc());
    if(c == '-') { neg = 1; c = gc(); }
    for(; c > 47 && c < 58; c = gc()) { *x = ((*x) << 1) + ((*x) <<3 ) + c - 48; }
    if(neg) *x = -(*x);
}


inline int checkXSegment(int Y12, int X1, int X2, int X, int Y)
{
	if(X >= X1 && X <= X2 && Y == Y12)
		return 1;
	else
		return 0;
}


inline int checkYSegment(int X12, int Y1, int Y2, int X, int Y)
{
	if(Y >= Y1 && Y <= Y2 && X == X12)
		return 1;
	else
		return 0;
}


int main()
{
	int T, X, Y, isOily;
	
	scanint(&T);
	while(T--)
	{
		scanint(&X);
		scanint(&Y);
		isOily = 0;
		
		// 1st Quadrant
		if(X >= 0 && Y >= 0)
		{
			if(X == 0 && Y == 0)
				isOily = 1;
			else
				if(X & 0x0000001)	// X is Odd
					isOily = checkYSegment(X, 0, X + 1, X, Y);
				if(!(Y & 0x0000001) && !isOily)		// Y is Even
					isOily = checkXSegment(Y, 0, Y - 1, X, Y);
		}
		else
			// 2nd Quadrant
			if(X < 0 && Y > 0)
			{
				X = -X;
				if(!(X & 0x0000001))	// X is Even
					isOily = checkYSegment(X, 0, X, X, Y);
				if(!(Y & 0x0000001) && !isOily)		// Y is Even
					isOily = checkXSegment(Y, 0, Y, X, Y);
			}
			else
				// 3rd Quadrant
				if(X < 0 && Y <= 0)
				{
					X = -X;
					Y = -Y;
					if(!(X & 0x0000001))	// X is Even
						isOily = checkYSegment(X, 0, X, X, Y);
					if(!(Y & 0x0000001) && !isOily)		// Y is Even
						isOily = checkXSegment(Y, 0, Y, X, Y);
				}
				else
					// 4th Quadrant
					if(X >= 0 && Y < 0)
					{
						Y = -Y;
						if(X & 0x0000001)	// X is Odd
							isOily = checkYSegment(X, 0, X - 1, X, Y);
						if(!(Y & 0x0000001) && !isOily)		// Y is Even
							isOily = checkXSegment(Y, 0, Y + 1, X, Y);
					}
		
		if(isOily)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}