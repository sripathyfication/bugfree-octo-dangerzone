/*
 * To detect if two numbers have the opposite sign:
 *
 * x, y are opposite IFF x ^ y < 0
 *
 */
#include <iostream>

int main()
{
    int x = 5, y = -5;
    int z = x ^ y;

    if ( z < 0) std::cout << x << "  and " << y << " are opposite" << std::endl; 
    else std::cout << x << " and " << y << " are the same" << std::endl;
    

    return 0;
}
