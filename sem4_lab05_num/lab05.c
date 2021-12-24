#define _CRT_SECURE_NO_WARNINGS
#define M_PI acos(-1.0)
#include <stdio.h>

#include <math.h>

int main()
{

	double x = M_PI / 3;
	double exact = 0.0;
	double mac = 1.0;
	double absolute = 0.0;
	double relative = 0.0;
	double fractions[] = { 0.0, 0.5, 0.041666666, 0.0013888888, 0.000024801,0.000000275};
	double macAnswer[10];
	double absoluteAnswer[10];
	double relativeAnswer[10];
	double power = 1.0;

	exact = cos(x);

	double errorbound = 0.0;

	printf("enter errorbound: ");
	scanf("%lf", &errorbound);

	for (int i = 0; i < 6; i++) {

		if (i > 1) {
			power = power * x; /*get power of range*/
			power = power * x; /*get power of range*/
		}

		if (i % 2 == 0)
			mac = mac + (fractions[i] * pow(x, (i * 2)));
		else
			mac = mac - (fractions[i] * pow(x,(i*2)));

		macAnswer[i] = mac;


		absolute = exact - macAnswer[i];
		if (absolute < 0) {
			absolute = absolute * -1;
		}
		absoluteAnswer[i] = absolute;

		if (absolute < errorbound) {
			errorbound = i+1;
				i = 6;
		}

	}

	for (int i = 0; i < errorbound; i++) {
		relative = absoluteAnswer[i] / macAnswer[i];
		relativeAnswer[i] = relative * 100;
	}
		printf("\nN.terms        Exact           aprociximate value         absolute error        %trelative error");
	for (int i = 1; i < errorbound; i++) {
		printf("\n%d            %0.6f            %0.06f                 %0.06f             %0.06f", i+1, exact, macAnswer[i], absoluteAnswer[i], relativeAnswer[i]);
	}



	return 0;
}