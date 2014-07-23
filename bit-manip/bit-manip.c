/* Program to count set bits from the bit k in an integer */

#include <stdio.h>

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

int main(void)
{
	int a = 0x3636;
	
	int num =0;
	
 	num = count_bits(a,5);

	printf("bits %d\n",num);
}
