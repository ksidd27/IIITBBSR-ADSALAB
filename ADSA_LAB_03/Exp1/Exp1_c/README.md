# Quick Sort Using Median-of-Three Pivot (C Program)

This project implements the **Quick Sort algorithm** in C using the **Median-of-Three** technique for pivot selection.  
It also uses **Insertion Sort** as a cutoff for very small subarrays to improve efficiency.

---

## 🚀 Features

- **Median-of-Three Pivot Selection**
  - Reduces the likelihood of worst-case behavior.
  - Gives better pivot approximation than choosing the first or last element.
  
- **Hybrid Sorting**
  - Quick Sort for large subarrays.
  - Insertion Sort for small subarrays (`size < 10`), improving performance.

- **Efficient Partitioning**
  - Partitions arrays around the chosen pivot.
  
- **User Input**
  - User enters the number of elements and the actual list to sort.

---

## 📌 How Median-of-Three Works

Before partitioning, three elements are considered:

- The **first** element (`arr[low]`)
- The **middle** element (`arr[(low+high)/2]`)
- The **last** element (`arr[high]`)

These three values are sorted, and the **median** is used as the pivot.  
This:
- Avoids poor pivot choices
- Reduces recursion depth
- Improves overall Quick Sort performance

---

## 📈 Time Complexity

| Case          | Complexity |
|---------------|------------|
| **Best Case** | `O(n log n)` |
| **Average Case** | `O(n log n)` |
| **Worst Case** | `O(n²)` *(much less likely because of median-of-three)* |

### Space Complexity  
`O(log n)` — due to recursive call stack.

---

## 🧠 Why Use Insertion Sort for Small Arrays?

Insertion Sort performs better than Quick Sort for tiny subarrays because:
- Lower overhead
- Fewer comparisons
- Faster on nearly sorted data

This hybrid approach is used in many real-world libraries.

---
Output Example

Enter number of elements: 6

Enter 6 integers: 9 4 7 3 1 5

Sorted array: 1 3 4 5 7 9

