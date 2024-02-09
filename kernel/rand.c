#include "rand.h"
#include <stdio.h>

unsigned long int next = 1;

int rand(int range)
{
    next = next * 1103515243 + 12345;
    return (unsigned int)(next / 65536) % range;
}

void srand(unsigned int seed)
{
    next = seed;
}
