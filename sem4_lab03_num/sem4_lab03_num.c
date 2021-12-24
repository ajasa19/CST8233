#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h>

#include <math.h>

int main() 
{
	int i;
	double n, x;
	n = 1.0;
	for (i = 0; i <= 147; i++)
	{
		n = n * 2.0;
		x = 1.0 / n;
		printf("%d %e %E\n", i, x, n);
	}

	printf("\n\ntask 2:");
	double factorial = 1;
	double trueFactorial = 1.0;
	double e = 2.71828;
	double absoluteError = 0.0, relativeError;
	int input = 0;
	int j;

	printf("\n\nType number of factorials you want:");
	scanf("%d", &input);

	for (i = 1; i <= input; i++) {
		factorial = 1;

		for (j = 1; j <= i; ++j)
		{
			factorial *= j;      // factorial = factorial*i;
		}

		trueFactorial = pow((i / e), i) * sqrt((2 * M_PI * i));
		absoluteError = factorial - trueFactorial;
		relativeError = (absoluteError / trueFactorial);

		printf("\n N: %d  n!: %f  real value: %f  absolute error: %0.5f  relative error: %f ", i, factorial, trueFactorial, absoluteError, relativeError);

		}
	return 0;
}