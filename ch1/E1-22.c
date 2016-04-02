/* E1-22.C source code. By Jonathan Pickett. May 12, 2014 */

/* Fold line. A program to wrap text onto a new line after a certain length. */

#include <stdio.h>

#define MAXLINE 1000
#define LINELEN 32

int getLine (char s[]);
int foldLine (char new[], char old[], int len);

int main ()
{
	int x;
	char line[MAXLINE];
	char foldline[MAXLINE];

	while ((x = getLine (line)) > 0)
	{
		foldLine (foldline, line, LINELEN);
		printf ("%s\n", foldline);
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

/* Folds lines of text at last blank space before set max line length. */
int foldLine (char new[], char old[], int len)
{
	int a = 0;
	int b = 0;
	int newLine = 1;
	int x;
	int temp = 0;

	while (old [a] != EOF)
	{
		new [b] = old [a];

		if (newLine > 0 && (newLine % len) == 0) {
			temp = b;
			x = 6;
			
			if (old [a+1] == ' ') {
				new [++b] = '\n';
				newLine = 0;
				a++;
			}
			
			else {
				while (new [temp] != ' ' && x != 0) {
					temp--;
					x--;
				}
			
				if (x == 0) {
					new [++b] = '-';
					new [++b] = '\n';
					newLine = 0;
				}	
			
				else {
					new [temp] = '\n';
					newLine = 6 - x;
				}
			}
		}

		a++;
		b++;
		newLine++;
	}
	new [a] = '\0';

	return a;
}