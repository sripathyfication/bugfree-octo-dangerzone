/*
Given a sorted array of N distinct elements. Find a key in the array using least number of comparisons.
 (Do you think binary search is optimal to search a key in sorted array?)
*/
#include <stdio.h>

// Simple binary search function
int bin_search(int arr[],int num, int x)
{
	int left,right,middle;
	
	left = 0;
	right = num-1;

	while(left <= right)
	{
		middle = (left + right) / 2;
		if (arr[middle] == x) return middle;
		if (arr[middle] > x) right = middle;
		else left = middle; 
	}	

	return -1;
}


// Driver program
int main(void)
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	int find = 5;
	
	if ((find = bin_search(arr,6,find))==-1)
		printf("Number not found\n");
	else
		printf("Found at index %d\n",find);

	return 0;


}
