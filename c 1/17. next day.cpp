#include <stdio.h>
int main()
{
	int a,b,c;
	printf("gunu girin ");
	scanf("%d",&a);
	if (a>30){printf("hatali giris"); return 0;}
	printf("ayi girin ");
	scanf("%d",&b);
	if (b>12){printf("hatali giris"); return 0;}
	printf("yili girin ");
	scanf("%d",&c);
	if (a<=30)a++;
	if (a==31){a=a-30; b++;}
	if (b==13){c++; b=1;}
	printf("ertesi gun %d.%d.%d",a,b,c);
	
	return 0;
}
