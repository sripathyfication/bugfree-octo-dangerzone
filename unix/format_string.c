#include<stdio.h>

/*
 * A regular format string
 *
 *
 * This is how the stack frame looks when printf is called.
 * Stack is growing upwards
 * printfs internal pointer moves in the opposite direction
 *
 * address of format string
 * pak
 * india
 *
 * What happens when printf encounters a format specifier, but no argument was pushed for it on
 * the stack. It will try to pick it up from the current stack pointer.
 */ 
int main(){
    char india[5] = "india";
    char pak[3] = "pak";
    printf(" Today I learned that %s beat %s in the ICC champions trophy\n", pak, india);
    return 0;
}
