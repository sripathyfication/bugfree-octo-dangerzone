/* Program to create a singly linked list and print it */
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data; //value
	struct node* next; //pointer to next node
};

// Function to create a new node and return pointer to it.
struct node* new_node(int value) 
{
	struct node *new;

	new = (struct node*)malloc(sizeof(struct node));
	if (NULL == new)
		return NULL;

	new->data = value;
	new->next = NULL;
	
	return new;
}

void add_node(struct node **head,int value)
{

	struct node* new,*tmp;

	new = new_node(value);

	if(*head == NULL)
	{
		// this is the very first node
		*head = new;
		return;
	}

	// There are other nodes.
	//Browse and insert at end
	tmp = *head;
	while(tmp->next){
		tmp = tmp->next;
	}

	tmp->next = new;
	return;
}

void reverse_list(struct node* head)
{

	struct node *tmp;
	struct node *prev;
	struct node *current;	

	current = head;
	prev = NULL;
	tmp = NULL;

	while (current)
	{

	current->next = tmp;
	

	}

}

void traverse_print(const struct node *head)
{
	const struct node* trav;
	int count=0;

	trav = head;
	while (trav)
	{
		printf("Node[%d]: %d\t",count,trav->data);
		count++;
		trav = trav->next;
	}
	
	return;

}

//Driver program
int main(void)
{

	struct node* head;
	
	add_node(&head,2);
	add_node(&head,2);
	add_node(&head,4);
	add_node(&head,3);
	add_node(&head,1);
	add_node(&head,9);

	traverse_print(head);
	return 0;
}
