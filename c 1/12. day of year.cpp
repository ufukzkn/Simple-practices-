#include <stdio.h>
int main()
{
	int a,b,c,d;
	printf("gun ay yil olarak bir tarih giriniz ");
	scanf("%d %d %d",&a,&b,&c);
	if(a>30||b>12){printf("hatali giris"); return 0;}
	if (b==1) d=a;
	else d=(b-1)*30+a;
	printf("%d yilinin %d. gunu",c,d);
	
	
	
	
	return 0;
}
