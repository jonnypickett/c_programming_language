/*E1-8.C source code. By Jonathan Pickett. February 19, 2014*/

#include <stdio.h>

int main()
{
	int c, b, t, nl;

	b = t = nl = 0;
	while((c = getchar()) != EOF)
	{	
		if(c == '\n')
			nl++;
		else if(c == ' ')
			b++;
		else if(c == '\t')
			t++;
	}
	printf("%d blank spaces, %d tabs, and %d new line characters\n", b, t, nl);
}