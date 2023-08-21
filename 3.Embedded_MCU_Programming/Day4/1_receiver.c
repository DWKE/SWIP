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

        int receivedData[2];
        int numBytes;
        int i;
        
        
        printf("SocketCAN Receiver\n");

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

        frame.can_id = 0x555;
        frame.can_dlc = 8;
        
        if (read(socketCANDescriptor, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
                perror("Read failed.");
                return -1;
        }

        printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);

        memcpy((char *)receivedData, frame.data, sizeof(frame.data));

        printf("%d\n", sizeof(frame.data));
        printf("%d %d\n", receivedData[0], receivedData[1]);

        if (close(socketCANDescriptor) < 0) {
                perror("Close failed");
                return -1;
        }

        return 0;
}