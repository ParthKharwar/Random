Minimum Spanning Tree (MST)
It is a subset of the edges of a connected, edge-weighted undirected graph 
It connects all the vertices together, without any cycles and with the minimum possible total edge weight.
It has V-1 edges where V are the number of vertices

Kruskals Algorithm
It is a Greedy Algorithm
Steps:
1. Sort all the edges in non-decreasing order of their weight.
2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
3. Repeat step #2 until there are (V-1) edges in the spanning tree.

Prims Algorithm
It is also a Greedy Algorithm
Steps:
1. Create empty spanning tree
2. Create two sets of vertices. One containing the vertices already included in the MST, the other with the vertices not yet included. 
3. Consider all the edges that connect the two sets, and picks the minimum weight edge from these edges. 
4. After picking the edge, move the other endpoint of the edge to the set containing MST.
5. Repeat steps #3 and #4 till all vertices are included
