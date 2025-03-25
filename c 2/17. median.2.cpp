#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,23,35,86};
	int a,n,i,i1,b,c,med,d,d1;
	while(x[n]!='\0')n++;
	printf("ilk array=   ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	for(i=1;i<n;i++)
		for(i1=0;i1<n;i1++)
			if(x[i]<x[i1])
			{
	  		c=x[i];
	  		x[i]=x[i1];
	  		x[i1]=c;
			}
	printf("\n\nsirali hali= ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	if (n%2==0) 
	{
	d=(n-2)/2; d1=n/2;
	med=(x[d]+x[d1])/2;
	printf("\n\nmedian= (%d+%d)/2= %d",x[d],x[d1],med);
	}
	else 
	{
	med=x[(n-1)/2]; 
	printf("\n\nmedian= %d",med);
	}
	return 0;
}
