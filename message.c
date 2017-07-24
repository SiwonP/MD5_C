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

    long long size = strlen(input);

    int i = 0;
    int j = 0;

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

    /* Adding a bit 1 */
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

    sizePart1 = (unsigned long)size;
    sizePart2 = (unsigned long)size >> 32;


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

void display_unsigned_long(unsigned long n) {
    unsigned char a = (unsigned char)n;
    unsigned char b = n >> 8;
    unsigned char c = n >> 16;
    unsigned char d = n >> 24;
    printf("%2.2x", a);
    printf("%2.2x", b);
    printf("%2.2x", c);
    printf("%2.2x", d);
}
