#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

int main(void) 
{
    int switchState;
    int ledState = LOW;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);
    
    while(1) 
    {
        switchState = digitalRead(GPIO_SWITCH);

        if(switchState == HIGH) {
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

        delay(100);
    }
}
