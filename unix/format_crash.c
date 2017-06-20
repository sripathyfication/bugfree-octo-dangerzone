#include<stdio.h>

/* In this example, we call printf passing it a format specifier but nothing as an argument.
 * Each time printf encounters a %s, it will take the current stack pointer to mean an adress
 * and go to that location and try to print out its contents. If it turns out that that location
 * had a valid address, then it will go that valid address and pick out the contents
 */
int main() {

    printf(" %s %s %s %s %s %s");

}
