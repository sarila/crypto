#include<stdio.h>
#include<conio.h>
int GCD(int a,int b);
int main()
{
	int a, b, gcd;
	printf("Enter two numbers a and b:");
	scanf("%d%d",&a,&b);
	gcd = GCD(a,b);
	printf("The gcd of two numbers %d and %d is %d",a,b,gcd);
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
