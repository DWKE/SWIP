#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define SIZE 1024


void receiveAndWriteIntoFile(int sockfd)
{
    int receivedBytesTotal; 
    FILE *fp;
    char *filename = "message.txt";
    char buffer[SIZE];

    fp = fopen(filename, "w");
    if(fp == NULL) {
        perror("[Error] in creating file.");
        exit(1);
    }
    while(1) {
        receivedBytesTotal = recv(sockfd, buffer, SIZE, 0);
        if(receivedBytesTotal <= 0)
        {
            break;
        }
        printf("[RECEVED] %s", buffer);
        fprintf(fp, "%s", buffer);
        bzero(buffer, SIZE);
    }

    fclose(fp);
}

void receiveAndPrint(int sockfd)
{
    int receivedBytesTotal; 
    char buffer[SIZE];

    while(1) {
        receivedBytesTotal = recv(sockfd, buffer, SIZE, 0);
        if(receivedBytesTotal <= 0)
        {
            break;
        }
        printf("[RECEIVED] %s", buffer);
        bzero(buffer, SIZE);
    }
}


int main ()
{
    char *ip = "10.69.1.253";       // IP address of server (RPi)
    int port = 8080;
    int ret;
    
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    socklen_t addrSize;
    
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSocket < 0) {
        perror("[ERROR] in socket");
        exit(1);
    }
    printf("[STARTING] TCP File Server started. \n");

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = port;
    serverAddress.sin_addr.s_addr = inet_addr(ip);

    ret = bind(serverSocket,(struct sockaddr*)&serverAddress, sizeof(serverAddress));
    if(ret < 0) {
        perror("[Error] in Binding");
        exit(1);
    }

    ret = listen(serverSocket, 10);
    if(ret < 0) {
        perror("[Error] in Listening");
        exit(1);
    }

    addrSize = sizeof(clientAddress);
    clientSocket = accept(serverSocket,(struct sockaddr*)&clientAddress, &addrSize);

    //receiveAndWriteIntoFile(clientSocket);
    receiveAndPrint(clientSocket);
    printf("\n[CLOSING] Closing the server.\n");
}