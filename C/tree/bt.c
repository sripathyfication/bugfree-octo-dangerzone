#include <stdio.h>
#include <stdlib.h>
#define MAX_ 500
/* binary tree node */
struct node {

    int value;
    struct node *left;
    struct node *right;
};

/* queue */
struct node* queue[MAX_];
int front = 0, rear = 0;

void enqueue(struct node* node)
{


}

struct node *dequeue();
{


}

/* utility functions */
struct node * new_node(int value)
{ 
    struct node * new = (struct node *) malloc(sizeof(struct node));
    if (new) {
        new->value = value;
        new->left = NULL;
        new->right = NULL;
        return new;
    } else {
        return NULL;
    }
}

void print_tree(struct node *root)
{
    struct node *tmp;
    if (!root) {
        return;
    }

    tmp = root;
    if(tmp) {
        printf(" -- %d -- \n", tmp->value);
        print_tree(tmp->left);
        print_tree(tmp->right);
    }
}

int main()
{
    struct node *root = new_node(5);
    root->left = new_node(2);
    root->right = new_node(3);

    root->left->left = new_node(4);
    root->left->right = new_node(1);


    root->right = new_node(6);

    print_tree(root);
}
