#/usr/bin/python

# Level order traversal of a binary tree
# using a queue is the best way.
#
# enqueue root
#
# while q is not empty:
#   dequeue an element
#   print it
#   if element has a left:
#       enqueue the left
#   if element has a right:
#       enqueue the right
   

from bst import Tree
from queue import Queue


def level_order(node):
    if node is None:
        return None

    q = Queue()
    q.enqueue(node)

    while q.is_empty() is not True:
        elem = q.dequeue()
        print elem.value

        if elem.left is not None:
            q.enqueue(elem.left)
        if elem.right is not None:
            q.enqueue(elem.right)    

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

    print "-- BFS -- "
    level_order(t.get_root())
    print "-- End -- "
