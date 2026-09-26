# DSA Assignment 2

## Graph Representation, BFS, DFS and Search

### Given Social Network

The given social network has the following connections:

- A-B

- A-C

- B-D

- B-E

- C-F

- E-F

The vertices are:

A, B, C, D, E, F

---

## 1. Adjacency Matrix

The graph is represented using an adjacency matrix.

|   | A | B | C | D | E | F |
|---|---|---|---|---|---|---|
| A | 0 | 1 | 1 | 0 | 0 | 0 |
| B | 1 | 0 | 0 | 1 | 1 | 0 |
| C | 1 | 0 | 0 | 0 | 0 | 1 |
| D | 0 | 1 | 0 | 0 | 0 | 0 |
| E | 0 | 1 | 0 | 0 | 0 | 1 |
| F | 0 | 0 | 1 | 0 | 1 | 0 |

---

## 2. Adjacency List

The graph is represented using an adjacency list.

A -> B C

B -> A D E

C -> A F

D -> B

E -> B F

F -> C E

3.BFS Starting from A

Breadth First Search (BFS) is performed starting from vertex A.

BFS using Adjacency Matrix
A B C D E F
BFS using Adjacency List
A B C D E F

4.DFS Starting from A
Depth First Search (DFS) is performed starting from vertex A.
DFS using Adjacency Matrix
A B D E F C
DFS using Adjacency List
A B D E F C

5.Search Operation

A search operation is performed to locate vertex F.

Search using Adjacency Matrix

Vertex F is found.

Search using Adjacency List

Vertex F is found.

The program also records the checks performed during the search.

7.Analysis

Space Requirements

An adjacency matrix requires O(V²) space because it stores information for every possible pair of vertices.

An adjacency list requires O(V + E) space because it stores the vertices and only the existing edges.

Traversal Behaviour

In an adjacency matrix, BFS and DFS scan the complete row to find adjacent vertices.

In an adjacency list, BFS and DFS directly visit the stored neighbouring vertices.

Search and Edge Checking

In an adjacency matrix, checking whether an edge exists between two vertices takes O(1) time.

In an adjacency list, checking for a particular edge requires searching through the adjacency list of the vertex.

Time Complexity

For BFS and DFS, an adjacency matrix takes O(V²) time.

For BFS and DFS, an adjacency list takes O(V + E) time.

⸻

8. Conclusion

The given social network is relatively sparse because only a small number of possible vertex pairs have connections.

For a sparse social network, an adjacency list requires less space because it stores only the existing edges. It also allows graph traversal to follow the actual neighbouring vertices.

Therefore, the adjacency list representation is suitable for representing a sparse social network.
