/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *arr_plus_one(int *arr, int size, int *r_sz)
{
    int tmp = 0,i = 0, j = 0, rem = 1;
    int *r_arr;
    if (arr[0] == 9) {
        r_arr = (int *) malloc( sizeof(int) * (size + 1));
        *r_sz = size +1;
        memset(r_arr, 0, sizeof(int) * (size + 1));
    } else {
        r_arr = (int *) malloc( sizeof(int) * (size ));
        *r_sz = size;
        memset(r_arr, 0, sizeof(int) * (size ));
    }

    for (i = (size -1); i >= 0 ; i--)
    {
        tmp = 0;
        tmp = rem + arr[i];
        if ((tmp % 10) == tmp) {
            r_arr[i] = tmp;
            rem =0;
        } else {
            r_arr[i] = (tmp % 10); 
            rem = (tmp / 10);
        }
    }

    if (*r_sz > size)
        r_arr[i+1] = rem;
    

    return r_arr;
}

void print_arr(int *r, int size)
{
    for (int i=0; i < size; i++)
        printf(" %d \t", r[i]);

    printf("\n");
}

int main()
{
    int inp[4] = {2,1,8,9};
    int *out;
    int r_size = 0;

    printf(" Input array \n");
    print_arr(inp, 4);
    out = arr_plus_one(inp, 4, &r_size);

    printf(" Output array \n");
    print_arr(out, r_size);
}
