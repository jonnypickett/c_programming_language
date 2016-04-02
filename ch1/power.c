/*POWER.C source code. By Jonathan Pickett. April 10, 2014*/

#include <stdio.h>

int power(int base, int n);

int main()
{
	int x, n;

	puts("Exponential Power!");
	puts("Find out what a certain base raised to a certain power is.\n");
	
	printf("What would you like the base number to be? ");
	scanf("%d", &x);
	printf("What power would you like the base raised to? ");
	scanf("%d", &n);
	printf("%d raised to the %d power is %d\n", x, n, power(x, n));
	
	return(0);
}

int power(int x, int n)
{
	int i, p;
	p = 1;

	for(i = 1; i <= n; i++)
	{
		p *= x;
	}
	return(p);
}