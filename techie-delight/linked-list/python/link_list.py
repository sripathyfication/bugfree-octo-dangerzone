#/usr/bin/python
# python linked list implementation
# todo: add support for sorted insert

class list_node:
    def __init__(self,val):
        self.val = val
        self.next = None        

class singly_linked_list:
    def __init__(self):
        self.head = None

    def get_head(self):
        return self.head

    def set_head(self, node):
        self.head = node

    def add(self,val):

        print " .. adding node " + str(val)
        if self.head is None:
            self.head = list_node(val)
        else:
            self._add_node(self.head,val)

    def _add_node(self,node, val):           
        if node is None:
            return
        else:
            prev = None
            while node is not None:
                prev = node
                node = node.next
            prev.next = list_node(val)

    def remove(self,val):
        print " .. removing node " + str(val)
        if self.head is None:
            return
        else:
            self._remove_node(self.head,None,val)

    def _remove_node(self, node, prev ,val):
        if node is None:
            return
        else:
            if node.val is val:
                if node is self.head:
                    self.head = node.next
                else:
                    if prev is not None:
                        prev.next = node.next
                    node = None
            else:
                self._remove_node(node.next,node,val)
        return

    def print_list(self):        
        print "singly_linked_list "
        if self.head is None:
            print " -- . -- "
        else:
            self._print_list(self.head)
        print "---- . ---- "

    def _print_list(self,node):
        if node is None:
            return
        else:
            print str(node.val) + " --> "
            self._print_list(node.next)

# Test driver
if __name__ == '__main__':
    list_ = singly_linked_list()
    list_.add(1)
    list_.add(2)
    list_.add(3)
    list_.add(4)
    list_.add(5)

    list_.print_list()
    list_.remove(2)
    list_.print_list()
    list_.add(2)
    list_.remove(1)
    list_.print_list()
    list_.add(1)
    list_.print_list()
    list_.remove(1)
    list_.print_list()
