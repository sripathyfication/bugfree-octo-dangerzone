/*Code for binary tree construction, inorder, preorder and post order traversal */
#include <stdio.h>
#include <stdlib.h>

struct tree {
	int value;
	struct tree *left;
	struct tree *right;
};

/* function to create new node */
struct tree * new_node(int value)
{
	struct tree *new;
	
	new = (struct tree *)malloc(sizeof(struct tree));
	if (NULL==new)
		return NULL;

	new->value = value;
	new->left = NULL;
	new->right = NULL;

	return new;

}

/* function to do inorder traversal */
void PrintInorder(struct tree *node)
{
	if (node == NULL)
		return;
	
	/* Print left subtree */
	PrintInorder(node->left);
	
	/* Print current node */
	printf("%d\t",node->value);

	
	/*Print right subtree */
	PrintInorder(node->right);

}

void PrintPostOrder( struct tree *root)
{
    if (root == NULL)
        return;

    printf(" %d \t", root->value);

    PrintPostOrder(root->left);

    PrintPostOrder(root->right);

    return;
}

void PrintPreOrder(struct tree *root)
{
    if (root == NULL)
        return;

    PrintPreOrder(root->left);
    PrintPreOrder(root->right);

    printf(" %d\t", root->value);

}

int main(void)
{
	struct tree *root = NULL;


	root = new_node(5);
	
	root->left = new_node(4);
	root->left->left = new_node(2);
	root->left->right = new_node(3);
	root->right = new_node(3);
	root->right->left = new_node(1);

	PrintInorder(root);
    printf("\n");
	PrintPreOrder(root);
    printf("\n");
	PrintPostOrder(root);

	return 0;
}
