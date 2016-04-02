/*E1-14.C source code. By Jonathan Pickett. March 3, 2014*/

/*A program to print a histogram of the frequencies of different characters in its input*/

#include <stdio.h>

int main()
{
	int x = 0;
	int a;
	char string[500];
	int character[200];
	char c;

	for(x = 0; x < 200; x++)
		character[x] = 0;
	x = 0;

	printf("Please enter a line of text: ");
	gets(string);

	while(string[x] != EOF)
	{
		c = string[x];
		character[(int)c]++;
		x++;
	}

	for(x = 32; x < 127; x++)
	{
		printf("%c |", (char)x);
		for(a = character[x]; a != 0; a--)
			putchar('-');
		putchar('\n');
	}
}