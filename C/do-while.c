#include<stdio.h>


int main(void) {
int i=1;

enum {false,true};

do {

printf("%d\n",i);
i++;
if (i < 15)
continue;
} while(false);
return 0;

}
