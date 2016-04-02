/* E2-2.C source code. By Jonathan Pickett. May 20, 2014 */

/* A program to replicate the functionality of the getline for loop but without the && and || 
* operators. */

#include <stdio.h>

#define MAXLINE 1000
int getLine (char s[]);

int main ()
{
	int x;
	char string [MAXLINE];

	while ((x = getLine (string)) > 0)
		printf ("%s\n", string);

	return 0;
}

int getLine (char s[])
{
	int c, i;

	for (i = 0; i < MAXLINE - 1; i++) {
		c = getchar ();

		if (c == EOF)
			break;
		if (c == '\n')
			break;

		s [i] = c;
	}

	s [i] = '\0';

	return i;
}