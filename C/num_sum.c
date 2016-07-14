/*
 *
 *
 *
 */

#include <stdio.h>


int addDigits(int num)
{
    int digits = 0, sum = 0;
    int tmp  = num, tmp1  = num;

begin:
    while (tmp1) {
        tmp1 = tmp1 / 10;
        digits++;
    }

    while (digits)
    {
        sum += (tmp % 10);
        tmp = tmp / 10;
        digits--;
    }

    if ((sum / 10)) 
    {
        tmp1 = tmp = sum;
        digits = 0;
        sum =0;
        goto begin;
    }

    return sum;
}


int main ()
{
    int num = 9999;

    printf(" Num sum is : %d\n", addDigits(num));

    return 0;
}

