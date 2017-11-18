#include <stdlib.h>
#include <stdio.h>
#include "src/message.h"
#include "src/hash.h"

#define MAX 64

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage : %s <string>\n", argv[0]);
        return 1;
    }

    unsigned int *message;
    unsigned int stamp[4];

    message = complete(argv[1]);

    hash(message, stamp);

    display_stamp(stamp);
    return 1;
}
