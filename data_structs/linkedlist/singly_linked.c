#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


struct node *new_node(int data)
{
    struct node *new;

    new = (struct node *) malloc (sizeof(struct node));

    if (new != NULL) {
        new->next = NULL;
        new->data = data;
    }

    return new;
}

void insert_node(int data, struct node **tailref, struct node **headref)
{
    struct node *temp, *new;

    new = new_node(data);

    if (new == NULL) {
        return;
    }

    if (*tailref == NULL) {
        *headref = *tailref = new;
        return;
    }

    temp = *tailref;

    // find end
    while (temp->next) {
        temp = temp->next;
    }

    // found end.
    *tailref = temp->next = new;

    return;
}

void push_node(int data, struct node **headref, struct node **tailref) 
{
    struct node *new, *temp;
    
    new = new_node (data);

    if (new == NULL) {
        return;
    }

    if (*headref == NULL) {
        *tailref = *headref = new;
        return;
    }

    temp = *headref; 
    temp->next = new;

    *headref = new;
    return;
}

void print_list(struct node *tailref) 
{
    int index = 0;
    struct node *parse = tailref;

    while (parse) {
        printf("Node [%d]: %d \n", index ,parse->data);
        parse = parse->next;
        index++;
    }
}

int main() 
{
    int length = 0;
    struct node *head = NULL, *tail = NULL;

    push_node(5, &head, &tail);
    push_node(2, &head, &tail);
    push_node(1, &head, &tail);
    push_node(4, &head, &tail);
    //insert_node(2, &tail, &head);

    print_list(tail);
}

