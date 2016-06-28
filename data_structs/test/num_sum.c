#include <stdio.h>

int arr[6] = {3,2,4,7,1,-6};
int target = 4;

struct hash_map {
    int index;
    int value;
};

struct hash_map *hashes;


int main() 
{

    int i = 0;

    for (int i= 0; i < 6; i++) {
        for (int j = i+1; j < 6; j++) {
            if ((arr[i] + arr[j]) == target) {
                arr_indices[0] = j;
                arr_indices[1] = i;
                break;
            }
        }
    }

    printf (" The indices are : %d %d\n", arr_indices[0], arr_indices[1]);
    return 0;
}

