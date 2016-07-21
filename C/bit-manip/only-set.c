/* Find position of only set bit */
#include <stdio.h>

int position(int a)
{
	int i,j=0;
	int arr[4]={0x1,0x2,0x4,0x8};

	if (!a) return 0;
	
	for (i=0;i<sizeof(int)*2;i++){
		if (a & 0xf)
		{
			for(j=0;j<4;j++)
				if(arr[j]== a)
					return (j + (i*4));

		}
		else
		{
			a= a>>4;
		}
	}

}


int main(void)
{
	int b = 0x200000;

	printf("Position %d\n",position(b));
	return 0;
}
