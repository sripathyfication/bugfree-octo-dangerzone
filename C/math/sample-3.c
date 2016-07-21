#include<stdio.h>
#include<stdlib.h>

int main(void)
{
int *p1,p2;

p1 = (int*)malloc(sizeof(int));
p2=p1;
*p2 = 10;
return 0;

}
