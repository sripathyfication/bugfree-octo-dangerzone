#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    int index;
    struct node *next;
};


void print_list(struct node *head) 
{
    int index = 0;
    struct node *parse = head;
    printf(" ===========================\n");
    printf(" Printing singly linked list\n");
    printf(" ---------------------------\n");

    while (parse) {
        printf("Node [%d]: %d \n", parse->index ,parse->data);
        parse = parse->next;
        index++;
    }
}



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

void push_node(int data, struct node **headref) 
{
    struct node *new, *tmp;
    
    new = new_node (data);

    if (new == NULL) {
        return;
    }

    if (*headref == NULL) {
        *headref = new;
        return;
    }

    new->next =  *headref; 
    *headref = new;

    return;
}

int get_length(struct node *head)
{
    int len = 0;
    struct node *tmp = head;

    while (tmp) { len++; tmp = tmp->next; }

    return len;
}


void front_back_split(struct node *head, struct node **first_head, struct node **second_head)
{
    int half_length, length, first_len, second_len, tmp_len;

    /* sanity checks */
    if (!head) {
       *first_head = NULL;
       *second_head = NULL;
       return;
    }

    if (!head->next) {
       *first_head = *second_head = head;
       return;
    }

    length = get_length(head); 
    half_length = length /2 ; 

    if (length % 2)  { 
       first_len = half_length + 1;
       second_len = half_length;
    } else {
       first_len = second_len = half_length;
    }

    /* create front half */
    struct node *tmp = head;
    tmp_len = first_len;
    while (tmp && tmp_len) {
        push_node(tmp->data, first_head);   
        tmp_len--;
        tmp = tmp->next;
    }

    print_list(*first_head);

    /* create second half */
    tmp = head;
    tmp_len = first_len;

    /* traverse to start of second half */
    while (tmp && tmp_len) {
        tmp = tmp->next;
        tmp_len--;
    }

    while (tmp && second_len) {
        push_node(tmp->data, second_head);   
        second_len--;
        tmp = tmp->next;
    }

    print_list(*second_head);

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



void print_menu() 
{

    printf(" \n \n");
    printf(" SINGLY LINKED LIST OPERATIONS\n");
    printf(" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" u -- Reverse the list from a position \n");
    printf(" r -- Reverse the entire list \n");
    printf(" c -- Club odd and even nodes of the list \n");
    printf(" p -- Print the list \n");
    printf(" l -- Print the length of the list \n");
    printf(" d -- Delete  a node  from list \n");
    printf(" f -- Split singly linked list into front and back halves \n");
    printf(" e -- Exit \n");
    printf(" \n \n");
}


int main(int argc, char **argv) 
{
    int length = 0;
    char option;
    struct node *head = NULL, *front_head = NULL, *back_head = NULL;
    bool has_cycle = false;

    push_node(1, &head);
    push_node(2, &head);
    push_node(3, &head);
    push_node(4, &head);
    push_node(5, &head);
    push_node(6, &head);
    push_node(7, &head);
    push_node(8, &head);

    print_menu();
    while (1) {
        scanf("%c", &option);
        switch (option) {
            case 'u':
                printf(" Reversing linked list from position \n");
                reverse_list_from_pos(&head,0,3);
                break;
            case 'r':
                printf(" Reversing the linked list \n");
                reverse_list(&head);
                break;
            case 'c':
                printf(" Club odd and even nodes \n");
                club_odd_even(head);
                break;
            case 'd':
                break;
            case 'f':
                printf(" Splitting front to back \n");
                front_back_split(head, &front_head, &back_head);
                break;
            case 'l':
                printf(" Length of the list: %d \n", get_length(head));
                break;
            case 'e':
                printf(" Exiting..\n");
                exit(0);
            case 'p':
                print_list(head);
                break;
            default:
                print_menu();
                break;
        }
    }

    return 0;
}

