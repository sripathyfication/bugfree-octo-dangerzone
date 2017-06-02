#/usr/bin/python

# python code to convert a binary search tree to
# a doubly linked list, circular and fully sorted
#
# left is akin to previous
# right is akin to next
#
# Logic is as follows:
#   do an inorder walk and push every element into a queue
#   once done,
#   dequeue each element and form the list while the queue is not empty
#   prev = null
#   head = null
#   while q is not empty:
#       node = dequeue()
#       if prev is not null:
#           prev.right = node
#       if head is null:
#           head = node
#           
#       prev = node
#   
#   prev.left = head    

from bst import Tree
from queue import Queue

def convert(node):
    

def _to_list(node):

if __name__ == '__main__':
    t = Tree()

    t.add(5)
    t.add(3)
    t.add(4)
    t.add(2)
    t.add(7)
    t.add(6)
    t.add(8)
