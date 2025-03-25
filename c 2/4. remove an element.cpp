#include <stdio.h>
int main()
{
	int x[100]={13,27,5,69,47,1,2,3,4},a,n,i,h;
	
	printf("hangi sayiyi sileceksin ");
	scanf("%d",&h);
	while(x[n]!='\0')n++;
	for(i=0;i<n;i++)
		if (x[i]==h) while(x[i]!='\0'){x[i]=x[i+1]; i++;}

	for(i=0;x[i]!='\0';i++)
	printf(" %d \t",x[i]);

	return 0;
}
