/*
 *  to add 1 to an integer.
 *
 *  Remember a negative number is stored as its 2's complement, which is ~x +1
 *
 *  so, -x = ~x + 1
 *
 *  -~x = x + 1;
 *
 *
 */
#include <iostream>

int main() {
    
    int x = 5;

    int y = -~x;

    std::cout << x << " +  1 is " << y << std::endl;

    return 0;
}
