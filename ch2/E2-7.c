/* E2-7.C source code. By Jonathan Pickett. May 24, 2014 */

/* Invert. A program to return x with n bits starting at p inverted. */

#include <stdio.h>
#include <stdlib.h>

unsigned int invert (unsigned int x, int p, int n);

int main ()
{
	unsigned int x;
	int p, n;

	printf ("x: ");
	scanf ("%u", &x);
	fpurge (stdin);

	printf ("p: ");
	scanf ("%d", &p);
	fpurge (stdin);

	printf ("n: ");
	scanf ("%d", &n);
	fpurge (stdin);

	printf ("%u\n", invert (x, p, n));

	return 0;
}

/* Returns x with n bits starting at p inverted */
unsigned int invert (unsigned int x, int p, int n)
{
	if (n < 0 || n > p + 1 || p < 0 || p > sizeof(unsigned int)*8)
		return 0;

	if (p == n && n == sizeof (x)*8)
		return ~x;

	unsigned int temp1;

	if (p == n)
		temp1 = ~(~0);
	else	
		temp1 = (x<<(sizeof(x)*8-(p-n)))>>(sizeof(x)*8-(p-n));

	unsigned int temp2 = (x>>p)<<p;
	unsigned int temp3 = temp1 | temp2;
	unsigned int temp4 = (((~x<<(sizeof(x)*8-p))>>(sizeof(x)*8-p))>>(p-n))<<(p-n);
	return temp3 | temp4;

}

