/* E2-8.C source code. By Jonathan Pickett. May 24, 2014 */

/* Rightrot. A program to rotate x right by n bits. */

#include <stdio.h>

unsigned int rightRot (unsigned int x, int n);

int main ()
{
	unsigned int x;
	int n;

	printf ("x: ");
	scanf ("%u", &x);
	fpurge (stdin);

	printf ("n: ");
	scanf ("%d", &n);
	fpurge (stdin);

	printf ("%u\n", rightRot (x, n));

}

/* rotate x right by n bits */
unsigned int rightRot (unsigned int x, int n)
{
	if (n < 0)
		return 0;

	if (n == sizeof (x)*8)
		return x;

	unsigned int temp1 = x<<(sizeof(x)*8-n);
	unsigned int temp2 = x>>n;
	return temp1 | temp2;
}