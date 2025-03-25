#include <stdio.h>
int main()
{
	int x[100],n,i,y=0;
	printf("kac tane deger olsun ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	for(i=0;i<n;i++) y+=x[i];
	printf("\n\nortalamadan buyuk olanlar= ");
	for(i=0;i<n;i++) if (x[i]>y/n) printf("%d  ",x[i]);
	
	return 0;
}
