#include <stdio.h>

int main()
{
	int a,b,c,d,e=1,x,y=1,z=1;
	printf("1024'ten kucuk bir sayi girin ");
	scanf("%d",&a);
	while(a/y!=1)
	{
		y*=2;
		z*=10;
	} 

	while(z>0)
	{
		d=a/y;
		x+=z*d;
		a-=y*d;
		z/=10;
		y/=2;
	}
	printf("\n%d",x);
	return 0;
}
