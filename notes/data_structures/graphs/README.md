Notes on Graphs:-
---------------

----------------
What is a graph?
----------------

A graph G is a set of vertices V and edges E.

G = {V, E}

V = All nodes in the graph. For e.g. cities in a map, people in facebook, electronic components in
    a circuit board.

E = An edge connects two vertices. They can be directed or undirected.
    Weighted or Unweighted. For e.g. all roads on a map, all connecting wires in a circuit board.


----------------    
Types of graphs:
----------------

-------------------------
1. DIRECTED vs UNDIRECTED: 
-------------------------

If an edge (x,y) belonging to edge set E, also implies (y,x) exists in the set E. Then it is undirected. 
E.g.Meaning a 2 way street between two cities or you get to point A from B or B from A. 

Directed graph has the opposite meaning. (x,y) in E doesn't imply (y,x) in E.
E.g. Map of NYC, most likely some one way streets exist in the map somewhere.

-------------------------
2. WEIGHTED vs UNWEIGHTED:
-------------------------

If an edge e = (x,y) in E has some weight or cost associated with it, then it is weighted. 
E.g. The distance between 2 places in a map becomes the cost of using one path over another.
Travelling salesman problem.

If an edge e = (x, y) in E doesn't have any weight associated with it, then it is unweighted.

Difference becomes most apparent when trying to find the shortest path. 
    In unweighted graphs, you'll use BFS to find least number of edges between two nodes:
    In weighted graphs, it'll most likely come down to a heuristic based approach. Much more
    complicated.

-------------------------
3. SIMPLE  vs UN SIMPLE:
-------------------------

The absence of loops, multiple edges between vertices, makes the graph a simple graph.

-------------------------
4. CYCLIC vs ACYCLIC:
-----------------------

Acyclic graphs don't contain cycles. The definition itself seems cyclic. So, to understand it
better: Acyclic graphs don't have multiple paths between vertices. A Tree is a good example.

Cyclic graphs have cycles, meaning there can be multiple paths that one can take between two
vertices.

What's a loop then? Loop is an edge that has start and end as the same node or vertex. A loop
then means, an edge e = (x,x). This is the important distinction between cyclic graphs and
unsimple graphs.

    
There are some more graphs that I'm not interested in right now.
