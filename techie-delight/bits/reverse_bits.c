#include<stdio.h>

#define GET(n,x) ((n & (1<<x))>>x)
#define SET(n,x) (n | (1<<x))
#define RESET(n,x) (n & ~(1<<x))
#define BITS_IN_CHAR 8
int reverse(unsigned char n) {
    int temp = n;
    int sbit = 0,ebit =0;
    int start = 0;
    int end = (sizeof(unsigned char) * BITS_IN_CHAR) - 1;

    while(start < end) {
        sbit = GET(n,start);
        ebit = GET(n,end);

        temp = sbit?SET(temp,end):RESET(temp,end);
        temp = ebit?SET(temp,start):RESET(temp,start);
        start++;
        end--;
    }

    return temp;
}


int main() {

    unsigned char c = 0x9;
    printf(" 0x%x reversed: 0x%x\n",c,reverse(c));

    return 0;
}
