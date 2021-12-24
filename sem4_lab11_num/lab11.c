#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>


int main()
{

	double fowardDiff = 0, backwardDiff = 0, centerdDiff = 0;
	double frontPoint = 0, backPoint = 0, centerFrontPoint = 0, centerBackPoint = 0;
	double x = 0, h = 0.25, y = 0, yDiv = 0;

	frontPoint = (0.25) * sin(pow(0.25, 2)) + 1;
	backPoint = (0) * sin(pow(0, 2)) + 1;
	centerFrontPoint = (0.50) * sin(pow(2, 2)) + 1;
	centerBackPoint = (-0.25) * sin(pow(2, 2)) + 1;


	fowardDiff = (((0.25) * sin(pow(0.25, 2)) + 1) -((0) * sin(pow(0, 2)) + 1) )/0.25;
	backwardDiff = (((0) * sin(pow(0, 2)) + 1) - ((-0.25) * sin(pow(-0.25, 2)) + 1)) / 0.25;
	centerdDiff = (((0.5) * sin(pow(0.5, 2)) + 1) - ((0) * sin(pow(0, 2)) + 1)) / (0.25*2);

	printf("x	y		Exact der		Centered	forward		backward\n");
	for (int i = 0; i < 17; i++) {

		fowardDiff = (((x+h) * sin(pow(x + h, 2)) + 1) - ((x) * sin(pow(x, 2)) + 1)) / h;
		backwardDiff = (((x) * sin(pow(x, 2)) + 1) - ((x-h) * sin(pow(x - h, 2)) + 1)) / h;
		centerdDiff = (((x+h) * sin(pow(x + h, 2)) + 1) - ((x - h) * sin(pow(x - h, 2)) + 1)) / (h * 2);

		y = (x)*sin(pow(x, 2)) + 1;
		yDiv = sin(pow(x, 2)) + 2 * pow(x, 2) * cos(pow(x, 2));

		if (x + h > 4 || x - h < 0) {
			if (x + h > 4) {
				printf("%.2f    %.4f		%lf		-		-		%lf\n", x, y, yDiv, backwardDiff);
			}
			if (x - h < 0) {
				printf("%.2f    %.4f		%lf		-		%lf	 -\n", x, y, yDiv, fowardDiff);
			}
		} else {
			printf("%.2f    %.4f		%lf		%lf	%lf	%lf\n", x, y, yDiv, centerdDiff, fowardDiff ,backwardDiff);
		}

		x += h;

	}

};
