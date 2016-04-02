/* E2-6.C source code. By Jonathan Pickett. MAy 24, 2014 */

/* Setbits. A program that returns x with n bits starting at p changed to those of y. */

#include <stdio.h>
#include <stdlib.h>

unsigned int setbits (unsigned int x, int p, int n, unsigned int y);

int main ()
{
	unsigned int x, y;
	int p, n;

	printf ("x: ");
	scanf ("%u", &x);
	fpurge (stdin);

	printf ("y: ");
	scanf ("%u", &y);
	fpurge (stdin);

	printf ("p: ");
	scanf ("%d", &p);
	fpurge (stdin);

	printf ("n: ");
	scanf ("%d", &n);
	fpurge (stdin);

	printf ("%d\n", setbits (x, p, n, y));

	return 0;
}

/* Returns x with n bits starting at p changed to those of y */
unsigned int setbits (unsigned int x, int p, int n, unsigned int y)
{
	if (n < 0 || n > p + 1 || p < 0 || p > sizeof(unsigned int)*8)
		return 0;

	unsigned int temp1;

	if (p == n)
		temp1 = ~(~0);
	else	
		temp1 = (x<<(sizeof(x)*8-(p-n)))>>(sizeof(x)*8-(p-n));

	unsigned int temp2 = (x>>p)<<p;
	unsigned int temp3 = temp1 | temp2;
	unsigned int temp4 = (((y<<(sizeof(y)*8-p))>>(sizeof(y)*8-p))>>(p-n))<<(p-n);
	return temp3 | temp4;

}

