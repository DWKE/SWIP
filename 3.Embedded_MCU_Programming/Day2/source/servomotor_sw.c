#include <wiringPi.h>
#include <stdio.h>
#include <softPwm.h>

#define PIN 18
#define PWM_RANGE 200

void moveMotor(int degree)
{
    float dutyCycle;        // the unit is %
    int pulseWidth;         

    dutyCycle = ((float)(degree*5)/180 + 5.0);
    pulseWidth = dutyCycle*(PWM_RANGE/100);

    softPwmWrite(PIN, pulseWidth);

    printf("dutyCycle = %0.1f\%\n", dutyCycle);
    printf("pulseWidth = %d\n", pulseWidth);
    printf("\n");

    return;
}

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
