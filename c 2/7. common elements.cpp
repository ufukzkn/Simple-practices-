#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,23,35};
	int y[100]={5,31,42,11,83,69,18};
	int a,n,n1=0,i,i1;

	while(x[n]!='\0')n++;
	while(y[n1]!='\0')n1++;
		printf("  ilk array: ");
			for(i=0;i<n;i++) printf("%d  ",x[i]);
		printf("\nikinci array: ");
			for(i1=0;i1<n1;i1++) printf("%d  ",y[i1]);
	for(i=0;i<n;i++)
		for(i1=0;i1<n;i1++) 	if(x[i]==x[i1]&&i!=i1) x[i1]='\0';
	printf("\n\nortak olan sayilar= ");
	for(i=0;i<n;i++)
		for(i1=0;i1<n1;i1++)	if(x[i]==y[i1]) {printf("%d \t",x[i]); x[i]='\0'; }

	return 0;
}
