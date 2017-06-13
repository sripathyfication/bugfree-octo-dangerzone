#/usr/bin/python

'''
    Efficient algorithm to delete a binary tree.

    Remember, while deleting, the root should be present before deleting left and right children,
    so, post order traversal!
'''

class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

def print_tree(tree):
    if not tree:
        return
    print_tree(tree.left)
    print tree.val
    print_tree(tree.right)

def delete_recursive(tree):
    if tree is None:
        return None

    delete_recursive(tree.left)
    delete_recursive(tree.right)
    tree.val = 0
    tree = None
    return tree

if __name__ == '__main__':
    tree = Node(5)
    tree.left = Node(3)
    tree.right = Node(7)

    tree.left.left = Node(2)
    tree.left.right = Node(4)

    tree.right.left = Node(6)
    tree.right.right = Node(8)

    print_tree(tree)
    delete_recursive(tree)
    print_tree(tree)
