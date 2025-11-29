# 🌳 Splay Tree Implementation in C

This repository contains an implementation of a **Splay Tree**, a self-adjusting binary search tree that performs operations such as insertion, search, and deletion while **splaying** (rotating) the accessed node to the root.

Splay Trees guarantee good amortized performance and are widely used in memory allocators, caches, and dynamic sets.

---

## 📌 What is a Splay Tree?

A **Splay Tree** is a type of Binary Search Tree (BST) where every operation (insert, search, delete) is followed by a **splay operation**, which moves the accessed node to the **root** using tree rotations.

This improves access time for frequently used keys.

### ✔ Key Characteristics
- **Self-adjusting** (no need to maintain strict balancing)
- **Fast amortized performance**
- Frequently accessed elements move closer to the root
- No extra balance factors required (unlike AVL / Red-Black trees)

---

## 📁 Features Implemented

### ✅ Insertion  
Inserts the key, then splays the inserted node to the root.

### ✅ Search  
Finds the key and splays it to the root.  
If not found, the last accessed node is splayed.

### ✅ Deletion  
Splays the key to the root, then removes it and reconnects subtrees.

### ✅ Inorder Traversal  
Shows the sorted order of keys.

### ✅ Splay Operation  
Handles Zig, Zig-Zig, and Zig-Zag rotations.

---

## 🧠 How Splaying Works

The splay operation moves a node to the root using rotations:

- **Zig** → Single rotation (when node is child of root)  
- **Zig-Zig** → Double rotation in the same direction  
- **Zig-Zag** → Double rotation in opposite directions  

This reduces the height of frequently accessed nodes over time.

---

## 🧮 Time & Space Complexity

### ⏱ Time Complexity

| Operation | Amortized Time | Worst Case |
|----------|----------------|------------|
| **Search** | **O(log n)** | O(n) |
| **Insert** | **O(log n)** | O(n) |
| **Delete** | **O(log n)** | O(n) |
| **Splay Operation** | **O(log n)** (amortized) | O(n) |

### Why amortized O(log n)?  
Because although individual operations may degrade to O(n),  
the **aggregate performance** over many operations stays O(log n).

---

## 💾 Space Complexity

| Component | Space |
|----------|--------|
| Node structure | O(1) per node |
| Entire tree | **O(n)** |

---

## 📌 Example Menu Output
--- Splay Tree Menu ---
1. Insert
2. Search
3. Delete
4. Inorder Traversal
5. Exit

