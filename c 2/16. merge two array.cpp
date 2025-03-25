#include <stdio.h>
int main()
{
	int x[100]={12,24,36,48,60,72,84};
	int y[100]={5,10,15,20,25,30,35};
	int z[100],z1[100];
	int a,n1,n2=0,i,i1,b,c;
	while(x[n1]!='\0')n1++;
	while(y[n2]!='\0')n2++;
	printf("ilk array=    ");
	for(i=0;i<n1;i++)
		printf("%d \t",x[i]);
	printf("\n");
	printf("ikinci array= ");
	for(i=0;i<n2;i++)
		printf("%d \t",y[i]);
	
	for(i=0;i<n1;i++)
		z[i]=x[i];
	for(i=n1;i<n1+n2;i++)
		z[i]=y[i-n1];
	for(i=0;i<n1+n2;i++)
	{
		for(i1=0;i1<n1+n2;i1++)
			if (z[i1]>b){b=z[i1]; c=i1;}
		z1[i]=b;
		z[c]='\0';
		b=0;
	}
	printf("\n\nsirali son array= ");
	for(i=0;i<n1+n2;i++)
		printf("%d  ",z1[i]);
	
	
	return 0;
}
