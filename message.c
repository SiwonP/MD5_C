#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *fill_the_message(char *input) {
    static char message[64];

    int size = strlen(input);

    int i;
    for (i = 0; i < size; i++) {
        message[i] = input[i];
    }
    
    char fill = 1;
    fill = fill<<7;

    i++;
    message[i] = fill;

    for (int j = i+1; j < 64; j++) {
        message[j] = 0;
    }


    return message;
}

