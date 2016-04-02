/*E1-10a.C source code. By Jonathan Pickett. February 26, 2014*/

/*A program to replace backspaces with "\b"*/

#include <stdio.h>

int main()
{
	int c;

	while((c = getchar()) != EOF)
	{
		switch(c)
		{
			case '\b':
				putchar('\\');
				putchar('b');
				break;
			default:
				putchar(c);
				break;
		}
	}
}