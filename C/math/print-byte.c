/* Prorgram to print each byte in an integer */
#include<stdio.h>


int main(void)
{

	int a=0x2bd75624;
	int i;

	printf("Whole integer: %x\n",a);

	for (i=0;i<sizeof(int);i++){
		printf("byte[%d]:0x%x\n",i, (a & 0xff));
		a >>= 8;
	}

	return 0;

}
