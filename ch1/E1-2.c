/*E1-2.C source code. By Jonathan Pickett. February 15, 2014*/

#include <stdio.h>

int main()
{
	printf("Hello, \r\a");
	printf("World!\r");
	printf("\0267");
	printf("\n");
}

/* Complete set of escape sequences */

/* \a	alert (bell) character */
/* \b 	backspace */
/* \f 	formfeed */
/* \n 	newline */
/* \r	carriage return */
/* \t 	horizontal tab */
/* \v 	vertical tab */
/* \\	backslash */
/* \?	question mark */
/* \'	single quote */
/* \"	double quote */
/* \ooo	octal number */
/* \xhh	hexidecimal number */