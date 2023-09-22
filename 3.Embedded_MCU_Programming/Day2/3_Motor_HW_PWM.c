#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#define PIN 18
#define PWM_CLOCK_DIVISOR 384   // This will generate 50,000 Hz from 19.2 MHz clock source
#define PWM_RANGE 1024          // The total number of clock ticks during a period
                                // This is equivalent to a period of 20 ms

void moveMotor(int degree)
{
    float dutyCycle;        // the unit is %
    int pulseWidth;         

    /////////////////////////////////////////////////////////////////////
    dutyCycle = 2 + (degree / 180.0) * 10;
    pulseWidth = PWM_RANGE * (dutyCycle/100.0);
    printf("dutyCycle = %f\n", dutyCycle);
    printf("pulseWidth = %d\n", pulseWidth);

    pwmWrite(PIN, pulseWidth);
    /////////////////////////////////////////////////////////////////////
}
#if 0
int main(void) 
{
    int inputValue;

    wiringPiSetupGpio();

    /////////////////////////////////////////////////////////////////////
    // Insert your code here
    // Your code should initialize PWM by using the following functions
    // --> pinMode(), pwmSetMode(), pwmSetClock(), pwmSetRange()
    /////////////////////////////////////////////////////////////////////
    pinMode(PIN, PWM_OUTPUT);
    pwmSetMode(PWM_MODE_BAL);
    pwmSetClock(PWM_CLOCK_DIVISOR);
    pwmSetRange(PWM_RANGE);
        
    while(1) 
    {
        printf("Enter value: ");
        scanf("%d", &inputValue);
        
        moveMotor(inputValue);
        
        delay(600);
    }    
    
    return 0;
}
#endif