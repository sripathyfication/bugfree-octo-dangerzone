#/usr/bin/python
#
# Notes:
#   if both trees are null, then true
#   if one tree is Null, return False
#   else, recurse over left tree and right tree checking the same
#
from bst import Tree
       
def _is_identical(n1,n2):
    if n1 is None and n2 is None:
        return True
    else:
        if (n1.value == n2.value):
            return(_is_identical(n1.left,n2.left), _is_identical(n1.right,n2.right))
        else:
            return False

def is_identical(t1, t2):
    if t1 is None and t2 is None:
        return True
    else:
        if t1 is None or t2 is None:
            return False
        else:
            if (t1.get_root().value == t2.get_root().value):
                return (_is_identical(t1.get_root().left,t2.get_root().left) and
                        _is_identical(t1.get_root().right,
                        t2.get_root().right))
    
if __name__ == '__main__': 

    t1 = Tree()
    t2 = Tree()

    t1.add(2)
    t1.add(1)
    t1.add(3)

    t2.add(2)
    t2.add(1)
    t2.add(3)

    print is_identical(t1,None)
