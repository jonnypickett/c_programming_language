/* E1-20.C source code. By Jonathan Pickett. May, 10, 2014 */

/* Detab. A program to replace tabs in input with the proper number of blank spaces to the next tab stop. */

#include <stdio.h>
#define MAXLINE 1000

int getLine (char s[]);
int formatLine (char new[], char old[]);

int main ()
{
	int x;
	char line[MAXLINE];
	char detabline[MAXLINE];

	while ((x = getLine (line)) > 0)
	{
		formatLine (detabline, line);
		printf ("%s\n", detabline);
	}

	return 0;
}

/* Gets input */
int getLine (char s[])
{
	int i, c;

	for (i = 0; (c = getchar()) != '\n'; i++)
		s [i] = c;
	s [i] = '\0';

	return i;
}

/* Replaces tabs with equivalent blank spaces */
int formatLine (char new[], char old[])
{
	int a = 0;
	int b = 0;
	int d = 0;
	int e;

	while (old [a] != '\0')
	{
		d = 8 - (b % 8);
		if (old [a] == '\t')
		{
			for (e = 0; e < d; e++)
				{
					new [b] = ' ';
					b++;
				};
				a++;
		}
		else 
		{
			new [b] = old [a];
			a++;
			b++;
		}
	}
	new [b] = '\0';

	return b;
}