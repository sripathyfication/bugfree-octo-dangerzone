#/usr/bin/python

# remove nth node from the end of a linked list
from link_list import singly_linked_list

def remove_nth_from_end(list_,n):
    list_ptrs = []
    head = list_.get_head()
    if head is None:
        return

    node = head

    while node is not None:
        list_ptrs.append(node)
        node = node.next

    print " Total nodes in linked list " + str(len(list_ptrs))    
    print " Node to removed from end " + str(n)
    node_to_remove = (len(list_ptrs)) - (n -1)
    print " Node to removed " + str(node_to_remove)

    if node_to_remove is (len(list_ptrs)):
        print list_ptrs[node_to_remove - 2].val
        list_ptrs[node_to_remove - 2].next = None
    elif node_to_remove == 1 :
        list_.set_head(list_ptrs[1])
    else:
        list_ptrs[node_to_remove -2].next = list_ptrs[node_to_remove ]

if __name__ == '__main__':
    list_ = singly_linked_list()

    list_.add(1)
    list_.add(2)
    list_.add(3)
    list_.add(4)
    list_.add(5)
    list_.add(6)


    list_.print_list()
    remove_nth_from_end(list_,1)
    list_.print_list()
    list_.add(6)
    list_.print_list()
    remove_nth_from_end(list_,6)
    list_.print_list()
    list_.add(1)
    list_.print_list()
    remove_nth_from_end(list_,2)
    list_.print_list()







