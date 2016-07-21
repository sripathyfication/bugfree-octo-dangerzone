#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *  * Return an array of size *returnSize.
 *   * Note: The returned array must be malloced, assume caller calls free().
 *    */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) 
{
    int start = 0, max = 0, i = 0;
    int *max_arr;

    max_arr = (int *)malloc(sizeof(int) * (*returnSize));
    memset(max_arr,0,(sizeof(int) * (*returnSize)));

    while ((start+k) <= numsSize) 
    {
        max = 0;

        for (i=start; i< (start+k); i++) {
            if (nums[i] >= max)
                max = nums[i];
        }

        max_arr[start] = max;
        start++;
    }

    printf("\n");
    return max_arr;
}

int main() 
{
    int window_size = 0, inp_size = 1, ret_size = 1;
    int arr[1] = {1};
    int *ret_arr;

    for (int i=0; i < inp_size; i++)
        printf(" inp_arr[%d]: %d\t", i, arr[i]);

    ret_arr = maxSlidingWindow(arr,inp_size, window_size,&ret_size);

    for (int j=0; j<ret_size;j++)
        printf(" max_arr[%d]: %d\t", j,ret_arr[j]);

    printf("\n");
    return 0;
}
