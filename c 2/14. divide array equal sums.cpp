#include <stdio.h>
int main()
{	
	int x[100];
	int a,b,c=0,d,n=0,i,i1,k;
	bool g,g1=true;
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
	printf("\n\narray'i kac gruba bolmek istiyorsun ",n/2);
	scanf("%d",&a);
	int alt[a];
	if (c%a==0)
		{
			b=c/a;
			for(i=0;i<a;i++)
				alt[i]=0;
			for(i=0;i<n;i++)
			{
				for (i1=0;i1<a-1;i1++)
					if (alt[i1]+x[i]<=b) {alt[i1]+=x[i]; break;}
				if(i1==a){g=false; g1=false;}
			} 
			if (g1) g=true;
		}	
	else g=false;
	if(x[1]!=x[2]&&a==n) g=false;
	
	if (g) printf("toplami esit olan %d kumeye bolunebilir\n",a);
	else printf("toplami esit olan %d kumeye bolunemez",a);
	
	return g;
}



