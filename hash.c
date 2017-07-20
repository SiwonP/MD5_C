#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


void hash() {
    long int h0 = 0x67452301;
    long int h1 = 0xefcdab89;
    long int h2 = 0x98badcfe;
    long int h3 = 0x10325476;
}


long int f(long int b, long int c, long int d) {
    return ((b & c) | (~b & d));
}

long int g(long int b, long int c, long int d) {
    return ((b & d) | (c & ~d));
}

long int h(long int b, long int c, long int d) {
    return (b ^ c ^ d);
}

long int i(long int b, long int c, long int d) {
    return (c ^ (b | ~d));
}
