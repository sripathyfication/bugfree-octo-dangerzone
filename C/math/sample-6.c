#include<stdio.h>

#define SIZE 10
int size(int arr[SIZE]){

printf("Size of arr is %d\n",sizeof(arr));
}

int main(void) 
{
int arr[SIZE];
size(arr);
return 0;
}
