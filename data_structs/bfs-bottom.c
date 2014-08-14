/*
 Program to illustrate breadth first search 
 or level order traversal of binary tree 

 This program also does an insert of a node in a sorted manner.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX_Q 15

struct node *head;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct stack {
	struct node *nodes[MAX_Q];
	int top;
};

/* utility function to create new node */
struct node* new_node(int data)
{
	struct node *new;
	
	new = (struct node*)malloc(sizeof(struct node));

	if (new == NULL)
		return NULL;

	new->data = data;
	new->left = NULL;
	new->right = NULL;
	
	return new;
}

struct node * pop(struct stack *q)
{
	struct node *dq;

	if (q->top == -1)	
		return NULL;
	
	dq = q->nodes[q->top];
	q->top--;

	return dq;
}

void push(struct stack *q,struct node* node)
{
	q->top++;
	q->nodes[q->top] = node;		
	
	return;
}


/* Function to do level order traversal */
void PrintBottomTree(void)
{
	struct node* node;
	struct stack q;
	
	q.top =-1;
	node = head;
	while (node) {
		printf(" %d\n",node->data);
		if (node->left != NULL)
			push(&q,node->left);
		if (node->right != NULL)
			push(&q,node->right);
	}
	
	while (q.top !=-1)
	{
		node = pop(&q);
		printf("%d\n",node->data);
	}
	

	return;
}

int main(void) 
{
	
	head = new_node(5);

	head->left = new_node(3);
	head->right = new_node(4);

	head->left->left = new_node(0);
	head->left->right = new_node(1);

	head->right->left = new_node(6);
	head->right->right = new_node(7);

	PrintBottomTree();

	return 0;
}

