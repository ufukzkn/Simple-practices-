#include <stdio.h>
int main()
{
	int x[100]={1,2,3,3,4,5,5,5,6,2,7,8,8,9};
	int n,n1,i,i1,i2;
	//counter'im '\0' (null) degeri ile calistigi icin array'de int karsiligi olan 0'i koyunca calismiyor
	while(x[n]!='\0')n++;
	printf("array'in ilk hali: ");
		for(i=0;i<n;i++) printf("%d  ",x[i]);
	
	for(i=0;i<n;i++)
		for(i1=0;i1<n;i1++) 	if(x[i]==x[i1]&&i!=i1) x[i1]='\0';

	for(i=0;i<n;i++)
	{
	if (x[i]=='\0') 
		{
			for(i2=0;i2<n;i2++)
				{
					i1=i;
					if(x[i+1]==x[i])
						while(i1<n){x[i1]=x[i1+1]; i1++;}
				}
			i1=i;
			while(i1<n){x[i1]=x[i1+1]; i1++;}
		}
	}
	printf("\n\nkopyalarin silinmis hali: ");
	for(i=0;x[i]!='\0';i++)
	printf("%d  ",x[i]);

	return 0;
}
