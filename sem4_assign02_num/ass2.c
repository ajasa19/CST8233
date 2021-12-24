/********************************************************************************
Filename:			ass2.c
Version:			1.0
Author:				Asim Jasarevic
StudentNo:			040922815
Course Name/Number:	Numerical Computing 20F_CST8233–300
Lab Sect:			303
Assignment #:		2
Assignment name:	Moore's Law
Due Date:			2020, Nov, 20
Submission Date:	2020, Nov, 18
Professor:			Hala Own
Purpose:			Take txt file as data points and find the exponential growth using exponetial model, 
					allow user to exstrapolate to any x point(year) and give a predicted y and rate of growth
All files:			ass2.c
********************************************************************************/

#define _CRT_SECURE_NO_WARNINGS

// include 
#include <stdio.h>
#include <math.h>

/********************************************************************************
Function name:		main
Purpose:			run program handel all user inputs, display menu, and calculate values
In parameters:
Out parameters:		return 0
Version:			1.0
Author:				Asim Jasarevic
********************************************************************************/
int main()
{
	int check = 0; /*used to break the for loop which displays menu*/
	int termInput; /*user input for term passed to functions*/
	double rangeInput; /*user input for range passed to functions*/
	char menuInput = '0'; /*user input for menu*/
	char fileName[15]; /*file name to read from*/
	char year[15][5]; /*2d array to hold year as string from file*/
	char tranCount[15][10]; /*2d array to hold tranCount as string from file*/
	int  yearInt[15]; /*2d array to hold year as int*/
	double  tranCountDouble[15]; /*2d array to hold tranCountDouble as double*/
	char ch = ""; /*used for current char when reading file*/
	int i = 0; /*used as first index of 2d array*/
	int n = 0; /*used as second index of 2d array*/
	int charCount = 0; /*char counter for reading file*/
	int interval = 0; /*used to switch between arrays when loading data from file*/
	int x = 0, x2 = 0; /*x and x2 values*/
	long double  y = 0, xy = 0, a1 = 0, a0 = 0, a0e = 0, rateInc = 0; /*values realting to fit equation*/
	int tempX = 0; /*user inputed year for extrapolating*/
	long double ans = 0; /*ans for user input*/

	/*for loop to display main menu*/
	for (int menueExit = 0; menueExit == 0 ; ) {
		printf("			LEAST_SQUARES LINEAR REGRESSION\n");
		printf("MENUE\n1. Exponential Fit\n2. Quit\n");

		/*get input from user ad check if valid*/
		for (int i = 0; i == 0;){
		scanf("%d", &check);
		getchar();

		/*if check is 1 or 2 input is good*/
		if (check == 1 || check == 2 ) {
			i = 1;
		}
		else {
			printf("invalid input\n");
		}
		}

		/*if user menu input is 1 get file name*/
		if (check == 1) {
			printf("Enter file name: ");
			scanf("%[^\n]", fileName);
			fflush(stdin);

			FILE* fptr;
			/*if file name enterd is not found kill program*/
			if ((fptr = fopen(fileName, "r")) == NULL) {
				printf("Error! opening file");
				/* Program exits if file pointer returns NULL.*/
				exit(1);
			}

			/*while loop to read each char in file*/
			while ((ch = fgetc(fptr)) != EOF) {

				/*if to get years and load into year array*/
				if (ch != ' ' && ch != '\n' && charCount < 4) {
					year[n][i] = ch;
					i++;
				}

				/*if to add string end to year array*/
				if (charCount == 4) {
					year[n][i] = '\0';
				}

				/*if to get tranCount and load into tranCount array*/
				if (ch != ' ' && ch != '\n' && charCount > 15 && charCount < 25) {
					tranCount[n][i] = ch;
					i++;
				}

				/*if to add string end to tranCount array*/
				if (charCount == 25) {
					tranCount[n][i] = '\0';
				}

				charCount++;

				/*if to reset index after reading a number of spaces*/
				if (charCount == 6 || charCount == 27) {
					i = 0;
				}
				/*if to reset index after reading new line*/
				if (ch == '\n') {
					charCount = 0;
					i = 0;
					n++;
				}
				/*print file content*/
				printf("%c", ch);
			}

			fclose(fptr);

			/*for loop to parse year string into year int array*/
			for (int i = 0; i < 15; i++) {
				yearInt[i] = atoi(year[i]);
			}

			/*for loop to parse tranCount string into tranCount double array*/
			for (int i = 0; i < 15; i++) {
				sscanf(tranCount[i], "%lf", &tranCountDouble[i]);
			}

			/*get size of year array*/
			size_t size = sizeof(yearInt) / sizeof(yearInt[1]);

			/*for loop to calculate the sum of x, y, xy, and x^2*/
			for (int i = 1; i < size; i++) {
				x += (yearInt[i] - 1970); /*get sum of x*/
				y += log(tranCountDouble[i]); /*get sum of y*/
				x2 += ((yearInt[i] - 1970) * (yearInt[i] - 1970)); /*get sum of x^2*/
				xy += ((yearInt[i] - 1970) * log(tranCountDouble[i])); /*get sum of xy*/
			}

			/*getting exponential model*/
			a1 = ((size - 1) * xy - x * y) / ((size - 1) * x2 - (x * x)); /*get a1*/
			a0 = (y - a1 * x) / (size - 1); /*get a0*/
			a0e = exp(a0); /*get a0e*/

			printf("\nThere are %d records.\n", size - 1);
			printf("\nLinear Regression Fit:  transistor count = %.03e*exp(%.03e*(year-1970))\n", a0e, a1);

			/*for loop to start sub menu*/
			for (int j = 0; j == 0;) {
				printf("\nMENUE\n1. Extrapolation\n2. Main Menu\n");

				check = 0;

				/*get menu input from user and make sure it's valid*/
				for (int i = 0; i == 0;) {
					scanf("%d", &check);
					getchar();

					/*if user menu input id 1 or 2 valid exit loop and continue else get new input*/
					if (check == 1 || check == 2) {
						i = 1;
					}
					else {
						printf("invalid input\n");
					}
				}

				/*if user menu input is 1 start calculations for extrapolation*/
				if (check == 1) {
					printf("please enter the year to extrapolate to: \n");
					scanf("%d", &tempX);

					ans = a0e * exp(a1 * (tempX-1970)); /*using exponential model to get y*/
					rateInc = ans * a1; /*using derviative of exponential model*/

					printf("Year = %d \n", tempX);
					printf("transistor count = %.03e \n", ans);
					printf("rate of count increase = %.03e \n", rateInc);
				}

				/*if user menu input 2 reset all values and go back to main menu*/
				if (check == 2) {
					j = 2;
					check = 0;
					menueExit = 0;
					ch = "";
					i = 0;
					n = 0;
					charCount = 0;
					interval = 0;
					x = 0, x2 = 0;
					y = 0, xy = 0, a1 = 0, a0 = 0, a0e = 0, rateInc = 0;
					tempX = 0;
					ans = 0;
				}
			}

			
		}

		/*if user main menu input 2 exit program*/
		if (check == 2) {
			menueExit = 2;
		}

	}

		

		



	return 0;
}

