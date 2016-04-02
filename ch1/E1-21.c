/* E1-21.C source code. By Jonathan Pickett. May 10, 2014 */

/* Entab. A program to replace mulitple blank spaces with the equivalent number of tabs. */

#include <stdio.h>
#define MAXLINE 1000

int getLine (char s[]);
int formatLine (char new[], char old[]);

int main ()
{
	int x;
	char line[MAXLINE];
	char entabline[MAXLINE];

	while ((x = getLine (line)) > 0)
	{
		formatLine (entabline, line);
		printf ("%s\n", entabline);
	}

	return 0;
}

/* Gets input */
int getLine (char s[])
{
	int i, c;

	for (i = 0; (c = getchar()) != '\n'; i++)
		s [i] = c;
	s [i] = '\0';

	return i;
}

/* Replaces multiple spaces with equivalent number of tabs */
int formatLine (char new[], char old[])
{
	int a = 0;
	int b = 0;
	
	while (old [a] != '\0')
	{
		new [b] = old [a];
		
		if ((a % 8) == 7 && old [a] == ' ')
		{
			while (new [b] == ' ')
				b--;
			new [++b] = '\t';
		}
			
		a++;
		b++;
	}
	new [b] = '\0';

	return b;
}