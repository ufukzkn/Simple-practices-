#include <stdio.h>
int main()
{
	int x[100]={1,1,2,2,3,3,4,4,5,6,6,7,7,8,8,9,9};
	int n,i,i1=0,b;
	while(x[n]!='\0')n++;
	printf("mevcut array= ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n\ntekrar etmeyen sayilar= ");
	for(i=0;i<n;i++)
	{
		b=1;
		for(i1=0;i1<n;i1++)
			if (x[i]==x[i1]&&i!=i1) b++;
		if (b==1) printf("%d ",x[i]);
	} 	
	
	return 0;
}
