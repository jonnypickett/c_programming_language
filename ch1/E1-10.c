/*E1-10.c source code. By Jonathan Pickett. February 26, 2014*/

/*A program to replace tabs with "\t", backspaces with "\b", and backslashes with "\\"*/

#include <stdio.h>

void shift(char string[], int x);

int main()
{
	int x = 0;
	int temp1, temp2, a, b;
	char string[250];

	printf("Please enter a line of text: ");
	gets(string);

	while(string[x] != EOF)
	{
		if(string[x] == '\t')
		{
			a = 1;
			b = 2;
			string[x] = '\\';
			temp1 = string[x+a];
			string[x+a] = 't';
			do
			{
			temp2 = string[x+b];
			string[x+b] = temp1;
			temp1 = temp2;
			a++;
			b++;
			}
			while(string[x+a] != EOF);
			x++;
		}
		if(string[x] == '\\')
		{
			a = 1;
			b = 2;
			string[x] = '\\';
			temp1 = string[x+a];
			string[x+a] = '\\';
			do
			{
			temp2 = string[x+b];
			string[x+b] = temp1;
			temp1 = temp2;
			a++;
			b++;
			}
			while(string[x+a] != EOF);
			x++;
		}
		if(string[x] == '\b')
		{
			a = 1;
			b = 2;
			string[x] = '\\';
			temp1 = string[x+a];
			string[x+a] = 'b';
			do
			{
			temp2 = string[x+b];
			string[x+b] = temp1;
			temp1 = temp2;
			a++;
			b++;
			}
			while(string[x+a] != EOF);
			x++;
		}
		x++;
	}

	printf("%s\n", string);
}