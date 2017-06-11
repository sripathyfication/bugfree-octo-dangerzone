#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * A Signed integer in C users the leftmost bit as the sign bit. So, a signed integer can have
 * values in the range -2(pow 31) to 2(pow 31) -1
 *
 * A negative number would have the leftmost bit set to true.
 *
 * consider 1000000000000101 (-5) { This is the normal intuitive way. but in practice the negative
 * number is stored as 2's complement in computers. Why? Here's why:
 *
 * assume 2 and -1
 *
 * 2: 0010
 * -1 : 1001 (intuitive way)
 *
 * This would mean  if i had to add 2 and -1 , with -1 stored in an intuitive way, then addition
 * would be complicated.
 *
 * 0010
 * 1001
 * ----
 * 1011
 * ----
 *
 * This is -3, which is not what we're supposed to get when we add 2 and -1; 2 + (-1) = -1.
 *
 * To prevent such complicated algorithms to add 2 signed integers, we store a negative number as
 * a 2's complement (which is a 1's complement + 1). Consider an addition with a negative number
 * stored as a 2's complement.
 *
 *  0010
 * +1111 (2's complement of 1: 1110 + 1)
 * -----
 *  10001 we can discard the carry. This gives us 1. 
 *  -----
 *  so, we didn't invent any new algorithm to do the math. 
 *
 *
 *
 *  Now to the main problem:
 *
 *  to detect if 2 numbers have the same sign, simply xor.
 *  if the signs are different the xor will return 1.
 */
char same_sign(int a, int b) {
    return (a ^ b);
}

int main() {

    int a = 10;
    int b = -10;

    int same = same_sign(a,b);
    printf("Are %d and %d of the  same sign? %s\n", a,b,(same < 0? "False":"True"));

    return 0;
}
