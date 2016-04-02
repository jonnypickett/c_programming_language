/* E2-10.C source code. By Jonathan Pickett. May 25, 2014 */

/* Lower. A program to convert upper case letters to lower case. */

#include <stdio.h>

int lower (int c);

int main ()
{
	int c;
	while ((c = getchar()) != EOF)
		putchar (lower(c));

	return 0;
}

/* converts upper case letters to lower case. */
int lower (int c)
{
		return (c >= 'A' && c <= 'Z') ? c + 'a'-'A' : c;
}