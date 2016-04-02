/* E1-19.C source code. By Jonathan Pickett. April 12, 2014 */

/* A program that reverses input a line at a time */

#include <stdio.h>
#define MAXLINE 1000

int getstring (char string[],int lim);
void reverseline (char new[], char old[], int len);

int main()
{
	int len;
	char string[MAXLINE];

	while((len = getstring (string, MAXLINE)) > 0)
	{
		char revstring[len];
		reverseline (revstring, string, len);
		printf ("%s\n", revstring);
	}
	return (0);
}

int getstring (char string[], int lim)
{
	int i, c;

	for (i = 0; i < lim-1 && (c = getchar ()) != '\n'; i++)
		string[i] = c;

	return (i);
}

void reverseline (char new[], char old[], int len)
{
	int a;
	int b = len-1;

	for (a = 0; a < len; a++, b--)
		new[a] = old[b];

	new[a] = '\0';
}