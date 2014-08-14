/* Program to implement a double linked list */

#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node* prev;
	struct node* next;
};


struct node *new_node(int data)
{

	struct node *new = (struct node *)malloc(sizeof(struct node));

	if (new == NULL)
		return NULL;

	new->data = data;
	new->prev = NULL;
	new->next = NULL;


	return new;
}

void add_node(struct node **head,int data)
{
	struct node *temp,*new;

	new = new_node(data);	

	if (*head == NULL)
	{
		*head = new;
		return;
	}


	temp = *head;

	while (temp->next)
		temp = temp->next;

	temp->next = new;
	new->prev = temp;

	return;

}

void insert_sorted(struct node **head,int data)
{
	struct node *new,*insert;

	insert = *head;
	new = new_node(data);

	while(insert)
	{
		if (insert->data > data)
		{
			//Insert here
			new->next = insert;
			new->prev = insert->prev;
			insert->prev = new;
			new->prev->next = new;
		}
		else
			insert = insert->next;
	}

}

void traverse_print(struct node* head)
{

	int count;
	struct node *temp;	


	temp = head;
	count =0;
	while(temp) {
		printf("Node[%d]: %d\t",count,temp->data);
		temp = temp->next;
		count++;
	}

	printf("\n");
	
	return;
}

int main(void)
{
	struct node *head;

	head  = NULL;

	add_node(&head,4);
	add_node(&head,3);
	add_node(&head,4);
	add_node(&head,1);
	add_node(&head,2);
	add_node(&head,7);

	traverse_print(head);


	return 0;

}
