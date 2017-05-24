#/usr/bin/python
from bst import Tree
def _height(node):
    if node is None:
        return 0
    if node and (node.left is None and node.right is None):
        return 1
    if node is not None:
        height = max(_height(node.left), _height(node.right)) + 1
    else:    
        height = 0

    return height

def height(tree):
    if tree is None:
        return 0

    if tree and (tree.get_root().left is None and tree.get_root().right is None):
        return 1

    return _height(tree.get_root())    

if __name__ == '__main__':
    t1 = Tree()

    t1.add(2)
    t1.add(1)
    t1.add(3)

    print height(t1)
