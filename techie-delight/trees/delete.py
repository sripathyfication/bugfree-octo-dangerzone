#/usr/bin/python
#
# If root is null, return
#
# if node exists but left and right are null, set delete node.
#
# recurse over left tree and delete, recurse over right tree and delete, delete node.
# basically a post order traversal to delete tree.
#



from bst import Tree

def _delete(node):
    if node is None:
        return None
    if node and (node.left is None and node.right is None):
        node.value = 0
    if node is not None:    
        _delete(node.left)
        _delete(node.right)
        node.value = 0

def delete(tree):
    if tree is None:
        return None 

    if tree:
       tree.get_root().value = 0 
    
    _delete(tree.get_root())   

if __name__ == '__main__':
    t1 = Tree()
    t1.add(2)
    t1.add(1)
    t1.add(3)
    t1.add(5)
    t1.add(4)
    t1.add(6)


    t1.print_tree()

    delete(t1)

    t1.print_tree()
