#include <stdio.h>
int main()
{
	int a,b=2,c,x=0,y;
	printf("bir pozitif sayi girin ");
	scanf("%d",&a);
	y=a;
	a--;
	while(a>=2)
	{
		c=1;
		while(a-c>0)
			{
			if(a%(a-c)!=0)c++;
			else if(a%(a-c)==0&&a-c!=1)break;
			else if(a%(a-c)==0&&a-c==1)
										{x++; //sayilari gormek icin printf("%d\n",a);
			 							c++;}
			}
		a--;
	}
	printf("\n%d'den kucuk %d tane asal sayi var",y,x);
	
	return 0;
}
