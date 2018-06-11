#include "md5.h"

unsigned int *complete(char *input)
{
    static unsigned int message[16] = {0};
    int bufferSize = 0;
    unsigned int buffer = 0;

    long long sizeMessage = 0;

    /*Size of the message coded 
     * in 64 bits */
    long long size = strlen(input) * 8;

    int i = 0;
    int j = 0;

    unsigned int tmp = 0;

    while (input[i] != 0) {
        /* Use of the tmp
         * to append to the 
         * beginning and not
         * to the end
         * ie reading in Little Endian */
        tmp = input[i];
        tmp = tmp << (bufferSize * 8);
        bufferSize++;
        buffer = buffer | tmp;
        i++;
        
        if (bufferSize == 4) {
            message[j] = buffer;
            buffer = 0;
            bufferSize = 0;
            sizeMessage = sizeMessage + 32;
            j++;
        }
    }

    /* Adding a bit 1 
     * to the current buffer (even if its 
     * empty) still with 
     * the reading in little endian
     * (that's why i use the tmp
     * int) */
    unsigned char one = 1;
    one = one << 7;
    tmp = one;
    tmp = tmp << (bufferSize * 8);
    buffer = buffer | tmp;

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


    unsigned int sizePart1 = 0;
    unsigned int sizePart2 = 0;

    /* storing the size of the
     * initial message in bits
     * in 2 x 32 bits (since
     * it's coded in 64 bits) */
    sizePart1 = (unsigned int)size;
    sizePart2 = size >> 32;


    message[j] = sizePart1;
    j++;
    sizeMessage = sizeMessage + 32;
    message[j] = sizePart2;
    j++;
    sizeMessage = sizeMessage + 32;

    return message;
}

void display_unsigned_long(unsigned int n)
{
    unsigned char a = (unsigned char)n;
    unsigned char b = n >> 8;
    unsigned char c = n >> 16;
    unsigned char d = n >> 24;
    printf("%2.2x", a);
    printf("%2.2x", b);
    printf("%2.2x", c);
    printf("%2.2x", d);
}

void display_stamp(unsigned int *stamp)
{
    for (int i = 0; i < 4; i++) {
        display_unsigned_long(stamp[i]);
    }
    printf("\n");
}

void hash(unsigned int *message, unsigned int *stamp)
{

    unsigned int r[64] = { 
        7, 12, 17, 22, 7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
        5,  9, 14, 20, 5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21};

    unsigned int k[64] = {
        0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
        0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
        0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
        0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
        0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
        0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
        0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
        0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
        0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
        0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
        0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
        0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
        0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
        0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
        0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
        0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};


    unsigned int h0 = 0x67452301; 
    unsigned int h1 = 0xEFCDAB89;
    unsigned int h2 = 0x98BADCFE;
    unsigned int h3 = 0x10325476;

    unsigned int a = h0;
    unsigned int b = h1;
    unsigned int c = h2;
    unsigned int d = h3;

    unsigned int f;
    unsigned int g;

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
        f = f + a + k[i] + message[g];
        a = d;
        d = c;
        c = b;
        b = b + left_rotate(f, r[i]);
        //printf("%x\n", left_rotate(f, r[i]));
   }

    h0 = h0 + a;
    h1 = h1 + b;
    h2 = h2 + c;
    h3 = h3 + d;

    stamp[0] = h0;
    stamp[1] = h1;
    stamp[2] = h2;
    stamp[3] = h3;
}

unsigned int F(unsigned int b, unsigned int c, unsigned int d)
{
    return ((b & c) | ((~b) & d));
}

unsigned int G(unsigned int b, unsigned int c, unsigned int d)
{
    return ((b & d) | (c & (~d)));
}

unsigned int H(unsigned int b, unsigned int c, unsigned int d)
{
    return (b ^ c ^ d);
}

unsigned int I(unsigned int b, unsigned int c, unsigned int d)
{
    return (c ^ (b | (~d)));
}

unsigned int left_rotate(unsigned int n, unsigned int r) {
    return (((n) << (r)) | ((n) >> (32 - (r))));
}
