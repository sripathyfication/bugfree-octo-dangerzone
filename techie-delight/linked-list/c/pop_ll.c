#include <stdio.h>
#include <stdlib.h>

/* linked list structure */
struct node{
    int data;
    struct node * next;
} ;

/* head data structure */
struct node *head;

/* print list */
void print_list (struct node *head) 
{
    struct node *print = head;
    int count = 0;
    if (head == NULL) { printf("head is null \n"); return;}

    while (print != NULL) {
        if (print->next)
            printf(" %d --> ", print->data);
        else
            printf(" %d ", print->data);
        print = print->next;
    }
    
    printf("\n");
    return;
}

/* new node */
struct node * new_node(int data) {

    struct node *new = (struct node *) malloc (sizeof(struct node));
    if (new) {
        new->data = data;
        new->next = NULL;
    }

    return new;
}

/* push : push a new node to the top of the linked list  and return new head */
void push(struct node **head, int data)
{
    struct node *newhead = new_node(data);

    if (*head == NULL)
        *head = newhead;

    if (*head) { 
        newhead->next = *head;
        *head = newhead;
    }

    return;
}


/* pop : Pop the head, free the node, update new head, return the data*/
int pop (struct node **head) 
{
    int data = -1;
    struct node *pop;

    /* check if head exists */
    if (*head == NULL) 
        return data;

    /* check if head is the only node */
    if ((*head)->next == NULL) {
        data = (*head)->data;
        free(*head);
        *head = NULL;
        return data;
    }

    /* else, there is atleast one more node in the linked list move head before popping */
    pop = *head;
    *head = (*head)->next;
    data = pop->data;
    free(pop);
    return data;
}

/* driver program */
int main() {

    head = new_node(1);

    head->next = new_node(2);
    head->next->next = new_node(3);

    print_list(head);

    printf(" popping head.. %d\n", pop(&head));
    print_list(head);

    printf(" pushing .. 1\n");
    push(&head, 1);
    printf(" pushing .. 90,89,88\n");
    push(&head, 90);
    push(&head, 89);
    push(&head, 88);
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);
    printf(" popping head.. %d\n", pop(&head));
    print_list(head);

    return 0;
}
