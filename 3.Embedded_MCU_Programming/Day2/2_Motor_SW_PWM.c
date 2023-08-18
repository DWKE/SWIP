#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PIN 18
#define PWM_RANGE 200

void moveMotor(int degree)
{
    float dutyCycle;        // the unit is %
    int pulseWidth;

    // Insert your code here
    dutyCycle = 2 + (degree / 180.0) * 10;        // the unit is %
    pulseWidth = dutyCycle * (PWM_RANGE/100.0);
    printf("dutyCycle = %f\n", dutyCycle);
    printf("pulseWidth = %d\n", pulseWidth);
    
    softPwmWrite(PIN, pulseWidth);
}
#if 1
int main() 
{
    int inputValue;         // the unit is degree
    
    wiringPiSetupGpio();
    pinMode(PIN, OUTPUT);

    // Set PWM range (= the total number of clock ticks during a period)
    softPwmCreate(PIN, 0, PWM_RANGE);

    while(1) 
    {     
        printf("Enter the position of motor (in degree): ");
        scanf("%d", &inputValue);
        
        moveMotor(inputValue);
        
        delay(600);
    }

    return 0;
}
#endif