#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXDIGITS	512		/* maximum length bignum */ 

#define PLUS		1		/* positive sign bit */
#define MINUS		-1		/* negative sign bit */

typedef struct {
    char integerPart[MAXDIGITS];     	/* represent the integer part, the last array element is LSB*/
	char fractionPart[MAXDIGITS];		/* represent the fraction part */
	int signPart;						/* 1 if positive, -1 if negative */ 
    int digitsTotal;					/* total number of digits */
} BigNum;

void convertStringToBigNumber(char string[], BigNum* bigNumber)
{
	int i;
	int len = strlen(string);
	//printf("\nlen = %d\n", len);

	if (string[0] == '-') {
		bigNumber->signPart = MINUS;
		bigNumber->digitsTotal = len - 1;
		for (i = MAXDIGITS - bigNumber->digitsTotal; i < MAXDIGITS; i++) {
			bigNumber->integerPart[i] = string[i - MAXDIGITS + bigNumber->digitsTotal] - 48;
		}
	}
	else {
		bigNumber->signPart = PLUS;
		bigNumber->digitsTotal = len;
		for (i = MAXDIGITS - bigNumber->digitsTotal; i < MAXDIGITS; i++) {
			bigNumber->integerPart[i] = string[i - MAXDIGITS + bigNumber->digitsTotal] - 48;
			//printf(" %d ", (int)(bigNumber->integerPart[i]));
		}
	}
}

void printBigNumber(BigNum *bigNumber)
{
	int i;

	if (bigNumber->signPart == MINUS) 
		printf("(-) ");

	for (i = MAXDIGITS - bigNumber->digitsTotal; i < MAXDIGITS; i++) {
		printf("%d", (int)(bigNumber->integerPart[i]));
	}
}

void addPositiveBigNumber(BigNum *first, BigNum *second, BigNum *result)
{
	int i;
	int totalDigitsMax;
	int sum;
	int carry = 0;

	totalDigitsMax = first->digitsTotal;
	if (totalDigitsMax < second->digitsTotal) {
		totalDigitsMax = second->digitsTotal;
	}

	for (i = MAXDIGITS - 1; i > MAXDIGITS - totalDigitsMax - 1; i--) {
		sum = first->integerPart[i] + second->integerPart[i] + carry;
		if (sum > 9) {
			carry = 1;
			result->integerPart[i] = sum % 10;
		}
		else {
			carry = 0;
			result->integerPart[i] = sum;
		}
	}

	if (carry == 1) {
		result->digitsTotal = totalDigitsMax + 1;
		result->signPart = PLUS;
		result->integerPart[i] = 1;
	}
	else {
		result->digitsTotal = totalDigitsMax;
		result->signPart = PLUS;
	}

}


int main()
{
	char firstValue[MAXDIGITS];
	char secondValue[MAXDIGITS];

	BigNum firstBigNumber;
	BigNum secondBigNumber;
	BigNum thirdBigNumber;

	printf("Enter the first big integer = ");
	scanf("%s", firstValue);
	printf("Enter the second big integer = ");
	scanf("%s", secondValue);

	convertStringToBigNumber(firstValue, &firstBigNumber);
	convertStringToBigNumber(secondValue, &secondBigNumber);

	printBigNumber(&firstBigNumber);
	printf(" + ");
	printBigNumber(&secondBigNumber);

	addPositiveBigNumber(&firstBigNumber, &secondBigNumber, &thirdBigNumber);
	printf(" = ");
	printBigNumber(&thirdBigNumber);
	printf("\n");
}