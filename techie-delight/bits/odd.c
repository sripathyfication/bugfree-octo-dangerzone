#include <stdio.h>

void bit(int n) {

    printf(" %x %x \n", n, -n);
    printf(" %x \n", n & -n);
}

int main() {

    int n = 6;
    bit(n);

    return 0;
}
