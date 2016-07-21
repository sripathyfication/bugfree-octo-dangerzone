/*
 * Swapping odd and even bits from
 * a 32 bit unsigned integer.
 */
#include <stdio.h>
#include <stdlib.h>

typedef  unsigned int uint32_t;
uint32_t swap_odd_even(uint32_t num)
{
#define ODD_32_BITS     0xAAAAAAAA
#define EVEN_32_BITS    0x55555555

    return (((num & ODD_32_BITS) >> 1) | ((num & EVEN_32_BITS) << 1));
}

int main() 
{
    uint32_t num;

    printf("Enter the number for which you want to swap odd and even bits \n");
    scanf("%u", &num);

    printf("Swapped even and odd bits number is : %u \n", swap_odd_even(num));

}
