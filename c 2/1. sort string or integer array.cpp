#include <stdio.h>
#include <string.h>
int main()
{
	char secim,cs,xs[100],xs1[100][100];
	int x[100];
	int a,i,i1,n,ci;
	printf("siralamak istediginiz array tipini secin \n\n1-integer(sayi)\n2-string(harf)\n3-string(kelime)\n\n");
	scanf(" %c",&secim);
	switch (secim)
	{
		case '1':
		printf("array'de kac tane deger olsun ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("%d. degeri gir ",i+1);
			scanf("%d",&x[i]);
		}
		printf("\nilk array=   ");
		for(i=0;i<n;i++)
			printf("%d ",x[i]);
		for(i=1;i<n;i++)
			for(i1=0;i1<n;i1++)
				if(x[i]<x[i1])
				{
		  		ci=x[i];
		  		x[i]=x[i1];
		  		x[i1]=ci;
				}
		printf("\n\nsirali hali= ");
		for(i=0;i<n;i++)
			printf("%d ",x[i]);
		break;
		
		case '2':
		printf("bir string array girin ");
		fflush(stdin); 
		//gets fonksiyonu öncesinde scanf kullanýldýðýnda çalýþmýyordu, 
		//internetteki diðer yöntemler de ayrý ayrý çalýþmasýna raðmen bu koda eklediðimde çalýþmýyordu
		//ben de alternatif olarak input buffer'ý sýfýrlamayý buldum ve þu anlýk iþe yarýyor
		gets(xs);		
		n=strlen(xs);	
		for(i=1;i<n;i++)	
			for(i1=0;i1<n;i1++)
				if(xs[i]<xs[i1])
				{
		  		cs=xs[i];
		  		xs[i]=xs[i1];
		  		xs[i1]=cs;
				}
		printf("\nsirali hali= ");
		printf("%s\n\n",xs);
		break;		
		
		case '3':
		printf("kac tane kelime olsun ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			{
			printf("%d. kelimeyi gir ",i+1);
			scanf("%s",xs1[i]);
			}
		for(i=0;i<n;i++)
			for(i1=i+1;i1<n;i1++)
				if(strcmp(xs1[i],xs1[i1])>0)
					{
            		strcpy(xs,xs1[i]);
					strcpy(xs1[i],xs1[i1]);
					strcpy(xs1[i1],xs);
					}
	printf("\nsirali hali= ");
	for(i=0;i<n;i++)
		printf("%s ",xs1[i]);
		break;
		
		default: printf("hatali secim");
			break;
	}
	return 0;
}
