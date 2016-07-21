/*Code for binary tree construction, inorder, preorder and post order traversal */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int max_of (int one, int two) {
    if (one >= two) return one;
    else return two;
}

/*
 * max depth of a binary tree 
 */
int maxDepth(struct tree *root)
{
    int max = 0, d_left = 0, d_right = 0;
    if (!root) return 0;

    if (root->left) {
        d_left = maxDepth(root->left);
    }

    if (root->right) {
        d_right = maxDepth(root->right);
    }

    max = max_of(d_left, d_right);

    return (max + 1);
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

    printf("%d \t", root->value);

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

    printf("%d\t", root->value);

}

/* Do in order traveral of both trees and compare 
 * the data 
 * 
 */
bool isSameTree(struct tree *tree1, struct tree *tree2)
{
    if (!tree1 && !tree2) return true;
    if ((!tree1 && tree2) || (!tree2 && tree1)) return false;

    if (tree1->value == tree2->value) 
        return (isSameTree(tree1->left, tree2->left) && isSameTree(tree1->right, tree2->right));
    else
        return false;
}

int main(void)
{
    char *true_s = "TRUE";
    char *false_s = "FALSE";
	struct tree *root = NULL;
    struct tree *tree = NULL;


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
    printf("\n");

    int d = maxDepth(root);

    printf("Max depth is: %d\n", d);


    tree = new_node(5);
	tree->left = new_node(4);
	tree->left->left = new_node(2);
	tree->left->right = new_node(3);
	tree->right = new_node(3);
	tree->right->left = new_node(1);

    printf(" Root and Tree are same? %s \n", isSameTree(root, tree) ? true_s : false_s);
	return 0;
}
