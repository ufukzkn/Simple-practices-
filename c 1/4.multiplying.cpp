#include <stdio.h>

 int main()
 {
 	int a,b,c,a1;
	printf("carpmak icin iki sayi girin ");
	scanf("%d %d",&b,&a);
	c=b;
	if (a<0&&b>0){a1=a; a=-a;} 		//buna da negatif sonradan
	if (b<0&&a>0){a1=b; b=-b;}		//yine sadece ikinci sayý negatifse
 	while(a>1)
	 {
	 	b=b+c;
	 	a--;	 	
	 } if(a1<0) b=-b;				//
 	printf("%d",b);
 	return 0;
 }
