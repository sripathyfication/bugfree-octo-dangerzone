#include <stdio.h>

char is_odd(int n) {
    return (n & 0x1);
}

int main() {
    int n = 6;
    printf(" n = %d is_odd: %d\n", n, is_odd(n)); 
    return 0;
}
