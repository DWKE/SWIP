#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>

#include "1_LCD.h"

#define Trig    23
#define Echo    24

// #define LED 17

float measureDistance(void) ;

#if 0
int main(void) 
{	
    float distance;

    struct timeval tv1;
    struct timeval tv2;

    wiringPiSetupGpio();
    deviceHandle = wiringPiI2CSetup(Detected_DEVICE_ID_BY_I2C); 
    initializeLCD();
    
    pinMode(Echo, INPUT);
    pinMode(Trig, OUTPUT);
    // pinMode(LED, OUTPUT);

    while(1) 
    {
        distance = measureDistance();
        // printf("%0.2f cm\n", distance);
        
        // if (distance < 10.0)
        //     digitalWrite(LED, 1);
        // else
        //     digitalWrite(LED, 0);

        char distance_string[20] = "XXX";

        sprintf(distance_string, "%g", distance);

        displayText(distance_string);
        displayText("cm");
        
        delay(500);

        sendBitsToLCD(0x01, LCD_RS_INST | LCD_RW_WRITE);  // "0000 0001" (clear display)
    }	
    
    return 0;
}
#endif

float measureDistance(void) 
{   
    digitalWrite(Trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);

    while(digitalRead(Echo) == LOW)
    {
        delayMicroseconds(10);
    }

    struct timeval send_timeval;
    gettimeofday(&send_timeval, NULL);

    while(digitalRead(Echo) == HIGH)
    {
        delayMicroseconds(10);
    }

    struct timeval receive_timeval;
    gettimeofday(&receive_timeval, NULL);

    long send_time = send_timeval.tv_sec * 1000000 + send_timeval.tv_usec;
    long receive_time = receive_timeval.tv_sec * 1000000 + receive_timeval.tv_usec;

    float time_interval = receive_time - send_time;

    float distance = (0.034 * time_interval) / 2;

    return distance;

}