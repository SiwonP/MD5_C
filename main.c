#include <stdlib.h>
#include <stdio.h>
#include "message.h"

#define MAX 64

int main(int argc, char *argv[]) {
    char *message;

    message = complete(argv[1]);

    int i = 0;

    while (message[i] != 0) {
        printf("%c\n", message[i]);
        i++;
    }
    return 1;
}
