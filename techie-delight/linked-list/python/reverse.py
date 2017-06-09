#/usr/bin/python

class Node:
    def __init__(self,val):
        self.val = val
        self.next = None


def print_list(node):
    print " list --> "
    while node is not None:
        print str(node.val) + " --> " 
        node = node.next

def reverse_list(head):
    prev = None
    first = head

    if head is None:
        return head

    second = head.next
    if second is None:
        return first

    while first is not None:
        first.next = prev
        prev = first
        first = second
        if second is not None:
            second = second.next

    return prev

if __name__ == '__main__':
    node1 = None

    print_list(node1)
    new_head = reverse_list(node1)
    print_list(new_head)
