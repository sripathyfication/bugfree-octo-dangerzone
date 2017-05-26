#/usr/bin/python

# in order traversal using a stack
#
# Iterative solution uses a stack
# 
# while stack is not empty or curr node is not null
#
# if curr node is not null
#  push node into stack 
#  move curr node to curr node's left
#
# if curr node is null
#   get top of stack in curr node
#   pop
#   print curr node's data
#   move curr node to curr node's right 
from bst import Tree
from stack import Stack

def inorder(tree):
    s = Stack()
    current = tree.get_root()

    if current is None:
        return None

    while ((s.is_empty() is not True) or (current is not None)):
        if current is not None:
            s.push(current)
            current = current.left
        else:
            current = s.get_top()
            s.pop()
            print " --> " + str(current.value)
            current = current.right
            

if __name__ == '__main__':

    t = Tree()

    t.add(5)
    t.add(2)
    t.add(4)
    t.add(1)
    t.add(7)
    t.add(6)
    t.add(8)

    t.print_tree()

    inorder(t)
