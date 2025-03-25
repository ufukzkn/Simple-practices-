#include <stdio.h>
int main()
{
	int x[100]={1,2,3,3,4,5,5,6,2,7,8,9};
	int n,n1,i,i1,i2;
	
	while(x[n]!='\0')n++;
	n1=n;
	for(i=0;i<n;i++)
		for(i1=i;i1<n;i1++)
			if (x[i]==x[i1]&&i!=i1) 
				{
					i2=i1;
				while(x[i2]!='\0'){x[i2]=x[i2+1]; i2++;}	
				}

	for(i=0;x[i]!='\0';i++)
	printf(" %d \t",x[i]);

	return 0;
}
