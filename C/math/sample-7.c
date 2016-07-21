#include<stdio.h>


int main(void) {

float a = 12.5;

printf("Size of float %d\n",sizeof(float));
printf("%d\n",a);
printf("%d\n",*(int *)&a);
return 0;


}
