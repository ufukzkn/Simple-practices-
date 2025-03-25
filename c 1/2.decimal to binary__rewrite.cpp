#include <stdio.h>

int main()
{
	int a,b,c,d=1,e=1,x;
	printf("1024'ten kucuk bir sayi girin ");
	scanf("%d",&a);
	while(d!=0)
	{
		d=a/2;
		c=a%2;
		a=d;
		x+=c*e;
		e*=10;
	}
	printf("\n%d",x);
	return 0;
}
