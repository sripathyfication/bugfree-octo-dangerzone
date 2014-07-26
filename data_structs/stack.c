/* Program to implement a stack */

#include <stdio.h>

#define MAX_SIZE 24
struct stack {
	int arr[MAX_SIZE]; //Array containing elements in stack
	int top; //Index to top of stack.
};

struct stack *stack;

int stack_empty (struct stack *s) {
	if (s->top == -1) return 1;
	else return 0;

}
void push(struct stack *s,int element) {

	s->top = s->top +1;
	s->arr[s->top] = element;

	return;
}

int pop(struct stack *s) {
	
	//Check if empty
	if (stack_empty(s)) return -1;

	//Else really pop
	s->top = s->top -1;
	return (s->arr[s->top +1]);
}


int main() {

	struct stack head;
	int i;
	
	head.top =-1;

	push(&head,1);
	push(&head,2);
	push(&head,31);
	push(&head,11);
	push(&head,4);
	push(&head,8);
	push(&head,9);


	printf("Popping..\n");
	for(i=0; i < MAX_SIZE; i++) {
		printf("%d\n",pop(&head));
	} 

	return 0;
}


