#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>
#include <stdbool.h>

#include <math.h>

int main()
{
	int numOfPoints = 0;
	double interpolationPoint = 0;
	double Xpoints[10];
	double Ypoints[10];
	double xMax = 0;
	double xMin = 0;
	bool valid = true;

	printf("\nnumber of points: ");
		scanf("%d", &numOfPoints);

		for (int i = 0; i < numOfPoints; i++) {
			printf("\nx[%d] : ", i + 1);
			scanf("%lf", &Xpoints[i]);

			printf("\ny[%d]: ", i + 1);
			scanf("%lf", &Ypoints[i]);

		}

		printf("\nEnter interpolation point:");
		scanf("%lf", &interpolationPoint);

		for (int i = 0; i < numOfPoints; ++i) {
			if (xMax < Xpoints[i])
				xMax = Xpoints[i];
		}

		for (int i = 0; i < numOfPoints; ++i) {
			if (xMin > Xpoints[i])
				xMin = Xpoints[i];
		}


		for (int i = 0; i < numOfPoints; i++) {
			if (interpolationPoint < xMin || interpolationPoint > xMax) {
				valid = false;
			}
		}

		if (valid == true) {
		double Yp = 0;

		double l [15];
		for (int i = 0; i < 15; i++) {
			l[i] = 1.0;
		}
		

		for (int i = 0; i < numOfPoints; i++) {

			for (int j = 0; j < numOfPoints; j++) {

				if (j != i){
				l[i] = l[i] * ((interpolationPoint - Xpoints[j]) / (Xpoints[i] - Xpoints[j]));
				//printf("\n %lf - %lf / %lf - %lf", interpolationPoint, Xpoints[j], Xpoints[i], Xpoints[j]);
				//printf("\n[%d] = %lf", i, l[i]);
				}

			}

		}

		for (int i = 0; i < numOfPoints; i++) {	
			l[i] = l[i] * Ypoints[i];
			//printf("\n[%d] * %lf = %lf", i, Ypoints[i], l[i]);
		}

		for (int i = 0; i < numOfPoints; i++) {
			Yp = Yp + l[i];
		}

		printf("\nInterpolated value at %lf is %lf", interpolationPoint, Yp);
		}
		else {
			printf("\ninvalid point");
		}

	return 0;
}