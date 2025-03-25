#include <stdio.h>
int main()
{
	int a,c,x,y=1;
	printf("ikili sayi girin ");
	scanf("%d",&a);
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
	printf("\nonluk sistemde = %d",c);
	return 0;
}
