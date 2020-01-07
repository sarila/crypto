#include<stdio.h>
#include<conio.h>
int main()
{
	int a, p, root[30],i, k=0, power, j, flag=0;
	printf("Is --- primtive root of ----?");
	scanf("%d%d", &a,&p);
	for(i=1;i<p;i++)
	{
		power = pow(a,i);
		root[k]=power%p;
		k++;
	}
	for(i=0;i<p-1;i++){
		printf("%d\t",root[i]);
	}
	for(i=0;i<p-1;i++){
		for(j=i+1;j<p-1;j++){
			if(root[i]==root[j]){
				flag=1;
				break;
			}
		}
	}
	if(flag==0){
		printf("%d is primtive root of %d",a,p);
	}
	else{
		printf("%d is not a primtive root of %d",a,p);
	}
	return 0;
}
