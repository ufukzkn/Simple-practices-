#include <stdio.h>
int main()
{
	int x[100],y[100],a,n,n1,i,c=1;
	printf("array'i tersine cevircez \nkac tane deger olsun ");
	scanf("%d",&n);
	n1=n;
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++,n1--)
		y[i]=x[n1-1];
	printf("\n kendisi= ");
	for(i=0;i<n;i++)
	printf(" %d \t",x[i]);
	printf("\n   tersi= ");
	for(i=0;i<n;i++)
	printf(" %d \t",y[i]);
		
	return 0;
}
