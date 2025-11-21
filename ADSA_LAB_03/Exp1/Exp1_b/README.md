# Sorting Algorithms in C (Quick Sort, Merge Sort, Heap Sort)

## 📌 Overview
This project implements **three major sorting algorithms** in C:

1. **Quick Sort**
2. **Merge Sort**
3. **Heap Sort**

The user enters an array and selects one of the sorting algorithms.  
The program then sorts the array using the selected method and prints the sorted result.

---

## 🚀 How the Program Works

### ✔ User Input
- Number of elements (`n`)
- Input array of integers
- Menu to choose a sorting algorithm:
  - `1 → Quick Sort`
  - `2 → Merge Sort`
  - `3 → Heap Sort`

### ✔ Output
- Sorted array printed on the screen

---

## 🔍 Algorithms Implemented

### 1️⃣ Quick Sort
- Uses the **divide-and-conquer** approach
- Pivot selected as the last element
- Recursively partitions array into subarrays

#### Time Complexity
| Case | Complexity | Description |
|------|------------|-------------|
| **Best Case** | **O(n log n)** | Balanced partitions |
| **Average Case** | **O(n log n)** | Expected performance |
| **Worst Case** | **O(n²)** | Occurs when array is already sorted or reverse sorted with poor pivot |

---

### 2️⃣ Merge Sort
- Stable sorting algorithm
- Uses recursive divide-and-conquer
- Merges sorted halves

#### Time Complexity
| Case | Complexity | Description |
|------|------------|-------------|
| **Best Case** | **O(n log n)** | Always divides into halves |
| **Average Case** | **O(n log n)** | Consistent behavior |
| **Worst Case** | **O(n log n)** | Never degrades |

#### Space Complexity
- **O(n)** → requires extra arrays for merging

---

### 3️⃣ Heap Sort
- Uses a **binary heap** structure
- Builds max heap and repeatedly extracts max

#### Time Complexity
| Case | Complexity | Description |
|------|------------|-------------|
| **Best Case** | **O(n log n)** | Heap operations |
| **Average Case** | **O(n log n)** | No performance degradation |
| **Worst Case** | **O(n log n)** | Always same performance |

#### Space Complexity
- **O(1)** → in-place sorting

---

## 📂 File Included
- `sorting.c` — Source code with all three algorithms  
- `README.md` — Program explanation (this file)

---

## 📌 Features
- Implements 3 major sorting techniques
- Menu-driven program
- Beginner-friendly and easy to understand
- Works for any integer array

---

## 🧪 Example Usage
Input:
Enter number of elements: 5

Enter integers: 4 1 7 2 9

Choose method: 2


Output: Sorted array: 1 2 4 7 9
