#include <stdio.h>

#define BITS sizeof(int)*8


void printBinary(int number, int nbitsToPrint)
{
    // Prints the binary representation
    // of the given number up to nbitsToPrint from LSB.
    int i;

    for (i = nbitsToPrint - 1; i >= 0; i--) {
        if ((number >> i) & 1)
            printf("1");
        else
            printf("0");

        if ((i % 4) == 0)
            printf(" ");
    }

    printf(" (in binary)\n");
}

int getNthBitFromLSB(int number, int nthBit)
{
    int result;

    /* Right-shift the given number by nthBit and then perform bitwise AND with 1 */
    result = (number >> nthBit) & 1;

    printf("The %dth bit is %d\n", nthBit, result);
    return result;    
}

void setNthBitFromLSB(int* number, int nthBit)
{
    /* Left-shift 1 by nthBit and then perform bitwise OR with the given number */
    *number = (1 << nthBit) | *number;

    printf("After setting %dth bit:\t", nthBit);
    printf("%d (in decimal)\t", *number);
    printBinary(*number, BITS);
}

void clearNthBitFromLSB(int* number, int nthBit)
{
    /* Left-shift 1 by nthBit, toggle all the bits, and then perform bitwise AND with the given number */
    *number = ~(1 << nthBit) & *number;

    printf("After clearing %dth bit:\t", nthBit);
    printf("%d (in decimal)\t", *number);
    printBinary(*number, BITS);
}

int countOne(int number)
{
    int i;
    int count = 0;
    int value = number;

    for (i = 0; i < BITS; i++) {
        if (value & 1) {
            count++;
        }
        value = value >> 1;
    }
    
    return count;
}

int main(void)
{
    int result;
    int nthBit;
    int intNumber;
        
    // We are going to process an integer number
    printf("Enter an int number: ");    
    scanf("%d", &intNumber);    

    printf("%d (in decimal)\t", intNumber);
    printBinary(intNumber, BITS);
    
    result = countOne(intNumber);
    printf("The number of '1's is %d\n", result);
    
    printf("\nEnter a bit position to experiment with (from LSB): ");
    scanf("%d", &nthBit);
    
    setNthBitFromLSB(&intNumber, nthBit);
    result = getNthBitFromLSB(intNumber, nthBit);
    clearNthBitFromLSB(&intNumber, nthBit);
    result = getNthBitFromLSB(intNumber, nthBit);
    
    return 0;
}