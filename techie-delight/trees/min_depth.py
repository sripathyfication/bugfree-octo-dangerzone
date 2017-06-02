#/usr/bin/python
from bst import Tree

def min_depth(node):
    if node is None:
        return min_depth 
    if node.left is None and node.right is None:
        return 1
    if node.left is not None:
        min_left = min_depth(node.left)
    if node.right is not None:
        min_right = min_depth(node.right)
    return min(min_left, min_right) + 1


if __name__ == '__main__':
    t = Tree()
    t.add(5)
    t.add(3)
    t.add(2)
    t.add(4)
    t.add(6)


    print min_depth(t.get_root())

