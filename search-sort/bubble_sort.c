/* Bubble Sort:
 * Simplest form of sort. O(n ^ 2) 
 * For every element, compare it to
 * every other element.
 *
 * Time Complexity:
 *
 * Best: O(n) - already sorted
 * Average: O(n ^ 2) - partially sorted
 * Worst: O(n ^ 2) - completely unsorted.
 *
 * Space Complexity:
 * O(1)
 */
#include <stdio.h>


void bubble_sort(int *arr, int len)
{
	int i=0, j=0, tmp = 0;;
    
	for (i=0; i<len; i++) 
	{
		for (j = 0; j < len-1; j++) 
		{
			if(arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() 
{
    int i,inp_arr[10] = {1,2,3,4,5,6,7,8,9,10};

	bubble_sort(inp_arr, 10);
	
	for (i=0; i < 10; i++)
		printf(" %d\t", inp_arr[i]); 
     	
	printf("\n");
}
