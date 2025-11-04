# Maximum Bipartite Matching

This project implements **Maximum Bipartite Matching** in C using **Depth-First Search (DFS)**.

---

## 🎯 Objective
Given a bipartite graph with two sets of nodes **U** and **V**, this program finds the **maximum matching** such that:

- Each U node matches with at most one V node  
- Each V node matches with at most one U node  
- Matching only happens if an edge exists between them (input matrix)

---

## 🧠 Algorithm
This program uses **DFS-based augmenting paths**:

- Try to match each node in U
- If a V node is already matched, try to re-assign that match
- If reassignment works, match U to that V
- Result = maximum possible matching

Complexity: **O(V × E)**

---

## 📥 Input Format
<U size> <V size>
<Adjacency Matrix U × V>


---

## ✅ Example Input
3 3

1 1 0

0 1 1

1 0 1


Meaning:

| U → V | V0 | V1 | V2 |
|------|----|----|----|
| U0   | 1  | 1  | 0  |
| U1   | 0  | 1  | 1  |
| U2   | 1  | 0  | 1  |

Edges:

U0 → V0, V1

U1 → V1, V2

U2 → V0, V2

---

## 📤 Output
Enter number of nodes in U and V: 3 3

Enter adjacency matrix (U x V):

1 1 0

0 1 1

1 0 1

Maximum Bipartite Matching = 3

Matched pairs (U -> V):

U2 -> V0

U0 -> V1

U1 -> V2


---

## 🧩 Explanation

Maximum matches possible = **3**

Final matching:

U0 → V1

U1 → V2

U2 → V0

All U nodes matched → **maximum matching achieved**
