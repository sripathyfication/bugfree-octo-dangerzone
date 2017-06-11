#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


char * int2bin(int i)
{
    size_t bits = sizeof(int) * CHAR_BIT;
    char * str = malloc(bits + 1);
    if(!str) return NULL;
        str[bits] = 0;
    unsigned u = *(unsigned *)&i;
    for(; bits--; u >>= 1)
        str[bits] = u & 1 ? '1' : '0';

    return str;
}

int main() {

    int n = -5;
    unsigned int x = -5;
    printf("Signed integer %d in binary %s\n",n,int2bin(n));
    printf("Unsigned integer %u in binary %s\n",x,int2bin(x));
}
