#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *complete(char *input) {
    static char message[64] = {0};

    int size = strlen(input);

    int i;
    for (i = 0; i < size; i++) {
        message[i] = input[i];
    }

    char fill = 1;
    fill = fill<<7;
    i++;
    message[i] = fill;
    
    return message;
}

