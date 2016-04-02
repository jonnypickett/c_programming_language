/* E2-1.C source code. By Jonathan Pickett. May 17, 2014 */

/* A program to find the value limits for each variable type. */

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>

unsigned long unsignedMaxLimit (int n);
long signedMinLimit (int n);
long signedMaxLimit (int n);

int main ()
{
	int x;

	puts ("Using standard headers:\n");

	printf ("The size of a char is %d bytes (%d bits)\n", x = sizeof (char), x * CHAR_BIT);
	printf ("Min unsigned char value: %u\n", 0);
	printf ("Max unsigned char value: %u\n", UCHAR_MAX);
	printf ("Min char value: %d\n", SCHAR_MIN);
	printf ("Max char value: %d\n\n", SCHAR_MAX);

	printf ("The size of a short int is %d bytes (%d bits)\n",  x = sizeof (short), x * CHAR_BIT);
	printf ("Min unsigned short value: %u\n", 0);
	printf ("Max unsigned short value: %u\n", USHRT_MAX);
	printf ("Min signed short value: %d\n", SHRT_MIN);
	printf ("Max signed short value: %d\n\n", SHRT_MAX);

	printf ("The size of an int is %d bytes (%d bits)\n",  x = sizeof (int), x * CHAR_BIT);
	printf ("Min unsigned int value: %u\n", 0);
	printf ("Max unsigned int value: %u\n", UINT_MAX);
	printf ("Min signed int value: %d\n", INT_MIN);
	printf ("Max signed int value: %d\n\n", INT_MAX);

	printf ("The size of a long int is %d bytes (%d bits)\n",  x = sizeof (long), x * CHAR_BIT);
	printf ("Min unsigned long value: %u\n", 0);
	printf ("Max unsigned long value: %lu\n", ULONG_MAX);
	printf ("Min signed long value: %ld\n", LONG_MIN);
	printf ("Max signed long value: %ld\n\n", LONG_MAX);

	printf ("The size of a float is %d bytes (%d bits)\n",  x = sizeof (float), x * CHAR_BIT);
	printf ("Min float value: %f\n", FLT_MIN);
	printf ("Max float value: %f\n\n", FLT_MAX);

	printf ("The size of a double float is %d bytes (%d bits)\n",  x = sizeof (double), x * CHAR_BIT);
	printf ("Min double value: %f\n", DBL_MIN);
	printf ("Max double value: %f\n\n", DBL_MAX);

	printf ("The size of a long double float is %d bytes (%d bits)\n",  x = sizeof (long double), x * CHAR_BIT);
	printf ("Min long double value: %Lf\n", LDBL_MIN);
	printf ("Max long double value: %Lf\n\n", LDBL_MAX);

	puts ("Using direct computation:\n");

	puts ("Using function:\n");
	
	printf ("Min signed char value: %ld\n", signedMinLimit (sizeof(char)));
	printf ("Max signed char value: %ld\n", signedMaxLimit (sizeof(char)));
	printf ("Max unsigned char value: %lu\n\n", unsignedMaxLimit (sizeof(char)));

	printf ("Min signed short value: %ld\n", signedMinLimit (sizeof(short)));
	printf ("Max signed short value: %ld\n", signedMaxLimit (sizeof(short)));
	printf ("Max unsigned short value: %lu\n\n", unsignedMaxLimit (sizeof(short)));
	
	printf ("Min signed int value: %ld\n", signedMinLimit (sizeof(int)));
	printf ("Max signed int value: %ld\n", signedMaxLimit (sizeof(int)));
	printf ("Max unsigned int value: %lu\n\n", unsignedMaxLimit (sizeof(int)));

	printf ("Min signed long value: %ld\n", signedMinLimit (sizeof(long)));
	printf ("Max signed long value: %ld\n", signedMaxLimit (sizeof(long)));
	printf ("Max unsigned long value: %lu\n\n", unsignedMaxLimit (sizeof(long)));

	puts ("Using overflow method:\n");
	char t1 = 0;
	while (--t1 < 0);
	t1++;
	printf ("Min char value: %d\n", t1);

	char t2 = 0;
	while (++t2 > 0);
	t2--;
	printf ("Max char value: %d\n", t2);

	unsigned char t3 = 0;
	t3--;
	printf ("Max unsigned char value: %u\n\n", t3);

	int t4 = -1;
	while (t4 < 0) 
	t4 -= 100000;
	t4 += 100000;
	while (--t4 < 0);
	t4++;
	printf ("Min int value: %d\n", t4);

	int t5 = 1;
	while (t5 > 0) 
	t5 += 100000;
	t5 -= 100000;
	while (++t5 > 0);
	t5--;
	printf ("Max int value: %d\n", t5);

	unsigned int t6 = 0;
	t6--;
	printf ("Max unsigned int value: %u\n\n", t6);

	puts ("Using sizeof() operator:\n");
	double tmp = 0;

	tmp = pow (2, (sizeof (char) * 8) - 1) * -1;
	printf ("Min char value: %.0f\n", tmp);

	tmp = pow (2, (sizeof (char) * 8) - 1) - 1;
	printf ("Max char value: %.0f\n", tmp);

	tmp = pow (2, sizeof (char) * 8) - 1;
	printf ("Max unsigned char value: %.0f\n\n", tmp);

	tmp = pow (2, (sizeof (int) * 8) - 1) * -1;
	printf ("Min int value: %.0f\n", tmp);

	tmp = pow (2, (sizeof (int) * 8) - 1) - 1;
	printf ("Max int value: %.0f\n", tmp);

	double tmp2 = 0;
	tmp2 = pow (2, sizeof (int) * 8);
	printf ("Max unsigned int value: %.0f\n", tmp2);

	/* Float value got by direct computation */
	int i, n;
	float fnum = 2.0;
	n = 34;

	do {
		fnum *= --n;

		if (n % 10 == 0)
			printf ("\nThe float is now: %f", fnum);
	} while (n > 1);
	printf ("\nThe float is now: %f\n\n", fnum);

	printf ("Max value to reach: %f\n", FLT_MAX);
	while (fnum < FLT_MAX) {
		fnum *= 1.00000006;
	}
	printf ("The float is now: %f\n\n", fnum);

	fnum /= 100;

	printf ("Divided by 100: %f\n", fnum);

	getchar();

	return 0;
}

unsigned long unsignedMaxLimit (int n)
{
	int i = 0;
	n *= 8;

	for (int x = 0; x < n; x++)
		i += pow (2, x);

	return i;
}

long signedMinLimit (int n)
{
	int i;
	n *= 8;

	i = pow (2, --n) * -1;

	return i;
}

long signedMaxLimit (int n)
{
	int i = 0;
	n *= 8;

	for (int x = 0; x < (n - 1); x++)
		i += pow (2, x);

	return i;
}