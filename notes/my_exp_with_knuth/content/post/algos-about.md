---
title: "How to think about algorithms?"
date: 2017-07-23T20:50:41-07:00
---

Categories : - Category of problem it solves 
--------------------------------------------

1. Search and Sorting -- Search for a key in a collection of keys. Sort a list of values to find
max or min.

2. Pattern matching -- Given an input string and a pattern, try to deduce different things about
the pattern. Is it present? Shortest substring etc..

3. Bit algorithms -- Various bit manipulation related questions

4. Mathematical algorithms -- Solves some mathematical problems, e.g. multiplication of numbers,
    pascal's triangle, fibonacci etc. 

5. Geometric algorithms -- solves some geometric problem, given a set of points, find closest set
    of points etc.

6. Graph algorithms -- pertaining to graph traversal etc.

7. Randomized algorithms -- 



Paradigms: - How the algorithm goes about solving a problem
-----------------------------------------------------------

1. Greedy algorithms -- Solves a problem piece by piece, each time choosing the best possible next
    step. Used in optimization problems
     e.g. kruskal's minimum spanning tree -- find a minimum spanning tree.
          prim's algorithm


2. Dynamic programming -- Divides a problem into sub problems and solves them, each time
remembering the solution to sub problems so as to not recompute. Typical problems that can be
solved by DP:
    1. optimal substructure : - optimal solution can be arrived by combining the optimal solution
        of each subproblem

    2. Overlapping subproblems : - E.g. fibonacci number, the same sub problem will need to be
    solved multiple times, instead we could remember the solution to previous computations
    and look it up in the next iteration.


3. Divide & Conquer -- similar to DP, it also divides the problem into sub problems, but the sub
problems don't overlap. 
    divide -- divide in to subproblems
    conquer -- compute results to each sub problem
    combine -- combine results of each sub problem
    e.g. binary search, quick sort, merge sort etc.


4. Backtracking -- Try a particular solution, if it doesn't work try another until you find a
solution that works.  
For e.g: in a knight's tour problem, a knight can make 8 possible moves, we try a move and see if
it takes us to a solution where all 8 x 8 blocks in a chess board are traversed. If not, we go back
and try another move.

How are we better than a naive solution?

5. Branch and Bound --
    Don't know what it is as of yet. But it is used in cases where we have to maximize value and
    minize cost. Knapsack problem.

    scheduling jobs, landing airplanes in a runway etc..


