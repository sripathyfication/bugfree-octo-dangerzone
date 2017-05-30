#/usr/bin/python

# given a key, find the floor and ceiling.
#
#  floor and ceil = key, if key is found in tree.
#  else, for floor, save current node as floor and
#  search right sub tree
#
#  for ceil, save current node, and search left subtree
from bst import Tree


def has_key(node, key):
    if node is None:
        return False

    if key == node.value:
        return True

    if key < node.value:
        return has_key(node.left, key)
    else:
        return has_key(node.right, key)

def floor_ceil(node, key, floor, ceil):
    while node:
        if node.value == key:
            floor = node
            ceil = node
        elif key < node.value:
            ceil = node
            node = node.left
        else:
            floor = node
            node = node.right

if __name__=='__main__':

    t = Tree()

    t.add(6)
    t.add(2)
    t.add(3)
    t.add(9)
    t.add(7)

    t.print_tree()

    floor = None
    ceil = None
    floor_ceil(t.get_root(),1,floor,ceil)
    print floor, ceil
