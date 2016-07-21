/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b) {
      return *(int*)a - *(int*)b;
}

void print_array(int *nums, int numsSize)
{
    for(int i=0; i < numsSize; i++)
        printf(" %d \t", nums[i]);

    printf("\n");
}

int majority_element(int* nums, int numsSize)
{
    // sort the input array
    qsort(nums, numsSize, sizeof(int), compare);

    return 0;
}


int main()
{
    int arr[10] = {5,3,4,5,5,2,1,1,1,8};

    majority_element(arr, 10);

    print_array(arr, 10);
}
