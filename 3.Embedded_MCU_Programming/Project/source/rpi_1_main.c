#include <stdio.h>
#include <string.h>
#include <pthread.h>

#include <wiringPi.h>

#include "rpi_1_can.h"
#include "rpi_1_stub.h"
#include "rpi_1_ultrasonic.h"
#include "rpi_1_led.h"
#include "rpi_1_dijkstra.h"

int main()
{
    int ret;
    float distance;
    
    pthread_t threadID[2];      // Create and run threads for LED and ultrasonic sensor
    int blinkInterval;          // Blink interval of LED (ms)

    int sourceNode = 3;         // The source node for Shortest Path
    int destinationNode = 6;    // The destination node for Shortest Path
    char shortestPath[16];      // Char array to receive the Shortest Path
    int shortestPathLen;        // Size of received shoretst path data

    char textString[128];       // Char array to receive user input 
    int executionCount = 10;    // Maximum number of interactions with RPC server
    
    // Initialize: WiringPI/GPIO and CAN 
    wiringPiSetupGpio();
    ret = initializeCAN();    
    
    printf("\nRPi #1 is ready.\n\n");

    // Step 1. Start LED
    blinkInterval = 1000;
    pthread_create(&threadID[0], NULL, blinkLED, &blinkInterval);
    printf("Started LED.\n\n");
    
    // Step 2. Request the shortest path
    findShortestPath(sourceNode, destinationNode, shortestPath, &shortestPathLen);
    printf("The shortest path is %s.\n\n", shortestPath);
    
    // Step 3. Run ultrasonic sensor to measure distance
    pthread_create(&threadID[1], NULL, mesaureAndBlinkLED, NULL);
    printf("Started Ultrasonic sensor.\n\n");    
    
    // Step 4. Move the motor at RPi #2
    ret = moveMotor(120);
    printf("Requested RPC moveMotor() and received return value %d\n", ret);

    // Step 5. Display test strings on the LCD at at RPi #2
    ret = displayText(1, shortestPath);
    ret = displayText(2, "You made it!");
    printf("Requested RPC displayText() and received return value %d\n", ret);
    
    // Step 6. Get text from user and display it on the LCD at at RPi #2
    while (executionCount > 0) {
        printf("Enter your text to display on RPi #2's LCD: ");
        fgets(textString, 128, stdin);

        if (textString[0] != 'q') {
            ret = displayText(1, textString);
        }
        else {
            ret = terminateRPC(textString);
            break;
        }

        bzero(textString, 128);
        executionCount--;
    }
    
    // Terminate
    ret = terminateCAN();
    printf("\nTerminating RPi #1.\n\n", ret);

    return 0;
}
