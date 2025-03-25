#include <stdio.h>
int main()
{
	int x[100]={1,1,2,2,2,2,3,4,5,6,6,7,8,8,9,9,9};
	int y[100];
	bool g=false;
	int a,n,i=0,i1=0,b;
	//counter'im '\0' (null) degeri ile calistigi icin array'de int karsiligi olan 0'i koyunca calismiyor
	while(x[n]!='\0')n++;
	printf("mevcut array= ");
	for(i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n\nhangi sayiyi silmek istiyorsunuz ");
	scanf("%d",&a);
	for(i=0;i<n;i++)
	{
		if (x[i]!=a) {y[i1]=x[i]; i1++;};
	}
	if (i1==n){printf("o sayi yok"); return 0;}
	printf("\nsilinmis hali= ");
	for(i=0;i<i1;i++)
		printf("%d ",y[i]);
	printf("\n\neski uzunluk=%d \nyeni uzunluk=%d",n,i1);
	return 0;
}
