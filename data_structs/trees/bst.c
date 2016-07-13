/*
 * Binary Search Tree
 *
 */

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree *root;

struct tree * new_node(int val)
{
    struct tree *new = (struct tree *) malloc(sizeof(struct tree));

    if (NULL == new) return new;

    new->data = val;
    new->left = NULL;
    new->right = NULL;

    return new;
}

int main ()
{

    struct tree *tmp;

    tmp = new_node(5);

    tmp->left = new_node(6);
    tmp->right = new_node(4);

    tmp->left->left = new_node(7);
    tmp->right->right = new_node(8);


}
