#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "message.h"


void hash() {
    unsigned long h0 = 0x67452301;
    unsigned long h1 = 0xefcdab89;
    unsigned long h2 = 0x98badcfe;
    unsigned long h3 = 0x10325476;
}


unsigned long f(unsigned long b, unsigned long c, unsigned long d) {
    return ((b & c) | (~b & d));
}

unsigned long g(unsigned long b, unsigned long c, unsigned long d) {
    return ((b & d) | (c & ~d));
}

unsigned long h(unsigned long b, unsigned long c, unsigned long d) {
    return (b ^ c ^ d);
}

unsigned long i(unsigned long b, unsigned long c, unsigned long d) {
    return (c ^ (b | ~d));
}
