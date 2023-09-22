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

                frame.can_id = 0x555;                
                packetTotal = strlen(inputString)/8 + 1;
                lastPacketSize = strlen(inputString) - (packetTotal - 1)*8;
                printf("Number of Packets to send = %d\n", packetTotal);
                printf("Size of last packet = %d\n", lastPacketSize);
                
                for (i = 0; i < packetTotal - 1; i++) {
                        memcpy(sendMessage, inputString + 8*i, 8);
                        frame.can_dlc = 8;
                        memcpy(frame.data, sendMessage, frame.can_dlc);
                
                        if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
                                perror("Write failed");
                                return -1;
                        }                        
                }       

                memcpy(sendMessage, inputString + 8*i, strlen(inputString + 8*i));
                frame.can_dlc = lastPacketSize;
                memcpy(frame.data, sendMessage, frame.can_dlc);
                
                if (write(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
                        perror("Write failed");
                        return -1;
                }                
                
                if ((sendMessage[0] == 'q') && (packetTotal == 1) && (lastPacketSize == 2)) {
                        printf("\nQUIT COMMAND!\n");
                        break;
                }

                printf("\n");             
        }
                
        if (close(socketCANDescriptor) < 0) {
                perror("Close failed");
                return -1;
        }

        return 0;
}
