-----------------
Notes on Graphs:-
-----------------

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

    
---------------------------
Types of Graph Problems:-
---------------------------

1. Searching through a graph.
   a. Breadth First Search
   b. Depth First Search

2. Minimum spanning tree of a graph 
    Least weight way of connecting vertices of a graph, given that each edge has a weight
    associated with it.

3. Maximum network flow.
    Given a source vertex and sink vertex, and the amount of material that can traverse through an
    edge, find the maximum flow a network can handle.

4. shortest path
    Given there is a weight associated with an edge, find the shortest path between 2 vertices.


------------------------
Graph Representations:-
------------------------

A graph can be represented in 2 ways in memory:
    1. Adjacency list.
    2. Adjacency Matrix.

    Given a directed graph :

        (1)  ---> (2) ---> (5) 
         |                  ^ 
         |                  | 
         v                  |
        (3) ---> (4) -------+ 

1. Adjacency List:

        Adjacency List will look like this:

            [1] --> [2] --> [3] --.
            [2] --> [5] --.
            [3] --> [4] --.
            [4] --> [5] --.
            [5] --.

        It is an array of vertices indexed by its destination # or vertex id.
        At each array entry is a singly linked list pointing to a vertex than can be reached
        directly from current vertex. Its adjacency.    

        Its representation doesn't change whether the graph is directed or undirected.

        Pros:
            Occupies less space than adjancency matrix

        Cons:
            Searching for a vertex can take time.

        Typically you'd use this when the graph is sparse. i.e. |E| << |V2|. # of edges is
        significantly smaller than the number of vertices.

2. Adjaceny Matrix:

        Adjacency Matrix would look like this:

            1   2   3   4   5
        -----------------------  
        1   0   1   1   0   0
        -----------------------  
        2   0   0   0   0   1
        -----------------------  
        3   0   0   0   1   0
        -----------------------  
        4   0   0   0   0   1
        -----------------------  
        5   0   0   0   0   0   
        -----------------------  

        It is |v| x |v| matrix. If there is an edge (u,v) then Adj[u][v] = 1
        We can also represent weighted graphs this way by saving the weight/length at index
        adj[u][v] instead of 1.

        In case of an undirected graph the adjacency matrix is perfectly symmetrical. So, if
        the graph above was undirected the adjacency matrix would look like this:

            1   2   3   4   5
        -----------------------  
        1   0   1   1   0   0
        -----------------------  
        2   1   0   0   0   1
        -----------------------  
        3   1   0   0   1   0
        -----------------------  
        4   0   0   1   0   1
        -----------------------  
        5   0   1   0   1   0   
        -----------------------  

        So in this case Adj[] = Transpose(Adj[]) which means that we can save just the upper
        diagonal matrix in memory to save space.

-------------------------------------
Elementary Algorithms:-
-------------------------------------

1. Breadth First Search (BFS):-
--------------------------------




2. Depth First Search (DFS):-
--------------------------------


3. Topological Sorting:-
----------------------

4. Strongly connected components:-
----------------------------------

