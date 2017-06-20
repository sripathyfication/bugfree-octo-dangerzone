#/usr/bin/python

'''

    How to find the lowest common ancestor of a node:

    Lowest common ancestor is the node that is the parent node for a sub tree that has node x in
    left or right sub tree with node y being on the opposite subtree.


    First check if the node is present in the tree.
    if present then find_lca.
    find lca as follows;

    Base case:

    node == x  or node == y
        lca = node
        return true

    left = find_lca(left,lca,x,y)
    right = find_lca(right,lca,x,y)

    if left and right:
        lca = node

    return (left || right)    

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

def is_node_present(tree,val):
    if tree is None:
        return False

    if tree.val is val:
        return True

    return (is_node_present(tree.left,val) or is_node_present(tree.right,val))

def find_lca(node, x, y):
    if not node:
        return None,False

    if node.val == x or node.val == y:
        print "found" + str(node.val)
        return node,True

    some,left = find_lca(node.left,x,y)
    if some:
        print some.val, left
    some,right = find_lca(node.right,x,y)
    if some:
        print some.val, right

    if left and right:
        print node.val
        return node,True

    return node,(left or right)     

def _find_lca(tree, x, y):
    if tree is None:
        return None

    if (is_node_present(tree,x) and is_node_present(tree,y)):
        print str(x) + str(y) + " are present"
        node,present = find_lca(tree,x,y)

    print " got something: " + str(node.val)
    return node

if __name__ == '__main__':
    tree = Node(1)

    tree.left = Node(2)
    tree.right = Node(3)

    tree.left.left = Node(4)
    tree.left.right = Node(5)

    tree.right.left = Node(6)
    tree.right.right = Node(7)

    print_tree(tree)

    lca = _find_lca(tree,4,5)

    if lca:
        print lca.val
