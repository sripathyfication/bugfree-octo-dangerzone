#/usr/bin/python

'''
    Given a binary tree, find the mirror.

    Another problem that can be solved by an inorder walk.

    Inorder, swap (left, right)
    recurse over left subtree
    recurse over right subtree
'''

class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

def print_tree(tree):
    if tree is None:
        return
    
    print_tree(tree.left)
    print tree.val
    print_tree(tree.right)

def swap(left, right):
    temp = left
    left = right
    right = temp

def mirror(tree):
    if tree is None:
        return

    swap(tree.left, tree.right)
    mirror(tree.left)
    mirror(tree.right)

if __name__ == '__main__':
    tree = Node(1)
    tree.left = Node(2)
    tree.right = Node(3)

    tree.left.left = Node(4)
    tree.left.right = Node(5)

    tree.right.left = Node(6)
    tree.right.right = Node(7)

    tree.right.left.left = Node(8)
    tree.right.left.right = Node(9)

    print "Printing tree"
    print_tree(tree)
    mirror(tree)
    print "Printing tree"
    print_tree(tree)
