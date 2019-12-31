#include<stdio.h>
#include<stdio.h>
#include<conio.h>
int Lucas_Lehmar(int P);
int main()
{
	int P,flag;
	printf("Enter the number to check for its primeness:");
	scanf("%d", &P);
	flag = Lucas_Lehmar( P);
	if(flag==0){
		printf("The given number %d is PRIME",P);
	}
	else{
		printf("The given number %d is COMPOSITE",P);
	}
	return 0;
}

int Lucas_Lehmar(int p)
{
	int s=4,m,i;
	m=pow(2,p)-1;
	for(i=0;i<(p-2);i++)
	{
		s = ((s*s)-2)%m;
	}
	if(s==0)
	{
		return 0;
	}
	else{
		return 1;
	}
	
}
