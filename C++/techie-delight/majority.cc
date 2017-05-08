#include <iostream>
#include <unordered_map>

void print_array(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        std::cout  << arr[i] << " \t ";
    }
    std::cout << std::endl;
}



int majority(int *arr, int size) 
{
    std::unordered_map<int, int> major;

    for (int i = 0; i < size; i++) {
        major[arr[i]]++;
    }

    for (auto pair:major)
        if (pair.second > size/2)
            return pair.first;

    return 0;
}


int main() {

    int arr[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
    int n = sizeof(arr)/sizeof(arr[0]);

    print_array(arr,n);
    int ret = majority (arr, n);
    if (ret) {
        std::cout << " majority element is: " << ret << std::endl;
    } else {
        std::cout << " majority element doesn't exist " << std::endl;
    } 

    return 0;
}
