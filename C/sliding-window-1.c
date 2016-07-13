/* Another version of sliding window.
 *
 */
#include <stdio.h>
#include <stdlib.h>


int *maxSlidingWindow(int *arr, int numSize, int k, int *returnSize)
{
    int max = 0, start = 0, i = 0, j = 0, r_i = 0;
    int *r_arr = (int *)malloc(*returnSize);

    printf(" Calculating max in each window of size: %d of an array of size: %d\n", k, numSize);
    for (i= start, r_i = 0; i < numSize && r_i < *returnSize;r_i++, i++)
    {
        j = i;
        max = 0;

        /* take care of the corner case where we reach the last few elements */
        if (i > (start + k)) {
            if (i < numSize)
                r_arr[r_i] = arr[i];
            continue;
        }

        /* take care of the normal case */
        while(j < (start+k)) {
            if (arr[j] > arr[j+1])
                max = arr[j];
            else 
                max = arr[j+1];
            j++;
        } 

        /* save the max */
        r_arr[r_i] = max;
        start++;
    }

    return r_arr;
}

void print_max_arr(int *arr, int size)
{
    for (int i=0; i < size; i++)
       printf("%d\n",arr[i]);
    printf("\n");
}

int main()
{
#define NUM_SIZE 8
    int arr[NUM_SIZE] = {1,4,2,4,6,3,9,8};
    int window_size = 2;
    int returnSize = 6;
    int *returnArr;

    print_max_arr(arr, NUM_SIZE);

    returnArr = maxSlidingWindow(arr, NUM_SIZE, window_size, &returnSize); 

    print_max_arr(returnArr, returnSize);

    free(returnArr);
    return 0;
}
