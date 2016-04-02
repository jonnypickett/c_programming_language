/*E1-6.C source code. By Jonathan Pickett. February 19, 2014*/

#include <stdio.h>

int main()
{
	int c;

	while(c = (getchar() != EOF))
	{
		printf("%d", c);
	}	
}