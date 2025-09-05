# 🔍 Binary Search vs Ternary Search in C

This program demonstrates and compares **Binary Search** and **Ternary Search** algorithms in C.  
It takes a sorted array of integers and a search key as input, performs both search techniques, and reports:

- Whether the key is found or not.  
- The index at which the key is found.  
- The number of comparisons made in each search.  

---

## 📌 How the Program Works

1. The user enters:
   - The size of the array `n`
   - The sorted array elements
   - The key to be searched

2. The program runs **Ternary Search**:
   - It divides the search range into **three parts** using two midpoints (`mid1` and `mid2`).
   - Compares the key with both midpoints.
   - Narrows the search space accordingly.
   - Counts the number of comparisons made.

3. The program runs **Binary Search**:
   - It divides the search range into **two parts** using one midpoint (`mid`).
   - Compares the key with the midpoint.
   - Narrows the search space accordingly.
   - Counts the number of comparisons made.

4. Finally, results are displayed:
   - Index where the key is found (if found)
   - Number of comparisons made by each algorithm
   - If not found, a message is displayed.

---

## 📊 Example Run

**Input:**
Enter Size of Array : 8

Enter Array Elements : 2 4 6 8 10 12 14 16

Enter value of key : 12

**Output:**
Key found in Ternary Search At index 5

Number of Comparisons in: 2

Key found in Binary Search At index 5

Number of Comparisons : 3


---

## ⚖️ Comparison Between Binary Search and Ternary Search

- **Binary Search** splits the range into **two halves** at each step.
- **Ternary Search** splits the range into **three parts** at each step.

### Time Complexity
- **Binary Search:** `O(log₂ n)`  
- **Ternary Search:** `O(log₃ n)`

At first glance, `log₃ n` seems smaller than `log₂ n` (so ternary might look faster).  
However, **ternary search does more comparisons per step (up to 2 instead of 1)**, which makes it slower in practice.

### Space Complexity
- Both algorithms run **iteratively** here, so space complexity is `O(1)`.

---

## ✅ Which is Better?

- For **most cases**, **Binary Search** is **better** than Ternary Search:
  - Fewer comparisons in total.
  - Faster execution in real-world scenarios.
  - Simpler implementation.

- **Ternary Search** only becomes useful in **unimodal function optimization problems** (not in array searching).  
  In array search, it introduces unnecessary overhead.

