
#include <math.h>
#include <stdio.h>

int convertBintoDec(long long decimal);
long long convertDectoBin(int num);
long long convertDectoBinFraction(long double fraDecimal);
long long convertBintoDecFraction(int binaryBeforeDec, char binaryAfterDec[30]);
char input;

int main() {

    for (int menuExit = 0; menuExit == 0; ) {

        printf("Would you like to: \n [A]Convert Dec -> Bin \n [B]Convert Bin -> Dec \n [C]Convert Dec Fraction -> Bin \n [D]Convert Bin Fraction -> Dec \n [F]Kill me \n Enter Input: ");
        scanf_s(" %c", &input);


        if (input == 'a' || input == 'A') {
            int decimal;
            printf("\n Enter a decimal number: ");
            scanf_s("%d", &decimal);
            printf("%d in decimal = %d in binary", decimal, convertDectoBin(decimal));
        }

        if (input == 'b' || input == 'B') {
            long long num;
            printf("\n Enter a binary number: ");
            scanf_s("%lld", &num);
            printf("%lld in binary = %d in decimal", num, convertBintoDec(num));
        }

        if (input == 'c' || input == 'C') {
            long double decimal;

            printf("\n Enter fractional decimal number: ");
            scanf_s("%Lf", &decimal);
            convertDectoBinFraction(decimal);
        }

        if (input == 'd' || input == 'D') {
            int binaryBeforeDec;
            char str[30];

            printf("\n Enter fractional binary number before decimal: ");
            scanf_s("%d", &binaryBeforeDec);
            printf("\n Enter fractional binary number after decimal: ");
            scanf_s("%s", str, sizeof str);
            printf("\n number: %d.%s " , binaryBeforeDec, str);
            convertBintoDecFraction(binaryBeforeDec, str);
        }

        if (input == 'f' || input == 'F') {

            printf("\nI am dead");
            menuExit = 1;

            return 0;
        }

        printf("\n\n");
    }
}

long long convertDectoBin(int decimal) {

    long long binary = 0;
    int remainder, i = 1;

    while (decimal != 0) {
        remainder = decimal % 2;
       // printf("\n remainder = %d", remainder);
        decimal /= 2;
       // printf("\n dec = %d", decimal);
        binary += remainder * i;
       // printf("\n i = %d", i);
        i *= 10;
    }

    return binary;
}

int convertBintoDec(long long binary) {

    int decimal = 0, i = 0, remainder;

    while (binary != 0) {
        remainder = binary % 10;
        //printf("\n remainder = %d", remainder);
        binary /= 10;
        //printf("\n binary = %lf", binary);
        decimal += remainder * pow(2, i);
        //printf("\n decimal = %d", decimal);
        ++i;
    }

    return decimal;
}

long long convertDectoBinFraction(long double decimal) {
    long double binary, binaryFrac = 0.0, decimalFrac, fraFactor = 0.1;
    long int decimalIntegral, binaryIntegral = 0;
    long int intFactor = 1, remainder, temp, i;

    decimalIntegral = decimal;
    decimalFrac = decimal - decimalIntegral;

    while (decimalIntegral != 0) {
        remainder = decimalIntegral % 2;
        binaryIntegral = binaryIntegral + remainder * intFactor;
        decimalIntegral /= 2;
        intFactor = intFactor * 10;
    }

    for (i = 1; i <= 25; i++) {

        decimalFrac *= 2;
        temp = decimalFrac;

        binaryFrac = binaryFrac + fraFactor * temp;
        if (temp == 1)
            decimalFrac -= temp;

        fraFactor = fraFactor / 10;
    }

    binary = binaryIntegral + binaryFrac;
    printf("Equivalent binary value: %.10lf", binary);
}

long long convertBintoDecFraction(int binaryBeforeDec, char binaryAfterDec[30]) {
    double answer, function = 0.0, fractionBinaryArray[20], facsum = 0;
    int sum = 0, decimal, i = 0, remainder, fractionArray[20];
    char fractionArrayChar[21];
    char frac[30];

    decimal = binaryBeforeDec;
    //printf("\ndec = %d", decimal);
    strcpy(frac, binaryAfterDec);
    //printf("\nfrac = %s", frac);
    while (decimal != 0)
    {
        remainder = decimal % 10;
        decimal /= 10;
        sum = sum + (remainder * pow(2, (i++)));
    }

    for (int i = 0; i < 20; i++) {
        if (frac[i] == '1') {
            fractionArray[i] = 1;
        }
        else { fractionArray[i] = 0; }
       // printf("\nfracarray = %d", fractionArray[i]);
    }

        for (int i = 0; i < 20; i++) {

            if (fractionArray[i] == 1) {
            fractionBinaryArray[i] = pow(2, -(i+1));

            facsum += fractionBinaryArray[i];
            //printf("\nfracsum = %.15f", facsum);
                }
            }

        answer = sum + facsum;
   printf("\nThe decimal equivalent is %.3lf", answer);
}
