# SIF (Simple Interaction Format) Graph Parser in C

This project is a simple **C program** that reads **SIF-formatted graph data** from the user, stores it in an **adjacency matrix**, and prints the resulting graph in the form of an **adjacency list**.

---

## 📌 What is SIF Format?

**SIF (Simple Interaction Format)** is a common plain-text format used to describe pairwise relationships in biological networks (such as protein interactions, gene regulations, etc.).

A typical SIF line looks like:

Node1 Relation Node2

Example:

A interacts B
B activates C


This program accepts such inputs and automatically builds a graph.

---

## 📌 What This Program Does

1. Takes SIF input from the user:
   - Example: `A interacts B`
2. Stops when the user enters:
END 
3. Creates a graph using an **adjacency matrix (size 100×100)**.
4. Stores node names dynamically (up to 100 nodes).
5. Prints the graph as an **adjacency list** for readability:
A -> B
B -> A C
C -> B


---

## 🧠 How It Works Internally

### ✔ Node Handling  
- Each node name is stored in a `Node` struct.
- Function `getNodeIndex()`:
- Returns existing index if node already exists.
- Otherwise creates a new node and returns new index.

### ✔ Graph Structure  
- `adj[i][j] = 1` means **edge between Node_i and Node_j**.
- Since the graph is **undirected**, both directions are stored:
```c
adj[index1][index2] = 1;
adj[index2][index1] = 1;
```
---


## ✔ Graph Output
The program prints every node, followed by its neighbors.

### Example Input
A interacts B  
B activates C  
END

### Example Output
Graph (Adjacency List):  
A -> B  
B -> A C  
C -> B  

## ⏱ Time & Space Complexity

### Time Complexity
| Operation                  | Complexity | Explanation                                 |
| -------------------------- | ---------- | ------------------------------------------- |
| Searching if a node exists | **O(N)**   | Linear search over existing nodes           |
| Inserting an edge          | **O(1)**   | Direct index assignment in adjacency matrix |
| Printing adjacency list    | **O(N²)**  | Need to scan entire matrix for connections  |

Overall Time Complexity: O(N²)  
Because printing the graph requires scanning the full adjacency matrix.

### Space Complexity 
| Component        | Space                      |
| ---------------- | -------------------------- |
| Node storage     | **O(N)** (array of names)  |
| Adjacency matrix | **O(N²)** (100×100 matrix) |

Total Space Complexity: O(N²)  
Adjacency matrix dominates the memory usage.
