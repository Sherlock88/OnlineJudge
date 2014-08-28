#include <stdio.h>

int main()
{
	int i,j,n,t,pD,fNZ,nZ,pLen;
	char m[94],c,p;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		for(j=0;j<94;j++) m[j]=' '; 
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf(" %c %c",&c,&p);			// Method 1: Leading space makes scanf() skip whitespaces
			// scanf("%*[\r\n]");				// Method 2: * suppresses matching characters
			// scanf("%c",&c);if(c=='\r') scanf("%c",&c);	// Method 3: On Windows, \r precedes \n
			// scanf("%c %c",&c,&p);
			m[c-33]=p;
		}
		scanf("%*[\r\n]");
		fNZ=0;nZ=0;pD=-1;pLen=0;
		while(1)
		{
			scanf("%c",&c);if(c=='\r' || c=='\n') { if(!pLen) printf("0");break; }
			p=(m[c-33]==' ')?c:m[c-33];
			if(p=='.') { pD=0;continue; }
			if(pD==-1)	
				if(fNZ==0) 
					if(p=='0') continue; 
					else { fNZ=1;printf("%c",p);pLen=1; }
				else { printf("%c",p);pLen=1; }
			else
			if(pD==0) if(p=='0') nZ++; else { pD=1;printf("%c",'.');for(j=0;j<nZ;j++) printf("%c",'0');nZ=0;printf("%c",p);pLen=1; }
			else if(p=='0') { nZ++; } else { for(j=0;j<nZ;j++) printf("%c",'0');nZ=0;printf("%c",p);pLen=1; }
		}
		printf("\n");
	}
	return 0;
}