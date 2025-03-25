#include <stdio.h>
int main()
{
	int a;
	printf("bes basamakli bir sayi girin ");
	scanf("%d",&a);
	if (a>=100000||a<10000) {printf("sayi bes basamakli degil"); return 0;}
	while (a>1000)
	{
		a/=10;
	}	printf("%d",a%10);
	return 0;
}
