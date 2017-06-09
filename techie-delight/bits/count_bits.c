
#include <stdio.h>
#include <stdlib.h>

int set_bit_f(int n) {
    int count = 0, loop_count =0;

    printf(" BEGIN: %s\n",__FUNCTION__);
    while (n) {
        printf(" 0x%x\n",n);
        n = n & (n -1);
        count++;
        loop_count++;
    }
    printf(" END: %s LC: %d\n",__FUNCTION__, loop_count);
    return count;
}

int set_bit_s(int n) {
    int count = 0, loop_count =0;

    printf(" BEGIN: %s\n",__FUNCTION__);
    while (n) {
        printf(" 0x%x\n",n);
        if (n & 0x1)
            count++;
        n >>= 1;
        loop_count++;
    }

    printf(" END: %s LC: %d\n",__FUNCTION__, loop_count);
    return count;
}

int main() {
    int n = 0xa;

    printf(" # set bits in 0x%x is %d\n",n,set_bit_f(n));
    printf(" # set bits in 0x%x is %d\n",n,set_bit_s(n));

    return 0;
}
