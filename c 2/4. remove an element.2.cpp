#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,1,2,3,4},a,n=0,i,h;
	while(x[n]!='\0')n++;
	printf("mevcut array'de %d tane sayi var \nkacinci sayiyi sileceksin ",n);
	scanf("%d",&h);
	if (h>n){printf("hatali giris"); return 0;}
	printf("%d. sayi= %d \n yeni array= \t",h,x[h-1]);
	for(i=0;i<n;i++)
		if (i==h-1) while(x[i]!='\0'){x[i]=x[i+1]; i++;}

	for(i=0;x[i]!='\0';i++)
	printf("%d \t",x[i]);

	return 0;
}
