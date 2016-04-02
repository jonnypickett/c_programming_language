/* E1-24.C source code. By Jonathan Pickett. MAy 15, 2014 */

/* Code check. A program to check a c source file for rudimentary syntax errors. */

#include <stdio.h>

#define MAXLINE 100000

int getLine (char s[]);
void cCheck (char check[]);

int main ()
{
	int x;
	char line[MAXLINE];

	while ((x = getLine (line)) > 0)
	{
		cCheck (line);
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

/* Checks input for rudimentary synax errors */
void cCheck (char check[])
{
	int a = 0;
	int curly = 0;
	int paren = 0;
	int brakt = 0;
	int snglq = 0;
	int dblq = 0;

	while (check[a] != EOF) {
		switch (check [a]) {
			
			case '{':
				curly++;
				break;
			
			case '}':
				curly--;
				break;
			
			case '(':
				paren++;
				break;
			
			case ')':
				paren--;
				break;
			
			case '[':
				brakt++;
				break;
			
			case ']':
				brakt--;
				break;
			
			case '\'':
				snglq++;
				break;
			
			case '\"':
				dblq++;
				break;
		}

		a++;
	}

	if (curly != 0 || paren != 0 || brakt != 0 || (snglq % 2) != 0 || (dblq % 2) != 0)
		puts ("Syntax error in source file");
}