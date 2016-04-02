/* E2-4.C source code. By Jonathan Pickett. May 22, 2014 */

/* Squeeze alternate. A program that deletes each character in string 1 that matches any character
* in string 2. */

#include <stdio.h>

#define MAXLINE 1000

int getLine (char s[]);
void squeeze2 (char s1[], char s2[], char s1new[]);

int main ()
{
	char string1 [MAXLINE];
	char string1new [MAXLINE];
	char string2 [MAXLINE];

	getLine (string1);
	getLine (string2);
	squeeze2 (string1, string2, string1new);
	printf ("%s\n", string1new);
	
	return 0;
}

/* Gets input. */
int getLine (char s[])
{
	int i = 0;
	int c;

	for (i = 0; (c = getchar()) != '\n'; i++)
		s [i] = c;
	s [i] = '\0';

	fpurge (stdin);

	return i;
}

/* Deletes each character in s1 that matches s2. */
void squeeze2 (char s1[], char s2[], char s1new[])
{
	int a = 0;
	int b = 0;

	while (s1 [a] != '\0')
	{
		if (s1 [a] != s2 [a])
			s1new [b++] = s1 [a];
		a++;
	}

	s1new [b] = '\0';
}