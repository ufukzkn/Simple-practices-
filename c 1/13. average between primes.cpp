#include <stdio.h>
int main()
{
	int a,b=2,c,x=0,y,a1,a2;
	float son,x1,y1;
	printf("iki sayi girin ");
	scanf("%d %d",&a,&a1);
	if(a<a1)
	{
		a2=a1;
		a1=a;
		a=a2;		
	}
	a--;
	while(a>a1)
	{
		c=1;
		while(a-c>0)
			{
			if(a%(a-c)!=0)c++;
			else if(a%(a-c)==0&&a-c!=1)break;
			else if(a%(a-c)==0&&a-c==1)
										{x++; y+=a; //sayilari gormek icin printf("%d\n",a);
			 							c++;}
			}
		a--;
	}
	y1=y;
	x1=x;
	son=y1/x1;
	printf("\naralarindaki asallarin ortalamasi = %f",son);
	
	return 0;
}
