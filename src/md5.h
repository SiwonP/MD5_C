#ifndef MD5_H
#define MD5_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void hash(unsigned int*, unsigned int*);

unsigned int F(unsigned int , unsigned int , unsigned int);

unsigned int G(unsigned int , unsigned int , unsigned int);

unsigned int H(unsigned int , unsigned int , unsigned int);

unsigned int I(unsigned int , unsigned int , unsigned int);

unsigned int left_rotate(unsigned int, unsigned int);

unsigned int *complete(char*);

void display_unsigned_long(unsigned int);

void display_stamp(unsigned int*);

#endif
