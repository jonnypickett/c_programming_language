/*E1-9.C source code. By Jonathan Pickett. February 19, 2014*/

/*A program to copy it's input to it's output, replacing each string of one
or more blanks by a single blank*/

#include <stdio.h>

int main()
{
	int x = 0;
	int a, b;
	char string[250];

	printf("Please type a line a text: ");
	gets(string);

	while(string[x] != EOF)
	{	
		while(string[x] == ' ' && string[x+1] == ' ')
		{
			a = 0;
			b = 1;
			do
			{
				string[x+a] = string[x+b];
				a++;
				b++;
			}
			while(string[x+a] != EOF);		
		}
		x++;
	}
	
	printf("%s\n", string);
}