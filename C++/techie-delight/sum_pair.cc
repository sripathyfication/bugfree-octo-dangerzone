#include <iostream>
#include <unordered_map>

int arr[10] = {1,4,2,6,10,34,5,12,3};

using namespace std;

int find_sum(int *arr, const int size, int sum, int& x, int& y) {

    std::unordered_map<int, int> sum_set;

    x = 0;
    y = 0;

    for (int i = 0 ; i < size; i++) {

        if (sum_set.find(sum - arr[i]) != sum_set.end()) {
            x = i;
            y = sum_set[(sum - arr[i])]; 
            return 0;
        }
        /* store the element and return */
        sum_set[arr[i]] = i;
    }


    if ( x == 0 && y == 0)
        return -1;
    else 
        return 0;
}

void print_array(int *arr) {

    for (int i = 0; i < 10; i++) {
        std::cout  << arr[i] << " \t ";
    }
    std::cout << std::endl;
}


int main() {

    int s = 100;
    int x =0, y = 0;
    std::cout << " Find sum " << s << " in array : " << std::endl;
    
    print_array(arr);

    if (find_sum(arr,10, s, x, y) == 0){
        std::cout << " Found sum " << s << " elements : " << x << " and " << y << std::endl;
    } else {
        std::cout << " Element not found" << std::endl;
    }

    return 0;
}
