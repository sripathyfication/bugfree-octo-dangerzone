/* 
	Author: Sripathy Ramaswamy, July 2014
	Program to count set bits from bit k in an integer 
	and return the count

*/

#include <stdio.h>

/* function count_bits, creates a mask of k bits
   and does a bitwise and with integer, this result
   is counted for set bits
*/
int count_bits(int n, int pos)
{
	/* get a number equivalent to just k bits. */
	int count =0;
	int i =0;
	int num = n & ~(~0<<(pos+1));

	printf("num = %x\n",num);
	for (i=0;i <sizeof(int)*8;i++)
	{
		if (num & 0x1) count++;
		num = num >> 1;
	}
	
	return count;
}

/* Test program */
int main(void)
{
	int a = 0xbbbbbbbb;
	int num =0;
	
 	num = count_bits(a,5);
	printf("bits %d\n",num);
	return 0;
}
