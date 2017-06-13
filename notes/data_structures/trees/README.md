Binary Trees:-
-------------

A form a graph where each node could have a left child, a right child, or either one, or none.

Several forms of binary tree problems can be solved by employing one of the traversal techniques:

1. In order Traversal:
---------------------
    visit left child
    visit current
    visit right child

2. Pre order traversal:
----------------------
    visit root
    visit left child
    visit right child

3. Post order traversal:
------------------------
    visit left child
    visit right child
    visit root

4. Level order (BFS) traversal:
------------------------------
    visit node at each level (use queue) before proceeding to the next level nodes.

5. DFS (depth first search):
----------------------------
    visit deepest leaf and proceed upwards (use stack)

The following table categorises problems based on one of the above techniques that can be used to
solve them.

-----------------------------------------------------------------------------------------------------------
In-order                    Pre-order                   Post-order                  BFS                 DFS
------------------------------------------------------------------------------------------------------------
convert Tree to BST         Mirror a binary tree        Max sum from root,leaf     
............................................................................................................
                            Print all path from root    delete a tree
............................................................................................................
                            Symmetric trees             height balanced
............................................................................................................
                            Lowest common ancestor
............................................................................................................

