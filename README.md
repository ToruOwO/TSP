# TSP

1)Brute Force (For N up tp 16)
Gives exact solution but takes a long time.

2)Nearest-Neighbour (For the rest)
Greedy algorithm.
Took a long time and apparently doesn't give an optimal value..

3)Bitmasking + DP
Reference:
https://en.wikipedia.org/wiki/Held%E2%80%93Karp_algorithm
Still in progress..

Some thoughts on other possible solutions:

4)Use TSP solvers like Google Map API
Theoretically(?) gives the optimal solutions

5)2-Opt Algorithm & Greedy 2-Opt Algorithm
https://en.wikipedia.org/wiki/2-opt

6)Approximation using Minimal Spanning Tree (Mainly for speed)
i. 
Find a minimal spanning tree T of the graph using any efficient algorithm;
the cost of T <= cost of optimal solution, since 1 edge is missing.
ii.
DFS the tree T; 
every city is visited at least twice so the DFS walk (say D) has at most twice the cost of optimal solution.
iii.
To visit every city exactly once, find shortcuts between cities to reduce number of edges in D;
by triangular inequality, the end result costs at most twice as the optimal result
