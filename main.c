#include <stdlib.h>
#include <stdio.h>
#include "message.h"

#define MAX 64

int main(int argc, char *argv[]) {
    unsigned long *message;

    message = complete(argv[1]);

    return 1;
}
