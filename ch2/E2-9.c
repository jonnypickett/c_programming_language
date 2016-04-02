/* E2-9.C source code. By Jonathan Pickett. May 25, 2014 */

/* Bitcount. A program to count the number of one bits in a number. */

#include <stdio.h>

int bitcount (unsigned int x);

int main ()
{
	unsigned int x;

	printf ("x: ");
	scanf ("%u", &x);

	printf ("%d\n", bitcount(x));

	return 0;
}

/* counts one bits. */
int bitcount (unsigned int x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		b++;

	return b;
}