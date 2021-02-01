#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <math.h>

void Deffie_Hellman(int p, int g)
{
	int XA, XB, YA, YB, K1, K2, k1,k2,ya,yb;
	XA = (rand() %p); 
	printf("%d\n",XA);
	ya = pow(g,XA);
	YA = ya%p;
	
	XB = (rand()%p);
	printf("%d\n",XB);
	yb = pow(g,XB);
	YB = yb%p;

	k1 = pow(YB, XA);
	k2 = pow(YA, XB);	
	K1 = k1%p;
	K2 = k2%p;
	
	printf("%d \t %d", K1,K2); 
	
}

int main()
{
	int p,g,i;
	printf("Enter plain text:");
	scanf("%d", &p);
	printf("Enter key text:");
	scanf("%d", &g);
	
	Deffie_Hellman(p,g);
	
	return 0;
}


