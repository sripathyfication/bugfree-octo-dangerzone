#/usr/bin/python

class Node:
    def __init__(self,val):
        self.val = val
        self.next = None

def print_list(node):
    string = "List::--> "
    while node is not None:
        string = string + str(node.val) + "-->"
        node = node.next
    print string 

def loop_detect(head):

    if head is None:
        return False

    if head.next is None:
        return False

    second = head
    first = second.next

    while first is not None and first is not second:
        first = first.next
    
    if first is second:
        print " Loop detected:: " + str(first) + str(second)
        return True
    else:
        return False    

if __name__ == '__main__':
    node = Node(1)
    node.next = Node(2)
    node.next.next = Node(3)
    node.next.next.next = node

#print_list(node)

    print " Is there a loop? " + str(loop_detect(node))
