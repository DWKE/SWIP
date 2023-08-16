
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>

#include "4_msg_data.h"

#if 1
int main()
{
    int i;
    const char* name = "SHM_TEST";                  // Name of the shared memory object    
    int shm_fd;                                     // File descriptor for shared memory
    void* shmPointer;                               // Pointer to shared memory object
    int messageSize = sizeof(messageStruct);        // Size of message
    
    messageStruct messageToReceive[MESSAGE_TOTAL]; // Message to receive
     
    /* Create the shared memory object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
 
    /* Configure the size of the shared memory object */
    // if (ftruncate(shm_fd, messageSize*MESSAGE_TOTAL) == -1) {
    //     printf("ftruncate failed.\n");
    //     return -1;
    // }
 
    /* Map the shared memory object */
    shmPointer = (unsigned char*)mmap(0, messageSize*MESSAGE_TOTAL, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    
    /* Read messages into the shared memory object */
    for (i = 0; i < MESSAGE_TOTAL; i++) {
        memcpy(&messageToReceive[i], shmPointer + messageSize*i, messageSize);
    }
         
    /* Unmap shared memory */
    munmap(shmPointer, messageSize*MESSAGE_TOTAL);
    
    /* Close shared memory communication */
    close(shm_fd);

    for (i = 0; i < MESSAGE_TOTAL; i++) {
        printf("Read %s and %f into %dth area.\n", messageToReceive[i].name, messageToReceive[i].value, i);
    }

    shm_unlink(name);

    return 0;
}

#endif