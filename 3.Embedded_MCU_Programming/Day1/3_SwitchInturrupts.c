#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

int ledState = LOW;

void ledToggle();

int main(void) 
{
    int switchState;
    int ledState = LOW;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);

    wiringPiISR(GPIO_SWITCH, INT_EDGE_RISING, &ledToggle);
    
    while(1) 
    {
        delay(100);
    }
}

void ledToggle()
{
    if(ledState == LOW) {
        digitalWrite(GPIO_LED, HIGH);
        ledState = HIGH;
        printf("LED ON\n");
    } else {
        digitalWrite(GPIO_LED, LOW);
        ledState = LOW;
        printf("LED OFF\n");
    }
}