#include<stdio.h>
#include<conio.h>
int GCD(int a,int b);
int a[100];
int main()
{
	int flag, n, i, k=0;
	printf("Enter the number:");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		flag= GCD(i,n);
		if(flag==1)
		{
			a[k]=i;
			k++;
		}
	}
	printf("The numbers that are relatively prime to %d are:\n",n);
	for(i=0;i<k;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;
	
}
int GCD(int a,int b)
{
	int r1,r2,q,r;
	r1=a;
	r2=b;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
	}
	return r1;
}
