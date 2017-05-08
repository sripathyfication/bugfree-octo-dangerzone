/*
 * This is a voting algorithm to determine a majority element
 * in constant time and constant space.
 *
 *
 * m = 0 , i = 0
 *
 *  for (x = 0; x < size; x++)
 *     if (i == 0)
 *           m = arr[x]; i = 1
 *      else
 *          if arr[x] == m; i = i +1
 *          else i = i - 1 
 *   return m;         
 */

#include <iostream>
void print_array(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        std::cout  << arr[i] << " \t ";
    }
    std::cout << std::endl;
}


int boyer_moore_vote(int *arr, int size)
{
    int m = 0, i = 0;

    for (int j = 0; j < size; j++) {
        if (i == 0) { 
            m = arr[j] ; 
        } else {
            if (arr[j] == m) 
                i = i + 1;
            else 
                i = i - 1;
        }
    }

    return m;
}


int main() {

    int arr[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int ret = 0;

    print_array(arr, n);
    ret = boyer_moore_vote(arr,n);

    std::cout << std::endl << ret << std::endl;
}
