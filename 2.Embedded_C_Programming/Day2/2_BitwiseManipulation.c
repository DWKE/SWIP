#include <stdio.h>

int getNthBitFromLSB(int number, int nthBit);
void setNthBitFromLSB(int* number, int nthBit);
void clearNthBitFromLSB(int* number, int nthBit);
int countOne(int number);
void printBinary(int number, int nbitsToPrint);

#if 0
int main(void)
{
    int number, nthBit;

    printf("Enter an int number: ");
    scanf("%d", &number);
    printf("printBinary: ");
    printBinary(number, sizeof(number)*8);
    printf("The number of '1' is %d\n", countOne(number));

    printf("Enter a bit position to experiment with (from LSB): ");
    scanf("%d", &nthBit);

    printf("After setting %dth bit:         ", nthBit);
    setNthBitFromLSB(&number, nthBit);
    printBinary(number, sizeof(number)*8);
    printf("The %dth bit is %d\n", nthBit, getNthBitFromLSB(number, nthBit));

    printf("After clearing %dth bit:        ", nthBit);
    clearNthBitFromLSB(&number, nthBit);
    printBinary(number, sizeof(number)*8);
    printf("The %dth bit is %d\n", nthBit, getNthBitFromLSB(number, nthBit));


    return 0;
}
#endif

int getNthBitFromLSB(int number, int nthBit)
{
    return (number>>nthBit) & 1;
}

void setNthBitFromLSB(int* number, int nthBit)
{
    *number = ((*number) | (1 << nthBit));
}

void clearNthBitFromLSB(int* number, int nthBit)
{
    *number = ((*number) & ~(1 << nthBit));
}

int countOne(int number)
{
    int cnt = 0;
    for (int i = sizeof(number)*8-1; i >= 0; i--) {
        if ((number>>i) & 1) cnt++;
    }
    return cnt;
}

void printBinary(int number, int nbitsToPrint)
{
    printf("%d (in decimal)     ", number);
    for (int i = nbitsToPrint-1; i >= 0; i--) {
        printf("%d", (number>>i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf(" (in binary)\n");
}