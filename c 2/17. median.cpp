#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,23,35,86};
	int y[100];
	int a,n,i,i1,b,c,med,d,d1;
	while(x[n]!='\0')n++;
	printf("ilk array=   ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	for(i=0;i<n;i++)
	{
		for(i1=0;i1<n;i1++)
			if (x[i1]>b){b=x[i1]; c=i1;}
		y[i]=b;
		x[c]=0;
		b=0;
	} printf("\n\nsirali hali= ");
	for(i=0;i<n;i++)
		printf("%d ",y[i]);
	if (n%2==0) 
	{
	d=(n-2)/2; d1=n/2;
	med=(y[d]+y[d1])/2;
	printf("\n\nmedian= (%d+%d)/2= %d",y[d],y[d1],med);
	}
	else 
	{
	med=y[(n-1)/2]; 
	printf("\n\nmedian= %d",med);
	}
	return 0;
}
