#include <stdlib.h>
#include <stdio.h>
#include "message.h"
#include "hash.h"

#define MAX 64

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("usage : %s <string>\n", argv[0]);
        return 1;
    }

    unsigned long *message;

    message = complete(argv[1]);

    hash(message);

    return 1;
}
