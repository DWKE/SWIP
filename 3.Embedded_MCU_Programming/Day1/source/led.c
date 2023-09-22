#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 17

// #define HIGH 1       // defined in "wiringPi.h"
// #define LOW 0        // defined in "wiringPi.h"

int main(void) 
{
    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);

    while(1) {
        digitalWrite(GPIO_LED, HIGH);
        delay(1000);
        
        digitalWrite(GPIO_LED, LOW);
        delay(1000);
    }
}
