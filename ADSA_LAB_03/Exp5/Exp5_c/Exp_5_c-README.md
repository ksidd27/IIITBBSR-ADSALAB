# Floyd–Warshall Algorithm in C (All-Pairs Shortest Path)

This project implements the **Floyd–Warshall Algorithm** in C to compute the **shortest paths between all pairs of vertices** in a weighted graph.

The program accepts an **adjacency matrix** where:
- `0` represents the distance from a node to itself  
- A positive weight represents an edge  
- `99999` (INF) represents **no direct edge**

The algorithm then calculates the **minimum distance between every pair of vertices** using dynamic programming.

---

## 📘 What This Program Does

1. Takes:
   - Number of vertices `n`
   - An `n × n` adjacency matrix

2. Initializes a `dist[][]` matrix with given graph weights.

3. Runs the **Floyd–Warshall algorithm**:
   - For every intermediate node `k`
   - Update shortest distance between all pairs `(i, j)`
   - If `i → k → j` is shorter than direct `i → j`, update the value.

4. Prints the final **All-Pairs Shortest Path (APSP)** matrix.

---

## 🧠 How the Algorithm Works

Floyd–Warshall uses a triple nested loop:

for each vertex k:  
for each vertex i:  
for each vertex j:  
if dist[i][k] + dist[k][j] < dist[i][j]:  
dist[i][j] = dist[i][k] + dist[k][j]    


It systematically attempts to improve the shortest path between every pair `(i, j)` using `k` as an intermediate point.

---

## 📌 Example Input

Enter the number of vertices: 4  
Enter the adjacency matrix (use 99999 for INF):  
0 3 99999 7  
8 0 2 99999  
5 99999 0 1  
2 99999 99999 0    

---

## 📌 Example Output

All-Pairs Shortest Path Matrix:  
0 3 5 6  
5 0 2 3  
3 6 0 1  
2 5 7 0  


---

## ⏱ Time & Space Complexity

### **Time Complexity**

Floyd–Warshall uses three nested loops:

for k = 1 to n:  
for i = 1 to n:  
for j = 1 to n:    


Thus the time complexity is: O(n³)  


✔ Suitable for small to medium-sized graphs  
✘ Not efficient for very large graphs  

---

### **Space Complexity**

The algorithm stores one `n × n` matrix (`dist`):

Space Complexity is: O(n²)  

No extra heavy memory structures are used.
