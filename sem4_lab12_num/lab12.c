#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>

double getK4(double x, double y, double h);

int main()
{
	double y = 1;
	double x = 0;
	double h = 0.1;

	for (int i = 0; i < 20; i++) {
		y = getK4( x, y, h);
		x = x + h;

		printf("The value of y %d  at x %d is : %lf \n", i+1, i+1, y);
	}

};


double getK4(double x, double y, double h) {

	double k1 = (2 * x - y) / 2;
	double k2 = (2 * (x + (h / 2)) - (y + 0.5 * k1 * h)) / 2;
	double k3 = (2 * (x + (h / 2)) - (y + 0.5 * k2 * h)) / 2; 
	double k4 = (2 * (x + h) - (y + k3 * h)) / 2;
	double y1 = y + (h / 6) * (k1 + (2 * k2) + (2 * k3) + k4);

	return y1;
};

