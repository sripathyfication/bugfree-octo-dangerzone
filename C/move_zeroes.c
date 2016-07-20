/*
 * Given an array nums, write a function to move all 0's to the end of it while maintaining the
 * relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3,
 * 12, 0, 0].
 *
 * Note:
 *    You must do this in-place without making a copy of the array.
 *    Minimize the total number of operations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *move_zeroes(int *arr, int size)
{
    int i = 0, j = 0, tmp = 0;

    if (size <= 1) return arr;

    while ((j < size)) 
    {
        if (arr[j] == 0) { 
            j++; 
            continue; 
        }

        if (arr[i] == 0 && arr[j]) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        } 

        i++; j++;
    }

    return arr;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d \t", arr[i]);

    printf("\n");
}

int main() 
{

    int arr[5] = {0,1,2,1,0};
    int *r_arr;
    
    printf("Input array\n");
    
    print_array(arr,5);
    r_arr = move_zeroes(arr, 5);

    printf("sorted array \n");
    print_array(r_arr, 5);
}
