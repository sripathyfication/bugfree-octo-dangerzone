#include<stdio.h>

int swap_odd_even(int n) {

    return (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));
} 

int main()
{
    
    int n = 0x1111;

    printf("Swapping odd and even of 0x%x gives 0x%x\n",n, swap_odd_even(n));
    return 0;
}
