#include <stdio.h>

#include <wiringPi.h>

#include "rpi_2_can.h"
#include "rpi_2_stub.h"
#include "rpi_2_motor.h"
#include "rpi_2_lcd.h"

int main()
{
    int ret;
    
    // Initialize
    ret = wiringPiSetupGpio();
    ret = initializeCAN();
    ret = initializeServerMotor();
    ret = initializeLCD();

    // Step 1. Start RPC server
    printf("\nRPi #2 is ready to accept RPC requests.\n\n");
    ret = runRPCServer(10);
    
    // Step 2. Now the runRPCServer() function has the control and serves RPC requests

    // Step 3. Terminate RPC server
    ret = terminateCAN();
    printf("Terminating RPi #2.\n\n", ret);

    return 0;
}
