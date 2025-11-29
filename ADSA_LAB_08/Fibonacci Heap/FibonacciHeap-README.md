# Fibonacci Heap Implementation in C

This repository contains an implementation of a **Fibonacci Heap** in the C programming language.  
A Fibonacci Heap is a sophisticated data structure used to efficiently support a **priority queue**, especially when a large number of **decrease-key** operations are required.  

It is widely used in advanced algorithms such as:

- **Dijkstra’s Shortest Path Algorithm**
- **Prim’s Minimum Spanning Tree**
- Network optimization problems  
- Any scenario where fast amortized time complexity is needed

---

## 🚀 Features Implemented

This implementation supports the following Fibonacci Heap operations:

### ✔ Insert  
Adds a new key into the heap.

### ✔ Find Minimum  
Returns the smallest key in the heap.

### ✔ Extract Minimum  
Removes and returns the minimum key. This involves **consolidation** of trees.

### ✔ Decrease Key  
Decreases the value of a node's key and performs **cut** and **cascading cuts** if required.

### ✔ Delete Node  
Deletes a key by reducing it to −∞ and performing Extract-Min.

### ✔ Display  
Displays all elements in the **root list**.

### ✔ Search (Recursive)  
Searches for a key inside the heap.

---

## 📁 File Description

- `main()` contains an interactive menu-driven interface.
- `insert()` handles adding elements to the root list.
- `extractMin()` removes the minimum node and consolidates the heap.
- `consolidate()` merges trees of the same degree into a min-heap-ordered structure.
- `decreaseKey()` triggers cuts and cascading cuts if heap order is violated.
- `deleteNode()` deletes a node using decreaseKey and extractMin.
- `search()` recursively looks through root and child lists.

---

## 📘 How Fibonacci Heap Works (Short Overview)

A Fibonacci Heap is a collection of **min-heap-ordered trees**, where:

- Each node may have multiple children.
- Trees are linked together through circular doubly linked lists.
- The **minimum node is always accessible in O(1)**.
- Trees are lazily merged — actual restructuring happens during `extractMin()` using **consolidation**.

Its power comes from **amortized** complexity:  
Instead of restructuring every time, the heap delays work and performs it only when needed.

---

## 🧮 Time Complexity

| Operation          | Amortized Time Complexity | Worst Case |
|--------------------|---------------------------|-------------|
| **Insert**         | Θ(1)                      | Θ(1)        |
| **Find-Min**       | Θ(1)                      | Θ(1)        |
| **Union**          | Θ(1)                      | Θ(1)        |
| **Extract-Min**    | Θ(log n)                  | Θ(n)        |
| **Decrease-Key**   | Θ(1)                      | Θ(n)        |
| **Delete Node**    | Θ(log n)                  | Θ(n)        |
| **Search**         | O(n)                      | O(n)        |

---

## 💾 Space Complexity

### **Space Complexity: Θ(n)**

Where **n = number of nodes in the heap**.  
Each node stores:

- key  
- degree  
- mark  
- parent pointer  
- child pointer  
- left & right sibling pointers  

Thus, space usage is linear in the number of heap elements.

---
===== Fibonacci Heap Menu =====

1. Insert

2. Find Min

3. Extract Min

4. Decrease Key

5. Delete Key

6. Display Root List

7. Exit
