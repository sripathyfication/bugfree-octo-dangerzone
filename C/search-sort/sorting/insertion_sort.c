/* Insertion Sort: 
 * think of a deck of cards in the hand,
 * and you're taking a new card lookin
 * at all other cards in your hand and 
 * placing new card in correct position
 *
 * Time Complexity:
 * 
 * Best: O(n) - already sorted
 * Worst: O(n ^ 2) - completely unsorted
 * Average: O(n ^ 2) - even if slightly sorted.
 *
 * Space Complexity:
 *
 * O(1)
 */
#include <stdio.h>

void insertion_sort(int *arr, int len)
{
    int new_i =0, old=0, tmp = 0, k = 0;
    
    for (new_i = 0; new_i <= len; new_i++)
    {
        old = new_i;
        while (old > 0 && (arr[new_i] < arr[old - 1])) 
            old--;

        tmp = arr[new_i];
        /* re arrange all the remaining */
        for (k = new_i; k > old; k--)
            arr[k] = arr[k-1];

        arr[old] = tmp;
    }
}

#define INPUT_LEN 8
int main()
{
    int i,inp_arr[INPUT_LEN] = {10,9,8,7,6,5,4,3};

    insertion_sort(inp_arr, INPUT_LEN);

	for (i=0; i < INPUT_LEN; i++)
		printf(" %d\t", inp_arr[i]); 
     	
	printf("\n");
}
