#include <stdio.h>
int main()
{
	int x[100]={1,2,3,4,5,6,7};
	int y[100]={1,2,3,4,5,6,7};
	int a,n1=0,n2=0,i,i1;
	bool e=true;
	while(x[n1]!='\0')n1++;
	while(y[n2]!='\0')n2++;
	
	printf("   ilk array= ");
		for(i=0;i<n1;i++) printf("%d ",x[i]);
	printf("\nikinci array= ");
		for(i=0;i<n2;i++) printf("%d ",y[i]);
	if (n1!=n2) {printf("\n\narrayler esit degil "); return 0;}
	for(i=0;i<n1;i++)
		if (x[i]!=y[i]) e=false;
	if (e) printf("\n\narrayler esit ");
	else printf("\n\narrayler esit degil ");

		
	return 0;
}
