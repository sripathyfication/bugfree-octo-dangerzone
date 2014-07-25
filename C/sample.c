/* This file plays around with C constructs */
#include <stdio.h>

int main(void)
{
	char a = 'a';
	printf("sizeof int pointer:%d\n",(int)sizeof(int*));
	printf("sizeof char:%d\n",(int)sizeof('a'));
	printf("sizeof char:%d\n",(int)sizeof(a));
	printf("sizeof int pointer:%d\n",(int)sizeof(int*));
	printf("sizeof int pointer:%d\n",(int)sizeof(int*));
}

