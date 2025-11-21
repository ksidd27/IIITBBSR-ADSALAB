# Minimum Spanning Tree using Prim's & Kruskal's Algorithms (C Program)

## 📌 Overview

This project implements **Minimum Spanning Tree (MST)** construction in C using:

- **Prim’s Algorithm**
- **Kruskal’s Algorithm**

The program reads graph input in **SIF (Simple Interaction Format)**, stores it in an adjacency matrix, and computes the MST using both algorithms. It then prints the edges selected and the **total cost** of the MST.

---

## 📥 Input Format (SIF Format)

The program accepts input edges in the form: U V W  

Where:  
- `U` and `V` are vertices represented by capital letters (`A`, `B`, `C`, …)  
- `W` is the weight of the edge  

Example:

A B 4  
A C 2  
B C 3  
C D 5  
-1 -1 -1  

Vertices are automatically mapped:  
A → 0  
B → 1  
C → 2  
D → 3  


---

## 📤 Output Format

The program prints:

### ✔ MST using Prim’s Algorithm  
- Each selected edge  
- Total weight of the MST  

### ✔ MST using Kruskal’s Algorithm  
- Each selected edge  
- Total weight of the MST  

---

## 📂 File Description

Contains complete C implementation of:

✔ Reading graph in SIF format  
✔ Storing graph in adjacency matrix  
✔ Prim’s Algorithm  
✔ Kruskal’s Algorithm  
✔ Union-Find functions  

---

## 📘 Algorithms Used

### 🔹 1. Prim’s Algorithm
- Greedy method  
- Builds MST by selecting the minimum-weight edge connected to already chosen vertices  
- Uses an adjacency matrix and selects the minimum edge repeatedly  

---

### 🔹 2. Kruskal’s Algorithm
- Greedy method  
- Works by sorting all edges and picking the smallest edge that doesn’t form a cycle  
- Uses **Union–Find (Disjoint Set Union)** to detect cycles  

---

## ⏳ Time Complexity Analysis

### **Prim’s Algorithm**
Using adjacency matrix:

| Step | Complexity |
|------|------------|
| Finding minimum edge repeatedly | `O(V^2)` |
| Overall Time Complexity | **O(V²)** |
| Space Complexity | **O(V²)** (adjacency matrix) |

---

### **Kruskal’s Algorithm**
| Step | Complexity |
|------|------------|
| Sorting edges | `O(E log E)` |
| Union-Find operations | `O(E α(V))` (≈ constant) |
| Overall Time Complexity | **O(E log E)** |
| Space Complexity | **O(V + E)** |

Where:
- `V` → number of vertices  
- `E` → number of edges  
- `α(V)` → inverse Ackermann function (almost constant)

---

## 📝 Example Output

Edges in MST using Prim’s Algorithm:  
A - C : 2  
C - B : 3  
C - D : 5  
Total cost of MST (Prim’s): 10  

Edges in MST using Kruskal’s Algorithm:  
A - C : 2  
B - C : 3  
C - D : 5  
Total cost of MST (Kruskal’s): 10  


