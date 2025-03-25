#include <stdio.h>
int main()
{
	int a,b=10,c,d,x,y;
	scanf("%d",&a);
	x=a;
	while(a>=10)
	{
		a/=10;
		b*=10;
	} 
	c=b*x+x;
	d=b*c+x;
	y=x+c+d;


	printf("%d + %d + %d = %d",x,c,d,y);
	return 0;
}
