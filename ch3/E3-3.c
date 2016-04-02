/* E3-3.C source code. By Jonathan Pickett. May 29, 2014 */

/* Expand. A program to expand instances like a-z into abcde...xyz. */

#include <stdio.h>

#define MAXLINE 1000

int getLine (char s[]);
void expand (char s[], char t[]);

int main ()
{
	int x;
	char original [MAXLINE];
	char expanded [MAXLINE];

	while ((x = getLine (original)) > 0)
	{
		expand (original, expanded);
		printf ("%s\n", expanded);
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

/* Expands instances like a-z or 0-9 to abcde...xyz and 0123...789 respectively */
void expand (char s[], char t[])
{
	int a = 0;
	int b = 0;

	while (s[a] != '\0') {
		int c = 0;

		if (s[a] == '-' && s[a-1] < s[a+1]) {
			b--;
			do {
				t[++b] = s[a-1] + ++c;
			}
			while (t[b] != s[a+1] - 1);
		}
		else if (s[a] == '-' && s[a-1] > s[a+1]) {
			b--;
			do {
				t[++b] = s[a-1] + --c;
			}
			while (t[b] != s[a+1] + 1);
		}
		else 
			t[b] = s[a];
		
		a++;
		b++;
	}

	t[b] = '\0';
}
