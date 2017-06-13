#/usr/bin/python

'''
    Recursive and iterative solution to finding identical trees.
'''
class Node:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

def print_tree(root):
    if not root:
        return

    print_tree(root.left)
    print root.val
    print_tree(root.right)


def is_identical_recursive(tree1, tree2):
    if tree1 is None and tree2 is None:
        return True
    if tree1 is None or tree2 is None:
        return False
    else:
        if tree1.val == tree2.val:
            return(is_identical_recursive(tree1.left,tree2.left) and is_identical_recursive(tree1.right, tree2.right))
        else:
            return False



def is_identical_iterative(tree1, tree2):
    s1 = []
    s2 = []
    curr1 = tree1
    curr2 = tree2
    if not curr1 and not curr2:
        return True
    if not curr1 or not curr2:
        return False

    while ( (s1 and s2) or (curr1 is not None or curr2 is not None)):
        if curr1 is not None and curr2 is not None:
            s1.append(curr1)
            s2.append(curr2)
            curr1 = curr1.left
            curr2 = curr2.left
        else:
            if s1:
                curr1 = s1.pop()
            if s2:
                curr2 = s2.pop()
            if curr1 is None or curr2 is None:
                return False

            if curr1.val != curr2.val:
                return False
            else:
                curr1 = curr1.right
                curr2 = curr2.right
    return True



if __name__ == '__main__':
    root = Node(5)
    root.left = Node(3)
    root.right = Node(6)

    root.left.left = Node(2)
    root.left.right = Node(4)

    root.right.right = Node(7)

    print " Tree "
    print_tree(root)

    beet = Node(5)
    beet.left = Node(3)
    beet.right = Node(6)

    beet.left.left = Node(2)
    beet.left.right = Node(4)

    print " Tree "
    print_tree(beet)


    print is_identical_recursive(beet,root)
    print is_identical_iterative(beet,root)
