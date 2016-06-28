#include <stdio.h>
#include <stdlib.h>


unsigned int reverseBits(unsigned int n) 
{
    unsigned int begin, end;
    unsigned int size = sizeof(unsigned int);
    begin = 0;
    end = (size * 8) - 1;

    while (begin <= end) {
        n |= ((n & ( 1 << begin)) << end) | ((n & ( 1 << end) >> end));
        begin++;
        end--;
    }

    return n;
}


int main(int argc, char **argv) 
{
    if (argc < 2) return -1;

    printf(" Number to be reversed: 0x%x .. after reversal: 0x%x\n", atoi(argv[1]),reverseBits(atoi(argv[1])));

    return 0;
}
