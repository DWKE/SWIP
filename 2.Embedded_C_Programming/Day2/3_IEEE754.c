#include <stdio.h>

typedef union {
    float f;
    unsigned u;
    struct {
        unsigned mantissa : 23;
        unsigned exponent : 8;
        unsigned sign: 1;
    } raw;
} ufloat;

extern void printBinary(int number, int nbitsToPrint);

int main(void)
{
    float number;
    printf("Enter a float number: ");
    scanf("%f", &number);

    ufloat value = { .f = number };

    printf("Breakdown of %f\n", number);
    printf("Sign:       ");
    printBinary(value.raw.sign, 1);
    printf("Exponent:   ");
    printBinary(value.raw.exponent, 8);
    printf("Mantissa:   ");
    printBinary(value.raw.mantissa, 23);

    return 0;
}
