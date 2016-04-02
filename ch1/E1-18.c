/* E1-18.C source code. By Jonathan Pickett. April 11, 2014 */

#include <stdio.h>
#define MAXLINE 1000

int grabline(char line[], int maxline);
void addline (char cat[], char new[]);
int formatline (char string[]);

int total = 0;	/* total number of characters */
int count = 0;

/* print longest input line */
int main()
{
	int x = 0;		/* number of lines */
	int len;		/* current line length */	
	int final;
	char line[MAXLINE];		/* current input line */
	char group[MAXLINE];	/* all lines */

	while ((len = grabline(line, MAXLINE)) > 0)
	{
			addline (group, line);
			x++;
	}
	final = formatline (group);
	printf ("%s...[%d line[s]; %d characters]\n", group, x, final-x);
	return (0);
}

/* grabline: read a line into s, return length */
int grabline (char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++) 
	{
		s[i] = c;
		total++;
	}
	s[i] = '\n';
	total++;
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

/* formatline: removes trailing blanks and tabs from each line of input and */
/* removes entirely blank lines */
int formatline (char string[])
{
	int x = 0;
	int a, b;

	while(string[x] != '\0')
	{	
		while((string[x] == ' ' && string[x+1] == ' ') || 
			(string[x] == ' ' && string[x+1] == '\n') || 
			(string[x] == '\t' && string[x+1] == '\t') || 
			(string[x] == '\t' && string[x+1] == '\n') || 
			(string[x] == '\n' && string[x+1] == '\n'))
		{
			a = 0;
			b = 1;
			do
			{
				string[x+a] = string[x+b];
				a++;
				b++;
			}
			while(string[x+a] != EOF);		
		}
		x++;
	}
	return (x);
}