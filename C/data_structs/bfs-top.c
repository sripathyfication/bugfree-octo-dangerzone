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

struct queue {
	struct node *nodes[MAX_Q];
	int head;
	int tail;
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

struct node * de_q(struct queue *q)
{
	struct node *dq;

	if (q->head == -1)	
		return NULL;
	
	dq = q->nodes[q->head];
	q->head++;

	return dq;
}

void en_q(struct queue *q,struct node* node)
{
	if (q->tail == -1) {
		// This is the first node
		q->tail++;
		q->nodes[q->tail] = node;		
		q->head = q->tail;
	}	
	
	q->nodes[q->tail] = node;
	q->tail++;
	
	return;
}


/* Function to do level order traversal */
void PrintLevelOrder(void)
{
	struct node* node;
	struct queue q;
	
	q.head =-1;
	q.tail =-1;
	node = head;
	while (node) {
		printf(" %d\n",node->data);
		if (node->left != NULL)
			en_q(&q,node->left);
		if (node->right != NULL)
			en_q(&q,node->right);

		node = de_q(&q);
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

	PrintLevelOrder();

	return 0;
}

