/*
 *Given an array where every element occurs three times, except one element which occurs only
 * once. Find the element that occurs once. Expected time complexity is O(n) and O(1) extra space.
Examples:

Input: arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
Output: 2

 */
#include <stdio.h>
#include <stdlib.h>

static int compare(const void *a, const void *b) {
          return *(int*)a - *(int*)b;
}

int find_single_num(int *arr, int size)
{
    int i = 0;
    qsort(arr, size, sizeof(int), compare);

    int k = 3;
    while (i < size)
    {
        if (arr[i] == arr[i+1])
            i = i + (k);
        else 
            break;
    }

    return arr[i];
}


int main()
{
    int arr[10] = {12,1,12,1,1,12,3,2,3,3};
    int s_num = 0;

    s_num = find_single_num(arr,10);

    printf("Single num is: %d\n", s_num);

    return 0;
}
