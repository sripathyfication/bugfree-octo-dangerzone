#include <iostream>
#include <math.h>

int shuffle (int *arr, int size) 
{
    /* fisher yates shuffle :
     *
     * for n -1 down to 1 do:
     * j = random such that 0 <= j <= i;
     * swap(a[j], a[i])
     *
     */

    srand(time(NULL));
    int j = 0;
    int tmp = 0;
    for (int i = (size -1); i >= 1; i--)
    {
       j = rand() % (i + 1); 
       tmp = arr[i];
       arr[i] = arr[j];
       arr[j] = tmp; 
    }

    return 0;
}

void print_array(int *arr) {

    for (int i = 0; i < 10; i++) {
        std::cout  << arr[i] << " \t ";
    }
    std::cout << std::endl;
}


int main () {

    int arr [10] = {1,2,4,1,5,3,4,7,6,8};

    std::cout << " Array before shuffle : " << std::endl;
    print_array(arr);
    shuffle(arr, 10);
    std::cout << " Array after shuffle : " << std::endl;
    print_array(arr);
}

