/*
 Program to illustrate breadth first search 
 or level order traversal of binary tree 

 This program also does an insert of a node in a sorted manner.
*/

#include<stdio.h>

#define MAX_Q_SIZE 500


struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct queue {
	struct node *node;
	struct queue *next;
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

void enqueue(struct node* node)
{


}


/* Function to do level order traversal */
void PrintLevelOrder(struct node* node)
{
	struct node *temp;
	
	temp = head;
	
	while(temp)
	{
		printf("%d\n",temp->data);	
		enqueue(temp->left);
		enqueue(temp->right);
		temp = dequeue();
	}

	return;
}

int main(void) 
{
	struct node *head;
	
	head = new_node(5);

	head->left = new_node(3);
	head->right = new_node(4);

	head->left->left = new_node(0);
	head->left->right = new_node(1);

	head->right->left = new_node(6);
	head->right->right = new_node(7);

	PrintLevelOrder(head);

	return 0;
}

