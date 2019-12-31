#include<stdio.h>
#include<conio.h>
int mulin(int n,int b);
int main()
{
	int n, b, gcd, mul;
	printf("Enter the number:");
	scanf("%d",&b);
	printf("Enter the scope:");
	scanf("%d",&n);
	mul = mulin(n,b);
	printf("The multiplicative inverse of %d in z%d is %d",b,n,mul);
	return 0;
}

int mulin(int n,int b)
{
	int r1,r2,q,r,t,t1,t2,mul;
	r1=n;
	r2=b;
	t1=0;
	t2=1;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	if(r1==1){
		mul = t1%n;
		if(mul>0)
			return mul;
		else
			return (mul+n);
	}
	
}
