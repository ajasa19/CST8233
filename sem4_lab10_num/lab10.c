#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>

double getYfit(double x, int numOfPoints, double a1, double a0);


int main()
{

	double X[] = {4, 2.25, 1.45, 1.0, 0.65, 0.25, 0.006};
	double Y[] = {0.398, 0.298, 0.238, 0.198, 0.158, 0.098, 0.048}; 
	double xSum = 0, ySum = 0, xySum = 0, x2Sum = 0, a1 = 0, a0 = 0, a = 0, b = 0;
	int size = 7;

	for (int i = 0; i < size; i++) {
		xSum += log10(X[i]);
		ySum += log10(Y[i]);
		xySum += (log10(X[i]) * log10(Y[i]));
		x2Sum += (log10(X[i]) * log10(X[i]));
	}

	a1 = ((size) * xySum - xSum * ySum) / ((size) * x2Sum - (xSum * xSum)); /*get a1*/
	a0 = (ySum - a1 * xSum) / (size); /*get a0*/

	a = pow(10, a0);
	b = a1;

	//a0e = exp(a0); /*get a0e*/

	printf("The Regression parameters are:\na0: %lf		a1: %lf\n\n", a, a1);
	printf("the nonlinear regression model is:\nY = %lf * Xexp(%lf)\n", a, b);



};
