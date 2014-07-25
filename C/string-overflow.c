/* sample code to demo buffer overflow*/
#include<stdio.h>

int main(void) 
{
char str[80];
printf("Enter a string\n");
scanf("%s",str);

printf("You entered %s\n",str);
return 0;


}
