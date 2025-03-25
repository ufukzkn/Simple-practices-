#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,35,89,62},a,n,i,n1,h,l;
	
	printf("mevcut array'e hangi sayiyi ekleyeceksin ");
	scanf("%d",&h);
	while(x[n]!='\0')n++;
	printf("mevcut veri sayisi=%d \n\nnereye ekleyeceksin ",n);
	scanf("%d",&l);
	if (l>n+1){printf("hatali giris"); return 0;}
	n1=n;
	for(i=0;i<n;i++)
		if (i==l-1) {
					while(i<n1) 
						{
						x[n1]=x[n1-1]; n1--;
						}
					}
	x[l-1]=h;
	for(i=0;i<n+1;i++)
	printf(" %d \t",x[i]);
		
	return 0;
}
