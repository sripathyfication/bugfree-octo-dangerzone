#include <stdio.h>

#define B2(n) n ,   n+1,    n+1,    n+2
#define B4(n) B2(n),B2(n+1),B2(n+1),B2(n+2)
#define B6(n) B4(n), B4(n+1),B4(n+1),B4(n+2)
#define COUNT_BITS  B6(0), B6(1), B6(1), B6(2)
unsigned int lookup[256] = { COUNT_BITS };

void print_lookup() {
    int i =0;
    printf("Lookup Table\n");
    printf("[");
    for(i = 0; i < 256; i++)
    {
        printf("%d,", lookup[i]);
    }
    printf("]\n");
    return;
}

int num_set_bits(int n) {
    int num_bits = 0;
    num_bits = lookup[n & 0xff] + lookup[(n>>8) & 0xff] + lookup[(n>>16) & 0xff] + lookup[(n>>24) & 0xff];
    return num_bits;
}

int main() {

    print_lookup();

    int n = -1;
    printf("number of set bits in number : 0x%x is %d\n", n, num_set_bits(n));
    return 0;
}
