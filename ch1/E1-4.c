/*E1-4.C source code. By Jonathan Pickett. February 17, 2014*/

/*Celsius to Fahrenheit Temerature Conversion Table*/

#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;

	puts("Temperature Conversion Table");
	puts("Celsius to Fahrenheit");
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%6.1f %3.0f\n", celsius, fahr);
		fahr = fahr + step;
	}
}