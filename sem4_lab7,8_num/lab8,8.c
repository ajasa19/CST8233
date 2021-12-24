#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>

double getMean(int points[2][20], size_t length);
double getMedian(int points[2][20], size_t length);
double getSD(int points[2][20], size_t length, double mean);
double getRange(int points[2][20], size_t length);
void getStandraization(int points[2][20], size_t length, double mean, double SD);
int getLength(int points[2][20], size_t length);

int main()
{

	int points[2][20] = { {3,4,6,5,7,8,6,5,8,6,0,0,0,0,0,0,0,0,0,0} , {3,4,6,5,7,8,6,5,8,6,0,0,0,0,0,0,0,0,0,0} };

	double mean = 0;
	double median = 0;
	double SD = 0;
	int range = 0;
	char input;
	size_t length = sizeof(points) / sizeof(points[0][0]);

	length = getLength(points, length);




	printf("(a)Put in new points \n(b)Use test points\n");
	scanf("%c", &input);

	if (input == 'a') {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 20; j++) {
				points[i][j] = 0;
			}
		}
		int valid = 0;

		for (int i = 0; i < 20; i++) {
			printf("point [%d] = ", i);
			scanf("%d", &valid);

			if (valid > 0 && valid < 11) {
				points[0][i] = valid;
				points[1][i] = valid;
			}
			else {
				i = 21;
			}
			
		}
		size_t length = sizeof(points) / sizeof(points[0][0]);
		length = getLength(points, length);
	}

	else {
		printf("\nTest data loaded arry values = {3,4,6,5,7,8,6,5,8,6}\n");
	}


	for (int i = 0; i == 0; ) {

		int input2 = 0;

		printf("\n1 - Mean\n2 - Median\n3 - Standard deviation\n4 - Rnage\n5 - Normalization(z-score)\n6 - Exit\n7 - Output all");
		scanf("%d", &input2);

		switch (input2) {
		case 1:
			mean = getMean(points, length);
			printf("\n mean = %lf\n", mean);
			break;
		case 2:
			median = getMedian(points, length);
			printf("\n median = %lf\n", median);
			break;
		case 3:
			SD = getSD(points, length, mean);
			printf("\n SD = %lf\n", SD);
			break;
		case 4:
			range = getRange(points, length, mean);
			printf("\n range = %d\n", range);
			break;
		case 5:
			getStandraization(points, length, mean, SD);
			printf("\n");
			break;
		case 6:
			i = 1;
			break;
		case 7:
			mean = getMean(points, length);
			printf("\n mean = %lf\n", mean);

			median = getMedian(points, length);
			printf("\n median = %lf\n", median);

			SD = getSD(points, length, mean);
			printf("\n SD = %lf\n", SD);

			range = getRange(points, length, mean);
			printf("\n range = %d\n", range);

			getStandraization(points, length, mean, SD);
			printf("\n");
			break;

		default:
			printf("Invalid grade\n");
		}

	};
}

double getMean(int points[2][20], size_t length)
{
	double mean = 0;
	double pointsSum = 0;

	for (int i = 0; i < length; i++) {
		pointsSum = pointsSum + points[0][i];

	}

	mean = pointsSum / length;

	return mean;
};

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
double getMedian(int points[2][20], size_t length)
{
	int min = points[1][0], max = points[1][0];
	double median = 0;
	double pointsSum = 0;

	int i, j, min_idx;

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < length - 1; i++) {

		// Find the minimum element in unsorted array 
		min_idx = i;
		for (j = i + 1; j < length; j++)
			if (points[1][j] < points[1][min_idx])
				min_idx = j;

		// Swap the found minimum element 
		// with the first element 
		swap(&points[1][min_idx], &points[1][i]);
	}

	median = points[1][length/2];

	return median;
};

double getSD(int points[2][20], size_t length, double mean)
{
	double SD = 0;
	double pointsSum = 0;

	for (int i = 0; i < length; i++) {

		pointsSum = pow((points[0][i] - mean), 2) + pointsSum;
	}

	SD = sqrt(pointsSum / (length-1));

	return SD;
};

double getRange(int points[2][20], size_t length) {
	int max = points[0][0];
	int min = points[0][0];
	int range = 0;

	for (int i = 1; i < length; i++){
		if (points[0][i] > max)
			max = points[0][i];
	}

	for (int i = 1; i < length; i++) {
		if (points[0][i] < min)
			min = points[0][i];
	}

	range = max - min;

	return range;

}

void getStandraization(int points[2][20], size_t length, double mean, double SD) {

	double standerd = 0.0;

	printf("\n%Data after Standraization\n");

	for (int i = 0; i < length; i++) {
		standerd = (points[0][i] - mean) / SD;
		printf("\n%lf", standerd);
	}

}

int getLength(int points[2][20], size_t length) {

	int trueLength = 0;

	for (int i = 0; i < length / 2; i++) {
		if (points[0][i] != 0) {
			trueLength++;
		}
	}

	return trueLength;
}