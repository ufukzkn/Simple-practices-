#include <stdio.h>
int main()
{
	int a,b,c,d=100000,e;
	printf("pozitif sayi girin ");
	scanf("%d",&a);
	while(d<a) d*=10;
	e=a%10;
	while(a>10)
	{
		c=a/d;
		e=e+c%10;
		d=d/10;
		if (d<10) break;
	}		while (e>=10)
					{
						e=e/100+e/10+e%10;		
					}
	printf("%d",e);	
	
	
	return 0;
}
