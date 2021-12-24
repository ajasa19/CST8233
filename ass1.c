/********************************************************************************
Filename:			ass1.c
Version:			1.0
Author:				Asim Jasarevic
StudentNo:			040922815
Course Name/Number:	Numerical Computing 20F_CST8233–300
Lab Sect:			303
Assignment #:		1
Assignment name:	Maclurin Series Application
Due Date:			2020, Oct, 09
Submission Date:	2020, Oct, 08
Professor:			Hala Own
Purpose:			Conatins both main and all functions main calls. main runs a menu loop which takes user inptus and then calls functions passing input
					values and printing out results. Functions do math relating to the passed values and return outcomes.
All files:			ass1.c
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// include 
#include <stdio.h>
#include <math.h>

// Function Prototypes
double getSeries(double range, int term);
double getExact(double B);
double getRelativeError(double Exact, double Series);
double getTruncationError(double Exact, double nextSeries, double Series);

/********************************************************************************
Function name:		main
Purpose:			run program handel all user inputs, function calls, and displayed menu
In parameters:		
Out parameters:		return 0
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
int main() 
{
	int check; /*used to break the for loop which displays menu*/
	int termInput; /*user input for term passed to functions*/
	double rangeInput; /*user input for range passed to functions*/
	char menuInput = '0'; /*user input for menu*/

	/*for loop to display menu exits if check is not 0*/
	for (check = 0; check == 0; ) {
		printf("\n1: Evaluate Series");
		printf("\n2: quit");

		scanf("\n%c", &menuInput); /*get menu input from user*/
		fflush(stdin); /*free scanf*/

		/*if user enters 1 start process for evaluating the series*/
		if (menuInput == '1') {
			printf("\nEvaluating the series");

			printf("\nPlease enter the number of (non-zero) terms in series (1, 2, 3, 4, 5, 6):");
			scanf("\n%d", &termInput); /*get term input from user*/
			while (termInput < 1 || termInput > 6) /*while loop to make sure input is valid*/
			{
				fflush(stdin); /*free scanf*/
				printf("\nInvalid option");
				printf("\nPlease enter the number of (non-zero) terms in series (1, 2, 3, 4, 5, 6):");
				scanf("\n%d", &termInput); /*get term input from user*/
			}


			printf("\nPlease enter the range of B to evaluate in 10 increments (0.0 < B <=0.9):");
			scanf("%lf", &rangeInput); /*get range input from user*/
			while (rangeInput < 0.0 || rangeInput > 0.9) /*while loop to make sure input is valid*/
			{
				fflush(stdin); /*free scanf*/
				printf("\nInvalid option"); 
				printf("\nPlease enter the range of B to evaluate in 10 increments (0.0 < B <=0.9):");
				scanf("%lf", &rangeInput); /*get range input from user*/
			} 


			fflush(stdin); /*free scanf*/

				
			printf("\n B        V(B) Series      V(B)Exact       RelativeError     %%RSerE");
			for (double n = rangeInput; n < rangeInput * 10; n += rangeInput) /*for loop to display values related to user input 10*/
			{
					/*printf which calls 4 functions each returning a value related to the user input (B, V(B) Series, V(B)Exact, RelativeError, %RSerE)*/
					printf("\n%0.2f     %0.9f     %0.9f     %E     %E", n, getSeries(n, termInput), getExact(n), getRelativeError(getExact(n), getSeries(n, termInput)), getTruncationError(getExact(n), getSeries(n, termInput + 1), getSeries(n, termInput)) );
			} 

			}

			/*if to see if user pressed 2*/
			if (menuInput == '2') {
				check++; /*adds to check which causes breaks out of forloop*/
			}
			else if (menuInput != '1') /*if the menu input is not 1 or 2 then print invalid statment*/
			{
				printf("\nNot a valid input");
			}

		} /*end of menu for loop*/

	
	return 0;
}


/********************************************************************************
Function name:		getSeries
Purpose:			get value of V in maclurin series calculation without using math.h functions
In parameters:		double range, int term
Out parameters:		return V
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getSeries(double range, int term) {

	    double fraction[] = { 0.0, 0.5 ,0.375 ,0.3125,0.2734375,0.24609375,0.225585937, 0.209472656}; /*array containing fractions for each maclurin series at a specific term*/
		double V = 1.0; /*answer for the maclurin equation*/
		double x = range; /*used as a power*/
		double temp = 0.0; /*temp answer holds sum at only one term in maclurin equation*/
		double power = 1.0; /*used as starting point of power of range*/

		/*for loop to get V depending on user inputed term*/
		for (int i = 0; i <= term; i++) {

			/*if i is more then 1 power is also more then 1*/
			if (i > 1) {
				power = power * x; /*get power of range*/
				power = power * x; /*get power of range*/
			}

			/*if i is more then 1 fraction is also more then 1/1*/
			if (i > 0) {
				temp = fraction[i - 1] * power; /*get V at term(i)*/
			}

			V = V + temp; /*get sum of V for complete maclurin equation*/

		}
	return V; /*return V from maclurin equation*/
}

/********************************************************************************
Function name:		getExact
Purpose:			get value of V in exact calculation using math.h functions
In parameters:		double B
Out parameters:		return V
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getExact(double B) {
	double V = 0.0; /*answer for exact equation*/

	V = 1 / (sqrt(1 - pow(B, 2))); /*get answer for exact equation*/

	return V; /*return V from exact equation*/
}

/********************************************************************************
Function name:		getRelativeError
Purpose:			gets relative error by using relative error equation
In parameters:		double Exact, double Series
Out parameters:		return relativeError
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getRelativeError(double Exact, double Series) {
	double absoluteError = Exact - Series; /*gets absoluteError by suptracting given values*/
	double relativeError = absoluteError / Exact; /*gets relativeError by dividing absoluteError by Exact*/

	return relativeError; /*return relativeError value*/
}

/********************************************************************************
Function name:		getTruncationError
Purpose:			gets truncation error % by preforming truncation error % equation using passed function values
In parameters:		double Exact, double nextSeries, double Series
Out parameters:		return truncationError
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
double getTruncationError(double Exact, double nextSeries, double Series) {
	double truncationError = 0.0; /*Final value for truncationError*/

	double firstTruncatedTerm = nextSeries - Series; /*first find value of firstTruncatedTerm by subtracting the next series term by  current series term */
	double fraction = firstTruncatedTerm / Series; /*get value the fraction using [firstTruncatedTerm/series]*/

	truncationError = 100 * fraction; /*get value the truncationError using [firstTruncatedTerm/series] * [series]*/

	return truncationError; /*return truncationError value*/
}