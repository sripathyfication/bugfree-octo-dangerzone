/* Program that performs a quicksort */
#include <stdio.h>

int partition(int arr[],int p, int r)
{
	int x = arr[p];
	int j = r;
	int i = p;
	int tmp;
	

	while (i < j) {
		if ((arr[j] > x)) 
			j--;
		else if ((arr[i] < x)) 
			i++;
		else { 
			tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			j--;
			i++;
		}
	}
	
	if (j > i)
		return (j-1);


}

void quicksort(int arr[],int p, int r)
{
	int pivot;
	
	if (p < r) {
		pivot = partition(arr,p,r);
		quicksort(arr,p,pivot);
		quicksort(arr,pivot+1,r);
	}

}

int main(void) 
{
	int arr[8] = {5,3,2,6,4,1,3,7};
	int i;

	//Print it
	for(i=0;i<=7;i++)
		printf("%d \t",arr[i]);

	printf("\n");
	quicksort(arr,0,7);

	//Print it
	for(i=0;i<=7;i++)
		printf("%d \t",arr[i]);

	printf("\n");
	return 0;
}
