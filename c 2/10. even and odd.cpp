#include <stdio.h>
int main()
{
	int x[100],n,i;
	printf("kac tane deger olsun ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	printf("\ncift olanlar= ");
	for(i=0;i<n;i++)
	{
		if (x[i]%2==0) printf("%d  ",x[i]);
	}
	printf("\n tek olanlar= ");
	for(i=0;i<n;i++)
	{
		if (x[i]%2==1) printf("%d  ",x[i]);
	}
		
	return 0;
}
