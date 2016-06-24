#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 8
int swap_odd_even_bits(int to_swap)
{
    int i =0, j =0, tmp_e =0, tmp_o = 0, result = 0;
    for (i=0, j=1; i < MAX_BITS && j < MAX_BITS; i+=2, j+=2) {
        tmp_e = to_swap & (1 << i);
        tmp_o = to_swap & (1 << j);
        printf(" even_bit  %d odd_bit  %d even_mask %d odd_mask %d swap_even %d swap_odd %d\n",
                i,j, (1 << i), (1 << j), (tmp_e), tmp_o);
        result |= ((tmp_o >> j) | (tmp_e << (j-1)));
        tmp_e = tmp_o = 0;
    }
    return result;
}

int main(int argc, char **argv) 
{
    int result =0, j =0, i =0;
    int num_tests =0, tc = 0;
    if (argc < 3) return -1;

    num_tests = atoi(argv[1]);
    printf(" Number of tests: %d \n", num_tests);

    while (num_tests) {
        tc = atoi(argv[2 + i]);
        printf(" TestCase: %d \n", tc);
        result = swap_odd_even_bits(tc);
        printf(" Result: %d \n", result);
        i++;
        num_tests--;
    }
                
    return 0;
}


