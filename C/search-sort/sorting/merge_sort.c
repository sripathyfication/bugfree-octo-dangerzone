/* Merge Sort:
 *
 * Divide & Conquer algorithm:
 *
 * Divide step: recursively subdivide array into two parts 
 *              till it can no longer be divided into smaller
 *              sub arrays.
 *
 *              How? Assume array of len = 7;
 *              left = 0, right = len - 1 = 6.
 *              middle = (right - left) /2
 *
 *              So, you got 2 sub arrays: left_arr[left, middle] right_arr[middle+1, right]
 *              Till 0, 1.
 *
 * Conquer step: create copies of left and right sub arry, compare element of right
 *               with element of left, replace with whichever is smaller.              
 *
 *
 * Time Complexity:
 *
 * Best: O (n log n)
 * Average: O (n log n)
 * Worst: O (n log n )
 *
 * Space Complexity:
 * O (n)
 *
 */
#include <stdio.h>

void merge(int *arr, int l, int r, int m)
{
    int size_left, size_right;
    int i, j, k;

    size_left = (m - l) +1;
    size_right = r - m;

    int left_arr[size_left],right_arr[size_right];

    /* First create a left and right sub array copy */
    for (i=0; i < size_left; i++) 
        left_arr[i] = arr[l+i];
    for (j=0; j < size_right; j++)
        right_arr[j] = arr[m+1+j];

    i = 0;
    j = 0;
    k = l;
    
    while ( i < size_left && j < size_right)
    {
        if (left_arr[i] <= right_arr[j]) { 
            arr[k] = left_arr[i];
            i++;
        } else {
            arr[k] = right_arr[j];
            j++;
        } 
        k++;
    }

    /* If there's anything left in left sub array then copy it over */
    while ( i < size_left) {
        arr[k] = left_arr[i];
        i++;
        k++;
    }
    
    /* If there's anything remaining in right sub array then copy it */
    while(j < size_right) {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    return;
}

void merge_sort(int *arr, int l, int r)
{
    if (l < r) 
    {
        int m = (l + (r - 1)) / 2;

        /* Divide steps */
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r); 

        /* conquer step */
        merge(arr, l, r, m);
    }
}

void sort(int *inp_arr, int len) 
{
    int left, right;
    left = 0;
    right = len - 1;

    merge_sort(inp_arr, left, right);
}

#define INPUT_LEN  10 
int main()
{
    int i,inp_arr[INPUT_LEN] = {-11,1,-23,1,2,6,4,3,2,1001};

    printf("Input array:\n");
    for (i = 0; i < INPUT_LEN; i++)
        printf(" %d\t", inp_arr[i]);

    printf("\n");
    sort(inp_arr, INPUT_LEN);

    printf("Sorted array:\n");
    for (i = 0; i < INPUT_LEN; i++)
        printf(" %d\t", inp_arr[i]);

    printf("\n");
}
