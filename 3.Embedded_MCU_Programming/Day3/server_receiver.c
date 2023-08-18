
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024

int main()
{
    char *ip = "172.16.0.90";       // IP address of server (RPi)
    int port = 8080;
    int ret;
    char buffer[SIZE] = {0};

    int serverSocket;
    struct sockaddr_in serverAddress;
    FILE *fp;
    char *filename = "message.txt";
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0) {
        perror("[Error] in socket");
        exit(1);
    }

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    serverAddress.sin_addr.s_addr = inet_addr(ip);
    unsigned int sockLen = sizeof(serverAddress);

    ret = bind(serverSocket, (struct sockaddr*)&serverAddress, sockLen);

    if(ret < 0) {
        perror("[Error] in Binding");
        exit(1);
    }

    printf("Waiting for client.\n");
    while(1) {
        ret = listen(serverSocket, 10);
        if(ret == -1) continue;

        int newSocket;
        unsigned int newSockLen;
        newSocket = accept(serverSocket, (struct sockaddr*)&serverAddress, &newSockLen);
        
        if(newSocket < 0) {
            perror("[Error] in Accepting");
            exit(1);
        }

        while(1) {
            ret = recv(newSocket, buffer, sizeof(buffer), 0);
            if (ret > 0) {
                printf("%s", buffer);
                bzero(buffer, SIZE);
            } else if (ret <= 0) {
                break;
            }
        }

    }
    
    printf("\n[CLOSING] Closing server.\n");
    close(serverSocket);
    return 0;
}