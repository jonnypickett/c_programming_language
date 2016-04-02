/* E2-3.C source code. By Jonathan Pickett. May 21, 2014 */

/* htoi. A program to turn a hexadecimal number into a decimal number. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>

#define MAXLINE 1000

int getLine (char s[]);
double htoi (char s[]);

int main ()
{
	int x;
	char hexalpha[MAXLINE];
	char test[] = "gg";

	while ((x = getLine (hexalpha)) > 0) {
		if (htoi (hexalpha) == 0) printf ("Hex string overflow or not a hex character.\n");
		else printf ("%.0lf\n", htoi (hexalpha));
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

/* Converts hexadecimal numbers to decimal numbers */
double htoi (char s[])
{
	double val = 0;
	int x = 0;

	if (s[x] == '0' && (s[x+1] == 'x' || s[x+1] == 'X')) x += 2;

	while (s[x] != '\0') 
	{
		if (val > DBL_MAX) return 0;
		
		else if (isdigit (s[x])) {
			val = val * 16 + s[x] - '0';
		}
		
		else if (s[x] >= 'A' && s[x] <= 'F') {
			val = val * 16 + s[x] - 'A' + 10;
		}
		
		else if (s[x] >= 'a' && s[x] <= 'f') {
			val = val * 16 + s[x] - 'a' + 10;
		}
		
		else return 0;

		x++;
	}

	return val;
}