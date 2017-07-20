#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "message.h"


void hash() {
    unsigned long h0 = 0x67452301;
    unsigned long h1 = 0xefcdab89;
    unsigned long h2 = 0x98badcfe;
    unsigned long h3 = 0x10325476;

    unsigned long a = h0;
    unsigned long b = h1;
    unsigned long c = h2;
    unsigned long d = h3;

    unsigned long f;
    unsigned long g;

    for (int i = 0; i < 64; i++) {
        if ( i < 16 ) {
            f = F(b,c,d);
            g = i;
        } else if (i < 32) {
            f = G(b,c,d);
            g = (5 * i + 1) % 16;
        } else if (i < 48) {
            f = H(b,c,d);
            g = (3 * i + 5) % 16;
        } else if (i < 64) {
            f = I(b,c,d);
            g = (7 * i) % 16;
        }
        unsigned long tmp = d;
        d = c;
        c = b;
        //b = blablabl
        a = tmp;
    }

}

unsigned long F(unsigned long b, unsigned long c, unsigned long d) {
    return ((b & c) | (~b & d));
}

unsigned long G(unsigned long b, unsigned long c, unsigned long d) {
    return ((b & d) | (c & ~d));
}

unsigned long H(unsigned long b, unsigned long c, unsigned long d) {
    return (b ^ c ^ d);
}

unsigned long I(unsigned long b, unsigned long c, unsigned long d) {
    return (c ^ (b | ~d));
}
