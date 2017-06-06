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


/* sorted insert: iterate over the list and find the sorted position in the list and insert in
 * correct position
 */
void sorted_insert(struct node *insert, struct node **head)
{
    struct node *find = *head;
    struct node *prev = NULL;

    /* if head is null, insert becomes head */
    if (*head == NULL) {
        *head = insert;
        return;
    }

    /* else iterate over the list and find */ 
    while (find) {
        prev = find;
        if (find->data < insert->data) {
            find = find->next;
        } else {
            find = prev;
            break;
        }
    }

    insert->next = find->next;
    find->next = insert;
     
    return ;

}

/* driver program */
int main() {

    head = new_node(1);

    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(5);

    print_list(head);
    sorted_insert(new_node(4), &head);
    print_list(head);
    sorted_insert(new_node(6), &head);
    print_list(head);

    return 0;
}
