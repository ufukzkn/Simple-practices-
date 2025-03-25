#include <stdio.h>
int main()
{
	int a=2,b=2,c,x=100,y;
	while(x>0)
	{
		c=1;
		while(a-c>0)
			{
			if(a%(a-c)!=0)c++;
			else if(a%(a-c)==0&&a-c!=1)break;
			else if(a%(a-c)==0&&a-c==1){x--; y+=a; // sayilari gormek icin printf("%d\n",a); 
														break;}
			}
		a++;
	}
	printf("\n%d",y);

	
	return 0;
}
