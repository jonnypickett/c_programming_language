/* E3-1.C source code. By Jonathan Pickett. May 30, 2014 */

/* Binsearch. A program to perform a binary search for a number in an array. */

#include <stdio.h>

int binsearch (int x, int v[], int n);

int main ()
{

}

/* find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch (int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else		/* found match */
			return mid;
	}

	return -1;		/* no mathch */
}