#include <stdio.h>

 int main()
 {
 	int a,b,c=1,d,e,f,g;
 	printf("iki sayi gir ");
 	scanf("%d",&a);
 	scanf("%d",&b);
 	d=a;
 	e=b;
	 
 	while (c!=0) 
	 {		
   		c=a%b;
   		printf("kalan %d\n",c);
		a=b;
   		b=c;
     }
 	printf("\nebob= %d\n",a);
 	f=d/a;
 	g=e/a;
 	printf("%d*%d=%d %d*%d=%d\n%d ile %d aralarinda asal",f,a,d,g,a,e,f,g);
 	
 	return 0;
 }
