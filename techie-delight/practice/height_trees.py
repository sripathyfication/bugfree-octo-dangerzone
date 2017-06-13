#/usr/bin/python

'''
Recursive and iterative solution
'''

class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Queue:
    def __init__(self):
        self.list_ = []
    def is_empty(self):
        ret = False
        if not self.list_:
            ret = True
        return ret

    def size(self):
        return len(self.list_)

    def enqueue(self,val):
       self.list_.insert(0,val)
    def dequeue(self):
        return self.list_.pop()


def print_tree(root):
    if not root:
        return
    print_tree(root.left)
    print root.val
    print_tree(root.right)

def height_recursive(root):
    if root is None:
        return 0
    return (max(height_recursive(root.left),height_recursive(root.right)) +1)

def height_iterative(tree):
    if not tree:
        return 0
    height = 0
    queue = Queue()

    queue.enqueue(tree)

    while queue.is_empty() is not True:
        size = queue.size()
        while size:
            node = queue.dequeue()
            if node.left is not None:
                queue.enqueue(node.left)
            if node.right is not None:
                queue.enqueue(node.right)
            size -= 1
        height +=1

    return height

if __name__ == '__main__':
    tree = Node(5)

    tree.left = Node(3)
    tree.right = Node(7)
    tree.left.left = Node(2)
    tree.left.right = Node(4)

    tree.right.left = Node(6)
    tree.right.right = Node(8)


    print height_recursive(tree)
    print height_iterative(tree)
