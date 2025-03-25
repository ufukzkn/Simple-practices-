#include <stdio.h>
int main()
{
	int x[100],a,n,i,b,c=1;
	printf("kac tane deger olsun ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	b=x[0];
	for(i=0;i<n;i++)
		if (x[i]>b){b=x[i]; c=i+1;}
	printf("\n %d. sayi %d olarak en buyuk",c,b);
		
	return 0;
}
