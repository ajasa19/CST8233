#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>

double getYfit(double x, int numOfPoints, double a1, double a0);


int main()
{


	double input = 0;
	int numOfPoints = 0;
	double pointsX[10];
	double pointsY[10];
	double x2 = 0, xy = 0, x = 0, y = 0, a1 = 0, a0 = 0;


	printf("Enter number of inputs\n");
		scanf("%d", &numOfPoints);


	printf("Enter x-axis values\n");

	for (int i = 0;  i < numOfPoints; i++) {
		 scanf("%lf", &pointsX[i]);
	}


	printf("Enter y-axis values\n");

	for (int i = 0; i < numOfPoints; i++) {
		scanf("%lf", &pointsY[i]);
	}
	

	for (int i = 0; i < numOfPoints; i++) {
		x += pointsX[i];
	}
	for (int i = 0; i < numOfPoints; i++) {
		y+= pointsY[i];
	}
	for (int i = 0; i < numOfPoints; i++) {
		x2 += (pointsX[i] * pointsX[i]);
	}
	for (int i = 0; i < numOfPoints; i++) {
		xy += (pointsX[i] * pointsY[i]);
	}

	a1 = ((numOfPoints * xy) - (x * y)) / ((numOfPoints * x2) - (x * x));

	a0 = ((y - (a1 * x)) / numOfPoints);

	printf("\nS.no		x			y(obs)			y(fit)\n");
	printf("_________________________________________________________________________________________________________\n");
	for (int i = 0; i < numOfPoints; i++) {
		printf("%d		%.1f			%.1f			%.3f\n",numOfPoints, pointsX[i], pointsY[i], getYfit(pointsX[i], numOfPoints, a1, a0));
	}
	printf("\nThe linear fit line is of the form:\n");
	printf("y = %.5fx + %.3f", a1, a0);
	
	};

double getYfit(double x, int numOfPoints, double a1, double a0) {

	double Yfitt = 0;

	Yfitt = (a1 * x) + a0;

	return Yfitt;
}