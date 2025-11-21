# B-Tree Implementation in C (Insert, Delete, Search, Traverse)

This repository contains a complete C program that implements a **B-Tree** data structure with the following operations:

- **Insertion**
- **Deletion**
- **Search**
- **Traversal (Display)**
- Handles node splitting, merging, borrowing, and rebalancing

The B-Tree implemented uses **minimum degree T = 3**, meaning:
- Each node can have **2T − 1 = 5 keys max**
- Each node must have **T − 1 = 2 keys min** (except root)
- Each internal node can have up to **6 children**

---

## 📌 What is a B-Tree?

A **B-Tree** is a self-balancing search tree designed for systems that read/write large blocks of data (like databases and filesystems).

### Key Properties:
- All keys are stored **in sorted order**
- All leaves appear at the **same level**
- A node can contain **multiple keys**
- Searching, inserting, and deleting keys is efficient
- Prevents deep trees → great for disk-based storage

Common real-world uses:
- **Database Indexing (MySQL, PostgreSQL)**
- **Filesystem Directory Trees**
- **Large Key-Value Stores**

---

## 📌 Program Features

### ✔ Insert Operation
Automatically handles:
- Splitting full nodes
- Promoting median keys
- Maintaining tree balance

### ✔ Delete Operation
Handles all deletion cases:
- Deleting from leaf
- Deleting from internal node
- Using predecessor/successor replacement
- Borrowing keys from siblings
- Merging nodes when required

### ✔ Search Operation
Performs key lookup similar to binary search but across multiple keys.

### ✔ Display (Traversal)
Uses **in-order traversal** to print all keys in sorted order.

The B-Tree uses **minimum degree T = 3**, meaning:
- Maximum keys per node = `2T − 1 = 5`
- Minimum keys per node = `T − 1 = 2`
- Maximum children per node = `2T = 6`

---

## 📌 Time Complexity

| Operation | Complexity | Explanation |
|----------|-------------|-------------|
| **Search** | `O(log n)` | Tree height is logarithmic because node branching factor is large |
| **Insert** | `O(log n)` | Only splits on the path; tree stays balanced |
| **Delete** | `O(log n)` | Handles merge/borrow but remains logarithmic |
| **Traversal** | `O(n)` | Visits all keys |
| **Split/Merge** | `O(1)` | Each affects only one node |

### 🔍 Why `O(log n)`?

A B-Tree node can hold many keys → height becomes very small:

Height ≈ logₜ(n)

This reduces disk access and speeds up operations.

---

## 📌 Space Complexity

| Complexity Type | Value | Explanation |
|----------------|--------|-------------|
| **Space Complexity (overall)** | `O(n)` | Stores all keys and pointers |
| **Space per Node** | `O(T)` | Holds up to `2T-1` keys and `2T` child pointers |
| **Auxiliary Space** | `O(1)` | Only uses constant extra memory for recursion/loops |
| **Worst-case Tree Height** | `O(log n)` | But height does not increase memory usage significantly |

Thus, the total memory grows linearly with the number of keys inserted.

---

The menu provides 5 options:
1. Insert
2. Delete
3. Display
4. Search
5. Exit

---
