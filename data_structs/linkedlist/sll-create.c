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

//Function to add node to the list
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

// Function to reverse a linked list
void reverse_list(struct node** head)
{

	struct node *tmp;
	struct node *prev;
	struct node *current;	
	int count=0;

	current = *head;
	prev = NULL;

	while (current)
	{

		tmp = current->next;
		current->next = prev;
		prev = current;
		//printf("Node[%d]: %d\t",count,current->data);
		if (tmp == NULL)
			*head = current;
		current = tmp;
		count++;
	}

	return;
}

// Function to delete a node in a linked list
void delete_node (struct node **head, int index)
{
	struct node *delete,*prev;
	int count = 0;

	prev = NULL;
	delete = *head;

	while(delete)
	{
		if (count == index)
		{
			//this is the node to be deleted
			if (delete == *head) 
			{
				*head = delete->next;
				free(delete);
			}
			else
			{
				prev->next = delete->next;
				free(delete);
			}
		}		
		prev = delete;
		delete = delete->next;
		count++;

	}
}

// Function to traverse and print a linked list
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
	
	printf("\n");
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

	printf("Created linked list\n");
	traverse_print(head);

	reverse_list(&head);

	printf("Reversed linked list\n");
	traverse_print(head);

	delete_node(&head,2);

	printf("Deleting node at index 2\n");
	traverse_print(head);

	add_node(&head,3);

	return 0;
}
