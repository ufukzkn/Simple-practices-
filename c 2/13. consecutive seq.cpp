#include <stdio.h>
int main()
{
	int x[100],n,i,y=0,a,k,amax,max=0,son;
	printf("kac tane deger olsun ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++) 
	{
	a=0;
	if (x[i]==x[i+1]-1) k=i;
	while(x[i]==x[i+1]-1){ a++; i++; }
	if (a>amax) {amax=a; max=k; son=i;}
	}
	printf("\nen uzun ardisik seri=%d tane\n seri=",son-max+1);
	while(max!=son+1)
	{
		printf("%d ",x[max]);
		max++;
	}
	
	return 0;
}
