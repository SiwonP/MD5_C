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

    /*
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
    */

    while (input[i] != 0) {
        bufferSize ++;
        buffer = buffer << 8;
        buffer = buffer | input[i];
        //sizeMessage = sizeMessage + 8;
        i++;

        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            sizeMessage = sizeMessage + 32;
            j++;
        }
    }

    
    unsigned char one = 1;
    one = one << 7;
    buffer = buffer << 8;
    buffer = buffer | one;
    bufferSize++;

    buffer = buffer << 8 * (4 - bufferSize);

    message[j] = buffer;
    sizeMessage = sizeMessage + 32;
    j++;
    bufferSize = 0;
    buffer = 0;

    while (sizeMessage < 448) {
        message[j] = 0;
        sizeMessage = sizeMessage + 32;
        j++;
    }


    unsigned long sizePart1 = 0;
    unsigned long sizePart2 = 0;

    sizePart1 = (unsigned long)sizeMessage;
    sizePart2 = (unsigned long)sizeMessage >> 32;


    message[j] = sizePart1;
    j++;
    sizeMessage = sizeMessage + 32;
    message[j] = sizePart2;
    j++;
    sizeMessage = sizeMessage + 32;

    printf("j : %d\n", j);

    printf("sizeMessage : %lld\n", sizeMessage);

    return message;
}

