#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,23,35,5};
	int y[100]={5,31,42,11,83,69,18};
	int z[100];
	int a,n=0,n1=0,i;
	while(x[n]!='\0')n++;
	while(y[n1]!='\0')n1++;
	if(n1<n) n=n1;
	printf("   ilk array= ");
		for(i=0;i<n;i++) printf("%d ",x[i]);
	printf("\nikinci array= ");
		for(i=0;i<n1;i++) printf("%d ",y[i]);
	printf("\n\nkarsilikli olan verileri carpacagiz\n\n");
	for(i=0;i<n;i++)
		z[i]=x[i]*y[i];
	for(i=0;i<n;i++)
		printf("%d. carpim=%d\n",i+1,z[i]);
		
	return 0;
}
