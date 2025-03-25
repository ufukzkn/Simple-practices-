#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,23,35,86};
	int a,n,i,i1,b,c,k;
	while(x[n]!='\0')n++;
	printf("mevcut array=   ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\nen buyuk kac taneyi bulalim ");
	scanf("%d",&k);
	printf("\nen buyuk %d tanesi=  ",k);
	b=x[0];
	for(i=0;i<k;i++)
	{
		for(i1=0;i1<n;i1++)
			if (x[i1]>b){b=x[i1]; c=i1;}
		x[c]=0;
		printf("%d ",b);
		b=0;
	} 
	
	return 0;
}
