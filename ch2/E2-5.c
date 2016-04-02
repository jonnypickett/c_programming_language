/* E2-5.C source code. By Jonathan Pickett. May 22, 2014 */

/* Any. A program that compares to strings and returns the location of the first instance
* of the strings having the same character. */

#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
char letter;

int getLine (char s[]);
int any (char s1[], char s2[], int y);

int main ()
{
	int x, y, z;
	char string1 [MAXLINE];
	char string2 [MAXLINE];

	getLine (string1);
	y = strlen (string1);
	getLine (string2);
	z = strlen (string2);
	x = any (string1, string2, y);
	if (x == 0) 
		puts ("There are no instances of the strings being the same.");
	else if (x == 1 || (x % 100 > 20 && x % 10 == 1))
		printf ("The %dst character \"%c\" is the first instance of the strings being the same.\n", x, letter);
	else if (x == 2 || (x % 100 > 20 && x % 10 == 2))
		printf ("The %dnd character \"%c\" is the first instance of the strings being the same.\n", x, letter);
	else if (x == 3 || (x % 100 > 20 && x % 10 == 3))
		printf ("The %drd character \"%c\" is the first instance of the strings being the same.\n", x, letter);
	else 
		printf ("The %dth character \"%c\" is the first instance of the strings being the same.\n", x, letter);

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

/* Finds the location of the first instance of the strings matching and returns that location and letter. */
int any (char s1[], char s2[], int y)
{
	int a = 0;

	while (s1 [a] != s2[a]) {
		if (s1[a] == '\0' || s2[a] == '\0') 
			return 0;
		a++;
	}

	if (s1[a] == '\0' && s2[a] == '\0')
		return 0;

	letter = s1[a];

	return ++a;
}