#include <stdio.h>
#include <wiringPi.h>

#define GPIO_LED 4
#define GPIO_SWITCH 13

int main(void) 
{
    int switchState;
    int ledState = LOW;
    int toggleFlag;

    wiringPiSetupGpio();

    pinMode(GPIO_LED, OUTPUT);
    pinMode(GPIO_SWITCH, INPUT);
    
    while(1) 
    {
        // switchState = digitalRead(GPIO_SWITCH);

        toggleFlag = 1;

        for (int i = 0; i < 10000; i++) {
            if (digitalRead(GPIO_SWITCH) == LOW) {
                toggleFlag = 0;
            }
        }

        if(toggleFlag) {
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
