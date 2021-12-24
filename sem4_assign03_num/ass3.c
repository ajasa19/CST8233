/********************************************************************************
Filename:			ass3.c
Version:			1.0
Author:				Asim Jasarevic
StudentNo:			040922815
Course Name/Number:	Numerical Computing 20F_CST8233–300
Lab Sect:			303
Assignment #:		3
Assignment name:	Moore's Law
Due Date:			2020, Dec, 6
Submission Date:	2020, Nov, 29
Professor:			Hala Own
Purpose:			Take user input and caluclate predicted temp for a mercury thermometer system over 2 seconds using 4 methods 
					Euler, Range-Kutta 2nd, 3rd, and 4th. Also allow diffrent steps to be chosen for more accurate data
All files:			ass3.c
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// include 
#include <stdio.h>
#include <math.h>

/*function decleartions*/
double getTrueTemp(double x); 
double getEulerTemp(double x, double y, double h); 
double getPercentErr(double trueValue, double testValue);
double getRK2(double x, double y, double h);
double getRK3(double x, double y, double h);
double getRK4(double x, double y, double h);
double getH(double check2);

/********************************************************************************
Function name:		main
Purpose:			run program handel all user inputs, display menu, and cal functions to calculate value
In parameters:
Out parameters:		return 0
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
int main()
{
	double h = 0.2; /*h value used to get steps the large the the less steps*/
	double y = 3; /*y at 0*/
	double x = 0; /*x at 0*/
	int breakMenu = 0; /*used to break out of menu when exit is called*/
	double check = 0, check2 = 0; /*used to get user input for menu(check) and user input for h(check2)*/

	/*for loop for menu*/
	for (breakMenu = 0; breakMenu == 0;) {
		printf(">> Choose the method for solving the ODE: \n");
		printf("1. Euler's Method \n\n");
		printf("2. Runge-Kutta 2nd Order Method \n\n");
		printf("3. Runge-Kutta 3rd Order Method \n\n");
		printf("4. Runge-Kutta 4th Order Method \n\n");
		printf("5- Exit\n\n");

		/*get input from user and check if valid*/
		for (int i = 0; i == 0;) {
			printf(">>");
			scanf("%lf", &check);
			getchar();

			/*if check is 1, 2, 3, 4, 5 input is good*/
			if (check == 1 || check == 2 || check == 3 || check == 4 || check == 5) {
				i = 1;
			}
			else {
				printf("invalid input\n");
			}
		}

		/*if user input 1 run Euler method */
		if (check == 1) {

			/*get valid h from user*/
			h = getH(check2);

			printf("Time(seconds)	Exact Temp(C)	Estimated Temp(C)	Percentage Error(%%):\n");

			/*for loop to display time(x) trueTemp(y), eulerTemp(y) and %err by calling functions*/
			for (x = 0; x <= 2.0-h; x += h) {
				printf("%0.2f		%0.3f		%0.3f			%0.2f	 \n", x + h, getTrueTemp(x + h), getEulerTemp(x, y, h), getPercentErr(getTrueTemp(x + h), getEulerTemp(x, y, h)));
				//set y to whatever euler result is for next step.
				y = getEulerTemp(x, y, h);
			}

			printf("\n");
		}

		/*if user input 2 run Range - Kutta 2nd method*/
		if (check == 2) {

			/*get valid h from user*/
			h = getH(check2);

			printf("Time(seconds)	Exact Temp(C)	Estimated Temp(C)	Percentage Error(%%):\n");

			/*for loop to display time(x) trueTemp(y), eulerTemp(y) and %err by calling functions*/
			for (x = 0; x <= 2.0 - h; x += h) {
				printf("%0.2f		%0.3f		%0.3f			%0.2f	 \n", x + h, getTrueTemp(x + h), getRK2(x, y, h), getPercentErr(getTrueTemp(x + h), getRK2(x, y, h)));
				//set y to whatever K2 result is for next step.
				y = getRK2(x, y, h);
			}

			printf("\n");
		}

		/*if user input 3 run Range - Kutta 3rd method*/
		if (check == 3) {
			h = getH(check2);

			printf("Time(seconds)	Exact Temp(C)	Estimated Temp(C)	Percentage Error(%%):\n");

			/*for loop to display time(x) trueTemp(y), eulerTemp(y) and %err by calling functions*/
			for (x = 0; x <= 2.0 - h; x += h) {
				printf("%0.2f		%0.3f		%0.3f			%0.2f	 \n", x + h, getTrueTemp(x + h), getRK3(x, y, h), getPercentErr(getTrueTemp(x + h), getRK3(x, y, h)));
				//set y to whatever K3 result is for next step.
				y = getRK3(x, y, h);
			}

			printf("\n");
		}

		/*if user input 4 run Range - Kutta 4th method*/
		if (check == 4) {
			h = getH(check2);

			printf("Time(seconds)	Exact Temp(C)	Estimated Temp(C)	Percentage Error(%%):\n");
			/*for loop to display time(x) trueTemp(y), eulerTemp(y) and %err by calling functions*/
			for (x = 0; x <= 2.0 - h; x += h) {
				printf("%0.2f		%0.3f		%0.3f			%0.2f	 \n", x + h, getTrueTemp(x + h), getRK4(x, y, h), getPercentErr(getTrueTemp(x + h), getRK4(x, y, h)));
				//set y to whatever K4 result is for next step.
				y = getRK4(x, y, h);
			}

			printf("\n");
		}

		// if user input 5 exit program
		if (check == 5) {
			printf("Exit");
			return 0;
		}

		// reset y and x to f(0) after doing a method loop;
		x = 0;
		y = 3;

	}

}


/********************************************************************************
Function name:		getTrueTemp
Purpose:			gets y value at given x by using equation given for true temp
In parameters:		double x
Out parameters:		return ans
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getTrueTemp(double x) {
	double ans = (0.1 * cos(4 * x)) + (0.2 * sin(4 * x)) + (2.9 * exp(-2 * x));

	return ans;
}

/********************************************************************************
Function name:		getEulerTemp
Purpose:			gets y value at given x and h by using Euler method equation
In parameters:		double x, double y, double h
Out parameters:		return ans
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getEulerTemp(double x, double y, double h) {
	double ans = y + h * (cos(4 * x) - 2 * (y));

	return ans;
}

/********************************************************************************
Function name:		getRK2
Purpose:			gets y value at given x and h by using Range-Kutta 2nd method equation
In parameters:		double x, double y, double h
Out parameters:		return y1
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getRK2(double x, double y, double h) {
	double K1 = cos(4 * x) - 2 * (y);
	double K2 = cos(4 * (x+h)) - 2 * ((y+(K1*h)));
	double y1 = y + (h/2)*(K1 + K2);

	return y1;
}

/********************************************************************************
Function name:		getRK3
Purpose:			gets y value at given x and h by using Range-Kutta 3rd method equation
In parameters:		double x, double y, double h
Out parameters:		return y1
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getRK3(double x, double y, double h) {

	double K1 = cos(4 * x) - 2 * (y);
	double K2 = cos(4 * (x + (h / 2))) - 2 * ((y + ((0.5 * K1) * h)));
	double K3 = cos(4 * (x + h)) - 2 * ((y - (K1 * h) + 2 * (K2 * h)));
	double y1 = y + (h / 6) * (K1 + (4 * K2) + K3);

	return y1;
}

/********************************************************************************
Function name:		getRK4
Purpose:			gets y value at given x and h by using Range-Kutta 4th method equation
In parameters:		double x, double y, double h
Out parameters:		return y1
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getRK4(double x, double y, double h) {

	double K1 = cos(4 * x) - 2 * (y);
	double K2 = cos(4 * (x + (h / 2))) - 2 * ((y + ((0.5 * K1) * h)));
	double K3 = cos(4 * (x + (h / 2))) - 2 * ((y + ((0.5 * K2) * h)));
	double K4 = cos(4 * (x + h)) - 2 * ((y + (K3 * h)));
	double y1 = y + (h / 6) * (K1 + (2 * K2) + (2 * K3) + K4);

	return y1;
}

/********************************************************************************
Function name:		getPercentErr
Purpose:			gets %err by using given true y and estimated y and using %err equation
In parameters:		double trueValue, double testValue
Out parameters:		return errPercent
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getPercentErr(double trueValue, double testValue) {
	double errPercent = (testValue - trueValue) / trueValue;
	errPercent = errPercent * 100;

	if (errPercent < 0) {
		errPercent *= -1;
	}

	return errPercent;
}

/********************************************************************************
Function name:		getH
Purpose:			gets valid h from user
In parameters:		double check2
Out parameters:		return check2
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getH(double check2) {

	printf("\n>> Choose step size [h] (0.8, 0.2, 0.05) \n\n");

	/*get input from user and check if valid*/
	for (int i = 0; i == 0;) {
		printf(">>");
		scanf("%lf", &check2);
		getchar();

		/*if check is 0.2, 0.8, 0.05 input is good*/
		if (check2 == 0.2 || check2 == 0.8 || check2 == 0.05) {
			i = 1;
		}
		else {
			printf("invalid input\n");
		}
	}

	return check2;
};