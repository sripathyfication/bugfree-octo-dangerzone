#include <stdio.h>
#define MAX_BITS 8
int swap_odd_even_bits(int to_swap)
{
    int i =0, j =0, tmpi =0, tmpj = 0, result = 0;
    for (i=0, j=1; i < MAX_BITS && j < MAX_BITS; i+=2, j+=2) {
        printf(" i = %d, j = %d \n", i,j);
        tmpi = to_swap & (1 << i);
        tmpj = to_swap & (1 << j);
        result |= ((tmpj >> j) | (tmpi << (j-1)));
        printf(" to_swap: 0x%x result: 0x%x tmpi: 0x%x tmpj: 0x%x\n",to_swap, result ,tmpi, tmpj);
        tmpi = tmpj = 0;
    }
            
    return result;
}

int main() 
{
    int result =0, j =0, i =0;
    int tc = 23; 

    printf(" TestCase: %d \n", tc);
    result = swap_odd_even_bits(tc);    
    printf(" Result: %d \n", result);
                
    return 0;
}


