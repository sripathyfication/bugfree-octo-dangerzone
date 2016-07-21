/*
 Program to swap two nibbles in a byte
*/

#include <stdio.h>

int swap_nibble(int a)
{
	return (((a & ~(~0<<4))<<4) | (a >> 4));
}

int main(void)
{

	int a = 0x64;
	int b=0;
	
	printf("Before swap:%x\n",a);
	b = swap_nibble(a);
	printf("After swap:%x\n",b);

	return 0;

}
