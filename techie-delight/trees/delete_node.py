#/usr/bin/python

# Deletion of a node from a binarysearchtree
#
# 3 Cases:
#
# 1 . No child:- delete node directly
# 2. 1 child: - copy that child to this current node, delete the last child
# 3. 2 children - Find the inorder successor (the left most child on the right subtree) and
# replace the current node with that. Free the inorder successor.
#


from bst import Tree

def inorder_successor(node):
# the inorder successor is the leftmost child of the right subtree
    if node.right is not None:
        node = node.right
        while node and node.left is not None:
            node = node.left
    return node

def delete_node(node, val):
    if node is None:
        return
    while node is not None:
        parent = node
        if val < node.value:
            node = node.left
        elif val > node.value:
            node = node.right
        elif val == node.value:
            break
            
    print "Node to be deleted: " + str(node.value)
    if node.left is None and node.right is None:
        print "delete case 1"    
        node.value = 0
        node = None
    elif node.left is None or node.right is None:
        print "delete case 2"    
        if node.left is not None:
            node.value = node.left.value
            node.left = None
        if node.right is not None:
            node.value = node.right.value
            node.right = None    
    elif node.left is not None and node.right is not None:
         print "delete case 3"    
         inorder_node = inorder_successor(node)
         print inorder_node.value
         node.value = inorder_node.value
         inorder_node.value = 0
            

if __name__ == '__main__':
    t = Tree()

    t.add(5)
    t.add(3)
    t.add(4)
    t.add(1)
    t.add(8)
    t.add(6)

    t.print_tree()
    delete_node(t.get_root(), 5)
    t.print_tree()
