/*
 * Given an unsorted array, find the max gap in each consecutive window
 * and return the max gap.
 */
#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b) {
      return *(int*)a - *(int*)b;
}

int maximumGap(int* nums, int numsSize) 
{
    int r_size = numsSize - 1;
    if (numsSize < 2) return 0;

    int *max_gap = (int *)malloc(r_size);

    for (int i = 0, j = 1; i< numsSize && j <= numsSize; i++,j++)
    {
        max_gap[i] = abs(nums[i] - nums[j]);
    }

    qsort(max_gap,numsSize,sizeof(int), compare);

    return max_gap[r_size - 1];
}


int main()
{
    int arr[10] = {1,1,1,1,1,5,5,5,5,5};

    printf(" Max gap is %d \n", maximumGap(arr, 10));
}
