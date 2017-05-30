#/usr/bin/python

# Algorithm to convert a binary tree to a binary search tree
#
# Do an inorder traversal and store the values in a list.
# Sort the list Or better still use a multimap or a set.
# Then do an inorder traversal again and replace data of each node 
# with list value.
from bst import Tree


bst =[] 
def qsort(a):
    if not a:
        return []
    first = a[0]
    lesser = filter(lambda i: i < first, a[1:])
    greater = filter(lambda i: i >= first, a[1:])
    return qsort(lesser) + [first] + qsort(greater)

def convert_to_bst(node,index):
    if node is None:
        return

    convert_to_bst(node.left,index)
    
    node.value = bst[index]
    print node.value
    index = index + 1
    convert_to_bst(node.right,index)

def to_list(node):
    if node is None:
        return

    to_list(node.left)
    bst.append(node.value)
    to_list(node.right)


if __name__ == '__main__':
    t = Tree()

    t.add(5)
    t.add(3)
    t.add(6)
    t.add(9)
    t.add(2)
    t.add(4)

    t.print_tree()

    to_list(t.get_root())
    qsort(bst)
    index = 0
    convert_to_bst(t.get_root(),index)
