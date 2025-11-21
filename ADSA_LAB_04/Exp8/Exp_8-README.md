# Longest Common Subsequence & All Common Subsequences in C

## 📌 Overview

This project implements:

1. **Longest Common Subsequence (LCS)** — using Dynamic Programming  
2. **Printing one actual LCS** — using backtracking  
3. **Printing all common subsequences** — using recursion  

The program takes two input strings and computes:

✔ LCS length  
✔ One valid LCS  
✔ All possible common subsequences (may include duplicates)

---

## 🧠 What is the Longest Common Subsequence (LCS)?

A **subsequence** is a sequence derived by deleting characters from a string without changing the order.

Example:  
String = `"ABCDEF"` → Subsequences = `"ACE"`, `"BDF"`, `"ABF"`, etc.

The **Longest Common Subsequence (LCS)** is the longest subsequence that appears **in both strings**.

Example:

X = ABCDGH  
Y = AEDFHR  
LCS = ADH  


---

## Program Functionality

### ✔ 1. LCS Length (Dynamic Programming)

A 2D DP table of size `(m+1) × (n+1)` is filled using:

if X[i-1] == Y[j-1]:  
dp[i][j] = 1 + dp[i-1][j-1]  
else:  
dp[i][j] = max(dp[i-1][j], dp[i][j-1])  


### ✔ 2. Print one LCS

Uses **backtracking** from `dp[m][n]` to reconstruct one valid subsequence.

### ✔ 3. Print ALL Common Subsequences

A recursive function explores all possible subsequences:

If characters match → include char and move diagonally  
Else → explore both possibilities (m-1, n) and (m, n-1)  


⚠ This part can print duplicates because many paths generate the same subsequence.

---

## Sample Input

Enter first string: ABCD  
Enter second string: ACBD  


## Sample Output

Length of Longest Common Subsequence: 3  
Longest Common Subsequence: ABD  

All Common Subsequences:  
D  
BD  
CD  


---

## 📂 File Explanation

### **Functions Included**

| Function | Purpose |
|---------|----------|
| `LCSLength()` | Builds DP table and returns LCS length |
| `printLCS()` | Prints one LCS using backtracking |
| `allCommonSubsequences()` | Recursively prints all common subsequences |
| `max(a,b)` | Helper function |

---

## ⏳ Time & Space Complexity

### **1. LCS Length (Dynamic Programming)**

DP Table size = `(m+1) × (n+1)`

- **Time Complexity:**  
O(m × n)

- **Space Complexity:**  
O(m × n)


### **2. Printing One LCS**

Backtracking through DP table:

- **Time:** `O(m + n)`
- **Space:** `O(m + n)` (storing LCS)


### **3. Printing All Common Subsequences**

This is **exponential**, because each character mismatch produces two recursive calls.

Worst case for strings of length `n`:

- **Time Complexity:**  
O(2^(m+n))

- **Space Complexity:**  
O(m + n)

(recursion depth + subsequence storage)

---

## 🧮 Total Complexity Summary

| Operation | Time Complexity | Space Complexity |
|----------|------------------|------------------|
| DP LCS Length | O(m×n) | O(m×n) |
| Print one LCS | O(m+n) | O(m+n) |
| Print all common subsequences | O(2^(m+n)) | O(m+n) |
