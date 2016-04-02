/* LONGLINE.C source code. By Jonathan Pickett. April 10, 2014 */

#include <stdio.h>
#define MAXLINE 1000	/* maximum input line size */

int grabline(char line[], int maxline);
void copy(char to[], char from[]);

int total = 0;

/* print longest input line */
int main()
{
	int len;	/* current line length */
	int max;	/* maximum length seen so far */
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = grabline(line, MAXLINE)) > 0)
	{
		if (len > max) {
			max = len;
			copy (longest, line);
		}
	}
	if (max > 0)	/* there was a line */
		printf ("%s...[longest line: %d characters; total: %d characters]\n", longest, max, total);
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
	s[i] = '\0';
	return (i);
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy (char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}