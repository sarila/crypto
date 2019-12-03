#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
char alpha[50]="abcdefghijklmnopqrstuvwxyz";
int k,choice;
int getPos(char ch);
void encryption(char ch);
void decryption(char ch);
int main()
{
	int i=0,n;
	char pt[100];
	printf("enter the string:");
	gets(pt);
	n = strlen(pt);
	printf("Enter your choice:\n1.encryption\n2.decryption\n3.exit\n");
	scanf("%d",&choice);
	printf("Enter the value of key:");
	scanf("%d",&k);
	switch(choice){
		case 1:
			for(i=0;i<n;i++)
			{
				char ch=pt[i];
				encryption(ch);
			}
		break;
		case 2:
			for(i=0;i<n;i++)
			{
				char ch=pt[i];
				decryption(ch);
			}
		break;
		case 3:
			exit(0);
	}

	return 0;
}
void encryption(char ch)
{
	if(ch== ' ')
	{
		printf(" ");
		
	}
	else
	{
		int pos = getPos(ch);
		printf("%c",alpha[(pos+k)%26]);
	}
}
void decryption(char ch)
{
	if(ch== ' ')
	{
		printf(" ");
		
	}
	else
	{
		int pos = getPos(ch);
		printf("%c",alpha[(pos-k+26)%26]);
	}
}

int getPos(char ch)
{
	int i=0;
	for(i=0;i<strlen(alpha);i++)
	{
		if(ch==alpha[i])
		{ 
		return i;
		}
	}
}

