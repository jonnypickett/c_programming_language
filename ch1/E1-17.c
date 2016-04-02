/* E1-17.C source code. By Jonathan Pickett. April 11, 2014 */

/* A program that prints lines of input over a certain hurdle point */

#include <stdio.h>
#define MAXLINE 1000
#define HURDLE 80

int grabline(char line[], int maxline);
void addline (char cat[], char new[]);

int count = 0;
int total = 0;

/* print longest input line */
int main()
{
	int x = 0;		/* number over lines over 80 characters */
	int len;	/* current line length */
	char line[MAXLINE];		/* current input line */
	char group[MAXLINE];	/* all lines over 80 characters */

	while ((len = grabline(line, MAXLINE)) > 0)
	{
		if (len > HURDLE) {
			addline (group, line);
			x++;
		}
	}
	printf ("%s...[%d line[s]; %d characters]\n", group, x, count-x);
	return (0);
}

/* grabline: read a line into s, return length */
int grabline (char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
		total++;
	}
	s[i] = '\n';
	return (i);
}

/* addline: adds lines over 80 characters to an array to print */
void addline (char cat[], char new[])
{
	int i = 0;

	while((cat[count] = new[i]) != '\n')
	{
		count++;
		i++;
	}
	cat[count++] = '\n';
}