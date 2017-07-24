#include <stdlib.h>
#include <stdio.h>
#include <string.h>

unsigned int *complete(char *input) {
    static unsigned int message[16] = {0};
    int bufferSize = 0;
    unsigned int buffer = 0;

    long long sizeMessage = 0;

    /*Size of the message coded 
     * in 64 bits */
    long long size = strlen(input) * 8;

    int i = 0;
    int j = 0;

    /*
    while (input[i] != 0) {
        bufferSize ++;
        buffer = buffer << 8;
        buffer = buffer | input[i];
        i++;

        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            sizeMessage = sizeMessage + 32;
            j++;
        }
    }
    */

    unsigned int tmp = 0;

    while (input[i] != 0) {
        tmp = input[i];
        tmp = tmp << (bufferSize * 8);
        bufferSize++;
        buffer = buffer | tmp;
        i++;
        
        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            sizeMessage = sizeMessage + 32;
            j++;
        }
    }

    /* Adding a bit 1 */
    unsigned char one = 1;
    one = one << 7;
    tmp = one;
    tmp = tmp << (bufferSize * 8);
    buffer = buffer | tmp;
    /*
    buffer = buffer << 8;
    buffer = buffer | one;
    bufferSize++;

    buffer = buffer << 8 * (4 - bufferSize);
    */

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


    unsigned int sizePart1 = 0;
    unsigned int sizePart2 = 0;

    sizePart1 = (unsigned int)size;
    sizePart2 = size >> 32;


    message[j] = sizePart1;
    j++;
    sizeMessage = sizeMessage + 32;
    message[j] = sizePart2;
    j++;
    sizeMessage = sizeMessage + 32;

    //printf("j : %d\n", j);

    //printf("sizeMessage : %lld\n", sizeMessage);

    return message;
}

void display_unsigned_long(unsigned int n) {
    unsigned char a = (unsigned char)n;
    unsigned char b = n >> 8;
    unsigned char c = n >> 16;
    unsigned char d = n >> 24;
    printf("%2.2x", a);
    printf("%2.2x", b);
    printf("%2.2x", c);
    printf("%2.2x", d);
}

void display_stamp(unsigned int *stamp) {
    for (int i = 0; i < 4; i++) {
        display_unsigned_long(stamp[i]);
    }
    printf("\n");
}
