#include <stdio.h>
#include <conio.h>
#include <string.h>

char alpha[50] = "abcdefghijklmnopqrstuvwxyz";

int getPos(char ch)
{
	int i,pos;
	for(i=0;i<strlen(alpha);i++)
	{
		if(alpha[i] == ch)
		{
			pos=i;
		}
	}
	return pos;
}

int main()
{
	char pt[100], key[100];
	int i;
	printf("Enter the plain text\n");
	gets(pt);
	printf("Enter the key \n");
	gets(key);
	if(strlen(pt)!=strlen(key))
	{
		printf("Invalid key");
		return 0;
	}
	
	printf("The encrypted text is:\n");
	for(i=0; i<strlen(pt); i++)
	{
		char a = pt[i];
		char b = key[i];
		int pos1 = getPos(a);
		int pos2 = getPos(b);
		
		int index = (pos1+pos2)%26;
		printf("%c", alpha[index]);
	}
	
	return 0;
}


