/*E1-13.c source code. By Jonathan Pickett. March 1, 2014*/

/*A program to print a histogram of the lengths of words in its input*/

#include <stdio.h>

int main()
{
	char string[500];
	int x = 0;
	int a;
	int letter = 0;
	int histogram[11];

	for(x = 0; x < 11; x++)
		histogram[x] = 0;

	printf("\nPlease type a line of text: ");
	gets(string);

	x = 0;

	while(string[x] != EOF)
	{
		if(string[x] >= 'A' && string[x] <= 'Z' || string[x] >= 'a' && string[x] <= 'z')
		{
			letter++;
			x++;
		}
		else
		{
			histogram[letter]++;
			letter = 0;
			x++;
		}
	}

	puts("\nWord Length Frequency\n");

	printf("Length\tFrequency\n"/*, 'Length', 'Frequency'*/);
	for(x = 1; x < 11; x++)
	{
		printf("%-2d letter |", x);
		for(a = histogram[x]; a != 0; a--)
		{
			printf("-");
		}
		putchar('\n');
	}
}