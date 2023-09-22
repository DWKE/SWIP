#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>

#include <sys/ioctl.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

int main(void) 
{
    int socketCANDescriptor;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;

    char inputString[128];
    char sendMessage[8];        
    
    int packetTotal;                 // Number of packets to send
    int lastPacketSize;              // Size of last packet

    int i;
    
    
    printf("SocketCAN Sender\n");

    if ((socketCANDescriptor = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
        perror("Socket creation failed.");
        return -1;
    }

    strcpy(ifr.ifr_name, "can0" );
    ioctl(socketCANDescriptor, SIOCGIFINDEX, &ifr);
    memset(&addr, 0, sizeof(addr));
    
    addr.can_family = AF_CAN;        
    addr.can_ifindex = ifr.ifr_ifindex;

    if (bind(socketCANDescriptor, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        return -1;
    }

    while(1) {                
        printf("Enter your text: ");
        fgets(inputString, 128, stdin);
        printf("Your text: %s", inputString);         
        printf("Input Length = %d\n", (int)strlen(inputString));

        // Insert your code here to send inputString using write() function
        // You may need to use the above declared variables "packetTotal" and "lastPacketSize"

        frame.can_id = 0x555;
        
        packetTotal = strlen(inputString) / 8;
        lastPacketSize = strlen(inputString) % 8;
        if (lastPacketSize > 0) packetTotal++;

        printf("Number of Packets to send = %d\n", packetTotal);
        printf("Size of Last Bytes to send = %d\n", lastPacketSize);

        i = 0;

        while(i < packetTotal) {

            if (i < packetTotal - 1) {
                frame.can_dlc = 8;
                strncpy(sendMessage, inputString + (i * 8), 8);
                memcpy(frame.data, (char *)sendMessage, 8);
            }
            else {
                frame.can_dlc = lastPacketSize;
                strncpy(sendMessage, inputString + (i * 8), lastPacketSize);
                memcpy(frame.data, (char *)sendMessage, lastPacketSize);
            }

            if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
                perror("Write failed");
                return -1;
            }   

            printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);
            printf("%d %d\n", sendMessage[0], sendMessage[1]);

            bzero(sendMessage, sizeof(sendMessage));
            i++;
        }
        
        if(strcmp(inputString, "q\n") == 0) {
            printf("QUIT COMMAND!\n");
            break;
        }
    }
    
    if (close(socketCANDescriptor) < 0) {
        perror("Close failed");
        return -1;
    }

    return 0;
}
