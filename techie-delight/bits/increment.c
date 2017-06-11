#include<stdio.h>
/*
 * Start with i = 1 in LSB and 
 *
 * keep left shifting i by 1, and try to find the first 0.
 * meanwhile set every set bit in the number to 0 till we find first 0.
 *
 * moment we find it, return (n | i)
 *
 * RECALL :
 *
 * -x = ~x + 1 (1's complement + 1)
 * Replace x with ~x
 *
 * -~x = x + 1
 *
 * That's it, no branching and we get any integer incremented.
 */
int increment(int n) {

    int i = 1;
    while (i & n) {

        n = n & ~i;
        i = i << 1;
    }

    return (n | i);
}

int main() {


    int n = 0x9;
    

    printf(" 0x%x incremented by 1 is 0x%x\n", n,increment(n));
    printf(" 0x%x incremented by 1 is 0x%x\n", n,-~n);
    printf(" %d incremented by 1 is %d\n", -5,-~(-5));
    printf(" 0x%x incremented by 1 is 0x%x\n", 0,-~0);

    return 0;
}
