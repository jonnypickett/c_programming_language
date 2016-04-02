/*E1-12.C source code. By Jonathan Pickett. February 26, 2014*/

/*A program that prints input one word per line*/

#include <stdio.h>

int main()
{
	int x = 0;
	char string[250];

	printf("Please enter a line of text: ");
	gets(string);

	while(string[x] != EOF)
	{
		switch(string[x])
		{
			case ' ':
				string[x] = '\n';
				break;
			case '\t':
				string[x] = '\n';
				break;
			case '\\':
				string[x] = '\n';
				break;
		}
		x++;
	}

	printf("%s\n", string);
}