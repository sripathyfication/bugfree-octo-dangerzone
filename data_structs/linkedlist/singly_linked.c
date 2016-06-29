#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int index;
    struct node *next;
};


struct node *new_node(int data)
{
    static int index = 0;
    struct node *new;

    new = (struct node *) malloc (sizeof(struct node));

    if (new != NULL) {
        new->next = NULL;
        new->data = data;
        new->index = index;
    }

    index++;
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

void club_odd_even(struct node *head) 
{
    int count = 0;
    struct node* old_odd, *new_odd, *even, *first_even;

    if (!head) return;

    old_odd = head;
    first_even = even = head->next;

    if (old_odd && !even) return ;

    new_odd = even->next;

    while (even && new_odd) {
        if (!(count%2)) {
            //odd node
            old_odd->next = new_odd;
            even->next = new_odd->next;
            old_odd = new_odd;
            even = even->next;
            printf(" count: %d \n", count);
        } else {
            // even node
            new_odd = even->next;
        }
        count++;
    }

    old_odd->next = first_even;
                                
    return ;
}


bool is_cycle(struct node *head) 
{
    struct node* fast, *slow;
    bool has_cycle = false;

    if (!head) return has_cycle;

    slow = head;
    fast = head->next;

    if (slow && !fast) return has_cycle;

    while (slow && fast) {
        if (slow == fast) {
            has_cycle = true;
            break;
        } else {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return has_cycle;
}


void reverse_list(struct node **head) 
{
    struct node* prev, *curr, *next;

    if (!head) return;

    prev = NULL;
    curr = *head;
    next = curr->next;

    if (!next) return;

    while (curr) {

        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr)
            next = curr->next;
    }

    *head = prev;
    return;
}

void reverse_list_from_pos(struct node **head, int start, int end) 
{
    struct node* prev, *oldprev, *oldcurr,*curr, *next, *oldhead;
    int count = 0;

    if (!*head) return;

    oldprev = prev = NULL;
    oldhead = curr = *head;
    next = curr->next;

    if (!next) return;

    for (count = 0; count < start; count++) {
        oldprev = curr;
        curr = next;
        if (curr) next = curr->next;
    }

    oldcurr = curr;

    if (oldprev)
        oldprev->next = NULL;

    while (curr && (count < end)) {

        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr)
            next = curr->next;
        count++;
    }

    if (oldprev)
        oldprev->next = prev;

    if (oldcurr)
        oldcurr->next = curr;
    
    if (start == 0) 
        *head = prev; 
        

    return;
}



void print_list(struct node *tailref) 
{
    int index = 0;
    struct node *parse = tailref;
    printf(" ===========================\n");
    printf(" Printing singly linked list\n");
    printf(" ---------------------------\n");

    while (parse) {
        printf("Node [%d]: %d \n", parse->index ,parse->data);
        parse = parse->next;
        index++;
    }
}

int main() 
{
    int length = 0;
    struct node *head = NULL, *tail = NULL;
    bool has_cycle = false;

    push_node(1, &head, &tail);
    push_node(2, &head, &tail);
    push_node(3, &head, &tail);
    push_node(4, &head, &tail);
    push_node(5, &head, &tail);
    push_node(6, &head, &tail);
    push_node(7, &head, &tail);
    push_node(8, &head, &tail);
    //insert_node(2, &tail, &head);

    print_list(tail);

    //club_odd_even(tail);
    //print_list(tail);


//    reverse_list(&tail);
//    print_list(tail);

    reverse_list_from_pos(&tail,0,3);
    print_list(tail);
}

