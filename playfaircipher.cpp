#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
char alpha[50]="abcdefghiklmnopqrstuvwxyz";
char ch;
char str[100];
int r=0,c=0;
char keyword[50];
char mat[20][20];
char pt[100];
int i1,i2,j1,j2;
int CheckRepetition(char ch,int n);
void CheckFiller(char ch,int n);
void encryption(char ch1,char ch2);
void decryption(char ch1,char ch2);

int main()
{
	printf("Enter Keyword:");
	gets(keyword);
	strcpy(str,strcat(keyword,alpha));
	for(int i=0;i<strlen(str);i++)
	{
		char ch=str[i];
		int check=CheckRepetition(ch,i);
		if(check==0)
		{
			mat[r][c]=ch;
			c++;
			if(c==5)
			{
				r++;
				c=0;
			}
		}
	}
	
	printf("\n\nThe 5*5 matrix is:\n\n");
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
	
	
	
	printf("\nType 1 to Encrypt your text or Type 2 to Decrpyt your text.");
	printf("\nType any number to exit.");
	while(1)
	{
		int choice;
		printf("\n\nEnter your choice:");
		scanf("%d",&choice);
		if(choice==1)
			{
				fflush(stdin);
				fflush(stdout);
				int i;
				printf("\n\tEnter a Plain text: ");
				gets(pt);
				printf("\n\tThe modified Plain text is: ");
				for(i=0;i<strlen(pt);i+=2)
				{
					ch=pt[i];
					CheckFiller(ch,i);
				}
				printf("\n\n\tThe Encrypted Text is: ");
				for(i=0;i<strlen(pt);i+=2)
				{
					int ch1=pt[i];
					int ch2=pt[i+1];
					encryption(ch1,ch2);
					if(i1==i2)
					{
						int a=0,b=0;
						if(j1==4)
						{
							pt[i]=mat[i1][a];
							pt[i+1]=mat[i2][j2+1];	
						}
						else if(j2==4)
						{
							pt[i]=mat[i1][j1+1];
							pt[i+1]=mat[i2][b];
						}
						else{
						pt[i]=mat[i1][j1+1];
						pt[i+1]=mat[i2][j2+1];
					}
					}
					else if(j1==j2)
					{
						int a=0,b=0;
						if(i1==4)
						{
							pt[i]=mat[a][j1];
							pt[i+1]=mat[i2+1][j2];
						}
						else if(i2==4)
						{
							pt[i]=mat[i1+1][j1];
							pt[i+1]=mat[b][j2];
						}
						else
						{
						pt[i]=mat[i1+1][j1];
						pt[i+1]=mat[i2+1][j2];
					}
					}
					else
					{
						  pt[i]=mat[i1][j2];
						  pt[i+1]=mat[i2][j1];
					}
					printf("%c%c ",pt[i],pt[i+1]);
				}
				memset(pt,'\0',100); //To clean the char array for next loop
			}
		else if(choice==2)
			{
				fflush(stdin);
				fflush(stdout);
				int i;
				printf("\n\tEnter a Cipher text: ");
				gets(pt);
				printf("\n\tThe modified Plain text is: ");
				for(i=0;i<strlen(pt);i+=2)
				{
					ch=pt[i];
					CheckFiller(ch,i);
				}
				printf("\n\n\tThe decrypted Text is: ");
				for(i=0;i<strlen(pt);i+=2)
				{
					int ch1=pt[i];
					int ch2=pt[i+1];
					decryption(ch1,ch2);
					if(i1==i2)
					{
						int a=4,b=4;
						if(j1==0)
						{
							pt[i]=mat[i1][a];
							pt[i+1]=mat[i2][j2-1];	
						}
						else if(j2==0)
						{
							pt[i]=mat[i1][j1-1];
							pt[i+1]=mat[i2][b];
						}
						else{
						pt[i]=mat[i1][j1-1];
						pt[i+1]=mat[i2][j2-1];
					}
					}
					else if(j1==j2)
					{
						int a=4,b=4;
						if(i1==0)
						{
							pt[i]=mat[a][j1];
							pt[i+1]=mat[i2-1][j2];
						}
						else if(i2==0)
						{
							pt[i]=mat[i1-1][j1];
							pt[i+1]=mat[b][j2];
						}
						else
						{
						pt[i]=mat[i1-1][j1];
						pt[i+1]=mat[i2-1][j2];
					}
					}
					else
					{
						  pt[i]=mat[i1][j2];
						  pt[i+1]=mat[i2][j1];
					}
					printf("%c%c ",pt[i],pt[i+1]);
				}
				memset(pt,'\0',100); //To clean the char array for next loop
			}
		else
		{
				printf("\n\nExiting...................................");
				exit(0);
		}
	}
}

int CheckRepetition(char ch,int n)
{
	for(int i=0;i<=n-1;i++)
	{
		if(str[i]==ch)
		return 1;
	}
	return 0;
}

void CheckFiller(char ch,int n)
{
	
	if(ch==pt[n+1])
	{
	for(int j=strlen(pt);j>(n+1);j--)
	{
		pt[j]=pt[j-1];
	}
	pt[n+1]='x';
    }
    if(pt[n+1]=='\0')
    pt[n+1]='x';
    
    printf("%c%c  ",pt[n],pt[n+1]);
}

void encryption(char ch1,char ch2)
{
    for(int m=0;m<5;m++)
    {
    	for(int n=0;n<5;n++)
    	{
    		if(mat[m][n]==ch1)
    		{
    			i1=m,j1=n;
			}
			if(mat[m][n]==ch2)
    		{
    			i2=m,j2=n;
			}
		}
	}
}

void decryption(char ch1,char ch2)
{
	for(int m=0;m<5;m++)
    {
    	for(int n=0;n<5;n++)
    	{
    		if(mat[m][n]==ch1)
    		{
    			i1=m,j1=n;
			}
			if(mat[m][n]==ch2)
    		{
    			i2=m,j2=n;
			}
		}
	}
}
