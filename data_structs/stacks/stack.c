/*
 * Basic stack implementation
 *
 * MAX_SIZE can be changed by changing #define of same name.
 * push - pushes value to top of stack
 * pop  - pops a value from top of stack
 * stack_empty - checks if stack is empty
 * stack_full  - checks if stack is full.
 * print_stack - prints the stack.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 24
#define EMPTY -1

struct stack {
    int stack_store[MAX_SIZE]; // the value is stored here.
    int top;  // the top of the stack is stored here.
};

struct stack *stack;

void init_stack() 
{
    struct stack *s;

    s = (struct stack *) malloc (sizeof(struct stack));
    s->top = EMPTY;

    stack = s;
}

bool stack_full(struct stack *s) 
{
    if (s->top == (MAX_SIZE -1)) return true;
    else return false;
}

bool stack_empty(struct stack *s)
{
    if (s->top == EMPTY) return true;
    else return false;
}

void print_stack()
{
    struct stack *s = stack;
    int stack_iter; 

    printf("\nSTACK \n");
    printf("----- \n");
    if (stack_empty(s)) printf(" EMPTY STACK \n");

    stack_iter = s->top;

    while(stack_iter != EMPTY)
    {
        printf(" stack[ %d ]:  %d\n", stack_iter, s->stack_store[stack_iter]);
        stack_iter--;
    }
}


/* Returns, true - success
 *          false - stack is full
 */
bool push(int value)
{
    struct stack *s = stack;

    /* check if the stack is full */
    if(stack_full(s)) return false;

    /* increment the top pointer */
    s->top += 1;

    /* store the value at top */
    s->stack_store[s->top] = value;

    return true;
}

/* Returns, value if found
 *          EMPTY if stack is empty    
 */
int pop()
{
    int value = 0;
    struct stack *s = stack;

    /* check if stack is empty then return EMPTY */
    if (stack_empty(s)) return EMPTY;

    /* extract element at top to return */
    value = s->stack_store[s->top];

    /* decrement top to point to latest top */
    s->top -= 1;

    return value;
}

/* stack tester */
int main()
{
    int value = 0;
    init_stack();

    push(2);
    push(4);
    push(-1);
    push(3);

    print_stack();
     
    pop();
    pop();

    print_stack();
}


