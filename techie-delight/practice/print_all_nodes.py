#/usr/bin/python

'''
    Print all paths from Root to leaf node:
    --------------------------------------

    1.Do an inorder traversal and keep pushing into a list until a leaf is not encountered.
    2.If a leaf is encountered, print the list
    3.Recurse over left subtree
    4.Recurse over right subtree
'''

class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

def is_leaf(node):
    if node is None:
        return False
    else:
        if node and node.left is None and node.right is None:
            return True

def print_all_paths(tree,paths):
    if tree is None:
        return

    paths.append(tree.val)

    if (is_leaf(tree)):
        print paths

    print_all_paths(tree.left,paths)
    print_all_paths(tree.right,paths)    


if __name__ == '__main__':
    paths = []
    tree = Node(1)
    tree.left = Node(2)
    tree.right = Node(3)

    tree.left.left = Node(4)
    tree.left.right = Node(5)

    tree.right.left = Node(6)
    tree.right.right = Node(7)

    tree.right.left.left = Node(8)
    tree.right.left.right = Node(9)

    print_all_paths(tree,paths)
