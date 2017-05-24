#/usr/bin/python

class Node():
    def __init__(self,val):
        self.value = val
        self.left = None
        self.right = None
        
class Tree:
    def __init__(self):
        self.root = None
        
    def add(self, val):
        if self.root is None:
            self.root = Node(val)
        else:
            self._add(self.root,val)  
              
    def _add(self, node, val):
        if val < node.value:
            if node.left is None:
                node.left = Node(val)
            else:
                self._add(node.left, val)    
        else:
            if node.right is None:
                node.right = Node(val)
            else:
                self._add(node.right,val)  
                        
    def get_root(self):
        return self.root      

    def print_tree(self):
        if self.root is not None:
            self._print_tree(self.root)
    
    def _print_tree(self, node):
        if node is not None:
            self._print_tree(node.left)
            print str(node.value) + '   '
            self._print_tree(node.right)        
        

if __name__ == '__main__': 
    
    t = Tree()
    t.add(2)
    t.add(1)
    t.add(3)
    t.add(3)
    t.add(4)
    t.add(6)
    
    
    t.print_tree()
