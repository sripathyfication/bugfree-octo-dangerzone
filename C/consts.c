#include <stdio.h>


int main() {
    int a = 10, b = 20;
    int const c = 50;
    /* constant pointer to mutable int */
    int  * const p = &a;
    printf(" %d \n", *p);
    //p = &b; <--- this line will generate compiler error as p is declared a const.

    /* mutable pointer to a constant int */
    int const *q = &a; 
    printf(" %d \n", *q);
    q = &b; // pointer q can be re assigned a different variable.
    printf(" %d \n", *q);
    
    int const *r = &a; // So, really even though I said here that this is a pointer to a constant
    //integer , the compiler doesn't check to see if a is a constant integer or not.
    printf(" %d \n", *r);


    /* constant pointer to a constant integer */
    int const * const s = &c;
    printf(" %d\n",*s);
    //s = &a;  << this line will throw a compilation error
    //c = 230; << this line will throw a compilation error    
    printf(" %d\n",*s);
    return 0;
}
