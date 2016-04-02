/* E3-2.C source code. By Jonathan Pickett. May 29, 2014 */

/* Escape. A program to convert characters like newline and tab into visible escape sequences and 
* vice versa. */

#include <stdio.h>

#define MAXLINE 1000

int getLine (char s[]);
void escape (char s[], char t[]);
void revEscape (char t[], char r[]);

int main ()
{
	int x;
	char original [MAXLINE];
	char escaped [MAXLINE];
	char reversed [MAXLINE];

	while ((x = getLine (original)) > 0)
	{
		escape (original, escaped);
		printf ("%s\n", escaped);
		revEscape (escaped, reversed);
		printf ("%s\n", reversed);
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

/* Converts escape characters to visible escape characters */
void escape (char s[], char t[])
{
	int i, j;

	for (i = 0, j = 0; s[i] != '\0'; i++, j++) {
		switch (s[i]) {
			case '\t':
				t[j++] = '\\';
				t[j] = 't';
				break;
			case '\n':
				t[j++] = '\'';
				t[j] = 'n';
				break;
			default:
				t[j] = s[i];
				break;
		}
	}
}

/* Converts visible escape characters to actual escape characters */
void revEscape (char t[], char r[])
{
	int i, j;

	for (i = 0, j = 0; t[i] != '\0'; i++, j++) {
		if (t[i] == '\\') {
			switch (t[i+1]) {
				case 't':
					r[j] = '\t';
					i++;
					break;
				case 'n':
					r[j] = '\n';
					i++;
					break;
				default:
					r[j] = t[i];
					break;
			}
		}
		else
			r[j] = t[i];
	}

	r[j] = '\0';
}
