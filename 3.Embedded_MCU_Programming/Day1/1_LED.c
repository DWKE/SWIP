#include <stdio.h>
#include <wiringPi.h>

#define LED_PIN 17

int main(void)
{
    if(wiringPiSetupGpio() == 0) {

        printf("WiringPi GPIO setup OK.\n");
        
        pinMode(LED_PIN, OUTPUT);

        while(1)
        {
            digitalWrite(LED_PIN, HIGH);
            printf("%d\n", digitalRead(LED_PIN));
            delay(1000);
            digitalWrite(LED_PIN, LOW);
            printf("%d\n", digitalRead(LED_PIN));
            delay(1000);
        }
    }
    else {
        printf("WiringPi GPIO setup error.\n");
    }

    return 0;
}