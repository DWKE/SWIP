
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024

void sendFile(FILE *fp, int sockfd)
{
    char buffer[SIZE] = {0};

    while(fgets(buffer, SIZE, fp)!=NULL) {
        if(send(sockfd, buffer, sizeof(buffer), 0)== -1) {
            perror("[Error] in sendung data");
            exit(1);
        }

        printf("[SENT] %s", buffer);
        bzero(buffer, SIZE);
    }

    fclose(fp);
}

int main()
{
    char *ip = "172.16.0.90";       // IP address of server (RPi)
    int port = 8080;
    int ret;
    char* msg = "NULL";

    int serverSocket;
    struct sockaddr serverAddress;
    FILE *fp;
    char *filename = "message.txt";
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0) {
        perror("[Error] in socket");
        exit(1);
    }

    serverAddress.sa_family = AF_INET;
    unsigned int sockLen = sizeof(serverAddress);

    ret = bind(serverSocket, &serverAddress, sockLen);

    if(ret < 0) {
        perror("[Error] in Binding");
        exit(1);
    }

    while(1) {
        ret = listen(serverSocket, 10);
        if (ret == 0) {
            ret = accept(serverSocket, &serverAddress, &sockLen);
            
            if(ret < 0) {
                perror("[Error] in Accepting");
                exit(1);
            }

            ret = recv(serverSocket, msg, SIZE, 0);

            if(ret < 0) {
                perror("[Error] in Receiving");
                exit(1);
            }

            printf("%s\n", msg);
        }
    }
    
    printf("\n[CLOSING] Disconnecting from the server.\n");
    close(serverSocket);
    return 0;
}