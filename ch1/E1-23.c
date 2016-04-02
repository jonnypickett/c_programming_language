/* E1-23.C source code. By Jonathan Pickett. May 14, 2014. */

/* No Comment. A program to remove comments from a c source file. */

#include <stdio.h>

#define MAXLINE 1000

int getLine (char s[]);
int noComment (char new[], char old[]);

int main ()
{
	int x;
	char line[MAXLINE];
	char nocline[MAXLINE];

	while ((x = getLine (line)) > 0)
	{
		noComment (nocline, line);
		printf ("%s\n", nocline);
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

/* Removes comments from a c source file. */
int noComment (char new[], char old[])
{
	int a = 0;
	int b = 0;

	while (old [a] != EOF)
	{
		if (old [a] == '/' && old [a+1] == '*') {
			while (old [a+1] != '/')
				a++;
			a += 2;

			if (old [a] == ' ' || old [a] == '\n')
				a++;
		}
		else if (old [a] == '/' && old [a+1] == '/') {
			while (old [a] != '\n')
				a++;
			a++;
		}

		new [b++] = old [a++];
	}

	return b;
}