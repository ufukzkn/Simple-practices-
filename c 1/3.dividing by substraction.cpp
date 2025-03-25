#include <stdio.h>
int main()
{
	int a,b,c,d=0,b1,a1;
	printf("bolmek icin iki sayi girin ");
	scanf("%d %d",&b,&a);
	if (a>b) 
	{
	c=b;
	b=a;
	a=c;	
	} b1=b; 
	a1=a; if (a<0) a=-a; 		//negatif sonradan ekledim zorlama biraz 
	while(a<=b)					//sadece 2. sayý negatifse çalýþýyor
	{
		b=b-a;
		d++;
	}
	if (a1<0) {d=-d;}		//
	printf("%d %d'ye bolumu %d yapar kalan=%d",b1,a1,d,b);
	
	
	return 0;
}
