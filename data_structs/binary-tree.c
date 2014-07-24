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


int main(void)
{
	struct tree *root = NULL;


	root = new_node(5);
	
	root->left = new_node(4);
	root->right = new_node(3);

	PrintInorder(root);


}
