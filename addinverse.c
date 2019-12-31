#include<stdio.h>
int GCD(int a,int b);
int main()
{
	int n,i,j,rem,a;
	int arr[100];
	printf("Enter the scope:");
	scanf("%d",&n);
	for(a=0;a<n;a++)
	{
		arr[a]=a;
	}
	
	printf("The additive inverse pair in z%d are:\n",n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			rem=(i+j)%n;
			if(rem==0){
				printf("(%d,%d)\t",i,j);
			}
		}
	}
	
	return 0;
}

