#include <stdio.h>
int main()
{
	int a,b,c,c1,x,y=1,d=1,e=1,z,a1;
	printf("toplamak icin 2 ikili sayi girin ");
	scanf("%d %d",&a,&b);
	x=a;
	while(x>0){
				if(x%10!=0&&x%10!=1)
									{
									printf("ikili sayi girmediniz ya da sayi cok buyuk"); return 0;
									}
				else x/=10;
				}
	while(a>0)
	{
		c+=a%10*y;
		y*=2;
		a/=10;
	}
	x=b; y=1;
	while(x>0){
				if(x%10!=0&&x%10!=1)
									{
									printf("ikili sayi girmediniz ya da sayi cok buyuk"); return 0;
									}
				else x/=10;
				}
	while(b>0)
	{
		c1+=b%10*y;
		y*=2;
		b/=10;
	}
	z=c1+c-1; x=0; 
	while(d!=0)
	{
		d=z/2;
		c=z%2;
		z=d;
		a1+=c*e;
		e*=10;
	}
	printf("\n%d",a1);

	
	return 0;
}
