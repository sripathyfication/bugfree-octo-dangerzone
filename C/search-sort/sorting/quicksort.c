/* Quick Sort:
 *
 *  Think of it like how a normal human would do it.
 *  Pick a reference point (pivot) and everything less
 *  than pivot move to the left of pivot, everything
 *  greater than pivot move to the right of pivot.
 *
 *  If the val to the left is already less, then move
 *  left index to right.
 *
 *  Similarly, if the val the right is already greater 
 *  than pivot move the right index to the left.
 *
 *  When the left and right indices meet, that's the new
 *  pivot. 
 *
 *  So now we've partitioned the original array into two
 *  sub arrays where we can apply this recursively. 
 *
 * Divide and Conquer: 
 *  Dividing is the partitioning step.
 * 
 * Space Complexity:
 * O(1)
 *
 * Time Complexity:
 *
 * Best Case: O(n log n)
 * Worst Case: O (n ^ 2) [ Completely sorted ]
 * Average Case: O (n log n ) 
 *
 * I'd use merge sort always because worst case makes unusable.
 */

#include <stdio.h>

void swap(int *arr, int src, int dst) 
{
    int tmp = 0;

    tmp = arr[dst];
    arr[dst] = arr[src];
    arr[src] = tmp;
}

int partition(int *inp_arr, int low, int high) 
{
    int i;
    int p;
    int firsthigh;

    firsthigh = low;
    p = high;

    /* pick a pivot as High index.
     * go from low index to high - 1
     * and check each element with pivot
     * if less than pivot move it to first high
     * if not leave as is.
     * At the end, move pivot to new firsthigh.
     *
     *
     * Objective is to move pivot to rightful place
     * in each partition iteration, thereby also
     * moving elements smaller than pivot to
     * before the pivot and those that are greater than
     * pivot to after the pivot.
     */
    for (i=low; i < high; i++) 
    {
        if (inp_arr[i] < inp_arr[p])
        {
            swap(inp_arr, i, firsthigh);
            firsthigh++;
        }
    }

    /* move pivot to right place */
    swap(inp_arr, firsthigh, p); 
    return firsthigh;
}

void quicksort(int *inp_arr, int lo, int hi) 
{
    int pivot = 0;
    if (lo < hi) {
        pivot = partition(inp_arr, lo, hi);

        quicksort(inp_arr, lo, pivot - 1);
        quicksort(inp_arr, pivot + 1, hi);
    }
}


#define INPUT_LEN 10
int main()
{
    int lo = 0, hi = INPUT_LEN -1;
    int inp_arr[INPUT_LEN] = {3,1,54,-23,0,6,7,10,11,5};

    printf("Input array\n");
    for (int i=0; i < INPUT_LEN; i++)
        printf(" %d \t", inp_arr[i]);

    printf("\n");
    quicksort(inp_arr,lo, hi);

    printf("Sorted array\n");
    for (int i=0; i < INPUT_LEN; i++)
        printf(" %d \t", inp_arr[i]);

    printf("\n");
}
