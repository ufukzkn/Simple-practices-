#include <stdio.h>
int main()
{
	int a,b=1,d,x,y,z;
	scanf("%d",&a);
	x=a;
	while(a>=10)
	{
		a/=10;
		b++;
	} 
	while(b>0)
	{
		d=b;
		z=x%10;
		while(d>1){z*=10; d--;}
		y+=z;
		x/=10;
		b--;
	}
	printf("%d",y);
	
	
	
	
	return 0;
}
