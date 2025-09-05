# Defective Coin Finder in C

This program finds the **defective coin** from a collection of coins, where all coins are of the same value except **one defective coin** that is lighter (smaller value).  

The algorithm uses a **modified binary search approach** to efficiently locate the defective coin.

---

## 📌 Problem Statement
- You are given `N` coins.  
- `N - 1` coins are **perfect** (equal value).  
- Exactly **1 coin is defective** (lighter value).  
- The task is to find the defective coin with **minimum comparisons**.

---

## ⚙️ How the Program Works
1. The user inputs:
   - The number of coins `N`
   - The values of the `N` coins in an array.

2. The program applies a **binary search-based approach**:
   - Checks if the **first coin** is already lighter than the last (`arr[low] < arr[high]`), then returns it.  
   - Otherwise, calculates `mid = (low + high)/2`.
   - Verifies if the `mid` element is smaller than its neighbors → if yes, that is the defective coin.
   - Otherwise, narrows the search range (`low` is incremented) and repeats.
   - Continues until the defective coin is found.

3. Finally, the defective coin value is printed.

---

## 🔎 Approach Used
- The algorithm is based on the idea of **binary search on a rotated/special array**:
  - Normally, all coins are equal.
  - If there’s one coin smaller than its neighbors, it is the defective coin.
- Instead of **linear scanning (`O(n)`)**, the code tries to reduce the search using **binary search checks**.

---

## ⏱️ Time Complexity (Why it is `O(log n)`)

We use a **binary-search-like** strategy: at each step we compare around a midpoint and **discard half** of the remaining search interval.
### 📊 Recurrence and Solution

Let $T(n)$ be the worst-case number of steps for an input of size $n$.  
Each step does $O(1)$ work (a few comparisons) and reduces the problem to **half** the size:

T(n) = T((n/2)) + O(1)

---

#### 🔹 Unrolling (repeated substitution)

T(n) = T((n/2)) + c  
     = T((n/4)) + 2c  
     = ...  
     = T((n/2^k)) + kc  

Stop when the subproblem size is 1:

(n / 2^k) = 1  ⇒  k = log₂ n  

Thus,

T(n) = T(1) + c log₂ n = O(log n)

---

#### 🔹 Base-change note

The base of the logarithm only changes the constant factor:

logₐ n = (log_b n) / (log_b a)

---

#### 🔹 Inductive view (interval halving)

After each iteration, the interval length halves:

n → n/2 → n/4 → ... → n/2^k  

After k = ⌈log₂ n⌉ iterations, the interval size is ≤ 1, so the search finishes.  
Hence, worst-case comparisons grow as:

Θ(log n)

---

## 🧮 Example Run

**Input:**
Enter number of Elements N: 6

Enter array elements: 10 10 10 5 10 10


**Output:**
Defective coin value: 5

