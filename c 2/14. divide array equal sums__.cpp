#include <stdio.h>
int main()
{
	int x[100];
	int a,b,c=0,d,n=0,i,i1,i2;
	bool g=true;
	printf("bir array giriniz\narray'de kac tane deger olsun ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("%d. degeri gir ",i+1);
		scanf("%d",&x[i]);
	}
	printf("\nmevcut array= ");
	for(i=0;i<n;i++) printf("%d  ",x[i]);
	for(i=0;i<n;i++) c+=x[i];
	printf("\n%d tane sayi var",n);
	printf("\n\narray'i kac gruba bolmek istiyorsun (not: grup sayisi %d'den buyuk olamaz) ",n/2);
	scanf("%d",&a);
	b=n/a;
	for(i=0;i<a;i++)
	{	printf("%d. grup= ",i+1);
	d=0;
	i2=i*b;
		for(i1=0;i1<b;i1++,i2++)
			{
				printf("%d  ",x[i2]);
				d+=x[i2];
			}
					if (a*b!=n&&(i2+(n-(a*b)))==n) 
						for(;i2<n;i2++) 
							{
								printf("%d  ",x[i2]);
								d+=x[i2];
							}
		printf("\n");
		if (d!=c/a) g=false;
	}
	if (g) printf("\ntum gruplarin toplami esit");
	else printf("\ntum gruplarin toplami esit degil");
	return g;
}
