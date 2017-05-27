#/usr/bin/python

# recursive solution to pre order traversal of tree
from bst import Tree

def preorder(node):
    
    if node is None:
        return None
    
    print node.value
    preorder(node.left)
    preorder(node.right)

    return


if __name__ == '__main__':
    t = Tree()

    t.add(5)
    t.add(8)
    t.add(2)
    t.add(3)
    t.add(1)
    t.add(6)
    t.add(9)


    t.print_tree()

    print "-- Preorder -- "
    preorder(t.get_root())
    print "-- End -- "
