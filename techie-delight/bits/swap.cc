#include <iostream>
/*
 * Here is the magic:
 *
 *  consider 6 and 8
 *
 *  6: 0110
 *  8: 1000
 *
 *  step 1, x: 0110 ^ 1000 = 1110
 *  step 2, y: 1110 ^ 1000 = 0110
 *  step 3, x: 1110 ^ 0110 = 1000
 *  new x = 8
 *  new y = 6
 *
 */
void swap(int &x, int &y) {
    if (x !=y ) {
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
    return;
} 

int main() {

    int x = 6, y = 8;
    printf(" %d and %d before swap\n", x,y);
    swap(x,y);
    printf(" %d and %d after swap\n", x,y);
    return 0;
}
