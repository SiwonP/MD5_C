#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned long *complete(char *input) {
    static unsigned long message[16] = {0};
    int bufferSize = 0;
    unsigned long buffer = 0;

    /*Size of the message coded 
     * in 64 bits */
    long long sizeMessage = 0;

    int size = strlen(input);

    int i = 0;
    int j = 0;

    while (input[i] != 0) {
        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            j++;
        } else {
            bufferSize++;
            buffer = buffer << 8;
            buffer = buffer | input[i];
            i++;
            sizeMessage = sizeMessage + 8;
        }
    }

    printf("buffer size : %d\n", bufferSize);
    //printf("%d\n", size);

    printf("buffer : %c\n", (char)buffer);
    printf("%c\n", (char)message[0]);
    printf("%c\n", (char)message[1]);


    return message;
}

