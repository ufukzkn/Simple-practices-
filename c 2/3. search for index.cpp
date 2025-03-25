#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,35,89,62},a,n,i,c=1,h;
	bool g=false;
	printf("mevcut array'de hangi sayiyi arayacaksin ");
	scanf("%d",&h);
	while(x[n]!='\0')n++;
	for(i=0;i<n;i++)
		if (x[i]==h){g=true; c=i+1;}
	
	if (g) printf("%d sayisi %d. veri \n",h,c);
	else printf("o sayi yokmus ya \n");
	for(i=0;i<n;i++)
	printf(" %d \t",x[i]);
		
	return 0;
}
