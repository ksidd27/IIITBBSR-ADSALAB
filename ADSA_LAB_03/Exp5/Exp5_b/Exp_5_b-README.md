# Dijkstra’s Algorithm in C (Shortest Path Finder)

This project implements **Dijkstra’s Algorithm** in C using an **adjacency matrix** to find the shortest path from a single source vertex to all other vertices in a weighted graph.

The program also prints:
- The **shortest distance** from the source to each vertex  
- The **actual path** taken (using a parent array)

---

## 📘 What This Program Does

1. Accepts:
   - Number of vertices `n`
   - An `n × n` adjacency matrix  
   - A source vertex `src`

2. Runs **Dijkstra's algorithm** to compute shortest distances.

3. Prints:
Vertex X: Distance = Y, Path = src -> ... -> X

4. Uses:
- `minDistance()` to choose the next closest vertex
- `parent[]` array to reconstruct paths
- Simple adjacency matrix (0 = no edge)

---

## 🧠 How Dijkstra’s Algorithm Works in This Code

### ✔ Initialization
- `dist[]` array stores minimum distances  
- `sptSet[]` marks finalized vertices  
- `parent[]` helps rebuild shortest paths  

### ✔ Main Algorithm Loop
For `n − 1` iterations:
- Pick the vertex **u** with minimum distance (not yet processed)
- Update distances for all adjacent vertices **v**
- Update parent of **v** when a shorter path is found

### ✔ Path Printing
Uses recursion:
```c
printPath(parent, v);
```
This prints the full path from source to any vertex.

### Example Input
Enter number of vertices: 5  
Enter the adjacency matrix:  
0 10 0 5 0  
0 0 1 2 0  
0 0 0 0 4  
0 3 9 0 2  
7 0 6 0 0  
Enter the source vertex: 0  

### Example Output (Simplified View)  
Shortest distances and paths from source vertex 0:  
Vertex 0: Distance = 0, Path = 0  
Vertex 1: Distance = 8, Path = 0 -> 3 -> 1  
Vertex 2: Distance = 9, Path = 0 -> 3 -> 1 -> 2  
Vertex 3: Distance = 5, Path = 0 -> 3  
Vertex 4: Distance = 7, Path = 0 -> 3 -> 4  

---
## Time & Space Complexity

### Time Complexity
Breakdown:  
| Operation                   | Complexity      |
| --------------------------- | --------------- |
| Finding min-distance vertex | O(V)            |
| Doing this for all vertices | O(V²)           |
| Relaxation of edges         | O(V) per vertex |

Dijkstra with adjacency matrix takes: O(V^2)  


### Space Complexity  
Breakdown:  
| Component        | Space |
| ---------------- | ----- |
| dist[]           | O(V)  |
| sptSet[]         | O(V)  |
| parent[]         | O(V)  |
| adjacency matrix | O(V²) |

Total space complexity: O(V²)  
Adjacency matrix dominates space usage.
