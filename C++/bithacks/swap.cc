/*
 * two swap 2 numbers without using a third variable just xor them
 *
 *
 * x = x ^ y  <== new x contains all the bits different between x and y.
 * y = x ^ y <== new y contains all the bits different between new x and old y, which is old x 
 * x = x ^ y <== new x will now contains all the bits different between x and new y, which y.
 *
 */
#include <iostream>

int main() {

    int x = 10, y =9;

    std::cout << " Before swap : " << x << "  " << y << std::endl;

    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    std::cout << " Afer swap : " << x << "  " << y << std::endl;
    return 0;
}
