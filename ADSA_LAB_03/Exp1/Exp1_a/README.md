# Binary Search in C (Recursive & Iterative)

## 📌 Overview
This project implements **Binary Search** in C using two methods:

1. **Recursive Binary Search**
2. **Iterative (Non-Recursive) Binary Search**

Binary Search is an efficient algorithm for finding the position of a target value within a **sorted array**.

---

## 🚀 How the Program Works

### ✔ Input
- Number of elements  
- Sorted array elements  
- Key to be searched  
- Choice between:
  - `1` → Recursive Binary Search  
  - `2` → Iterative Binary Search  

### ✔ Output
- Index of the key if found (0-based index)  
- Message `"Key not found"` if the element is absent  

---

## 📘 Important Note
Binary Search **requires the array to be sorted**.  
If the array is not sorted, the algorithm will not work correctly.

---

## ⏱ Time Complexity

| Case | Complexity | Description |
|------|------------|-------------|
| **Best Case** | **O(1)** | Key found at middle immediately |
| **Average Case** | **O(log n)** | Problem size is halved each iteration |
| **Worst Case** | **O(log n)** | Key found late or not present |

Binary Search is fast because it eliminates half the search space at each step.

---

## 🧠 Space Complexity

| Method | Space Complexity | Reason |
|--------|------------------|--------|
| **Recursive** | **O(log n)** | Uses recursion stack |
| **Iterative** | **O(1)** | No extra memory required |

---

## 📂 File Included
- `binary_search.c` — Source code containing both implementations  
- `README.md` — Documentation (this file)

---

## 📌 Features
- Simple and beginner-friendly  
- Supports both recursive and iterative binary search  
- Clean and readable C code  
- Easy to test and use  

---

## 🧪 Example Usage
Input:
Enter the number of elements: 5

Enter elements: 1 3 5 7 9

Enter key to search: 7

Choose method: 1

Output:
Key 7 found at position 3
