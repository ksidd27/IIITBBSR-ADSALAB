# KMP (Knuth–Morris–Pratt) String Matching Algorithm in C

This repository contains an implementation of the **KMP (Knuth–Morris–Pratt)** algorithm for efficient pattern matching in strings.

KMP is an improvement over the brute-force string matching algorithm.  
Unlike naive search, which may re-check characters unnecessarily, KMP preprocesses the pattern to create the **LPS (Longest Prefix Suffix) array**, allowing the algorithm to skip unnecessary comparisons.

---

## 🚀 Features

### ✔ Efficient Pattern Searching  
Searches for all occurrences of a pattern inside a text.

### ✔ LPS Array Construction  
Precomputes longest prefix that is also a suffix for every index of the pattern.

### ✔ No Rechecking of Characters  
KMP avoids backtracking on the text, making it significantly faster for long patterns.

---

## 📁 File Overview

### **Functions included:**

#### 1️⃣ `buildLPS(pattern, m, lps)`
Builds the LPS table used to skip comparisons.

#### 2️⃣ `KMPsearch(text, pattern)`
Performs pattern matching using KMP logic and prints all occurrences.

#### 3️⃣ `main()`
Takes user input for text and pattern, then runs the KMP search.

---

## 🧠 How KMP Works (Short Explanation)

1. **Preprocessing phase:**  
   Build the `LPS` array where:
   - `lps[i]` = length of the longest proper prefix of the pattern  
     which is also a suffix for substring ending at index `i`.

2. **Searching phase:**  
   Use LPS to avoid recomputation:  
   When a mismatch occurs after `j` matches, instead of moving back `i`,  
   we set `j = lps[j-1]` and continue.

This makes the KMP algorithm run in **linear time**.

---

## 🧮 Time Complexity

### **Time Complexity of KMP Algorithm**
| Phase | Time Complexity |
|-------|------------------|
| **Building LPS Array** | Θ(m) |
| **Pattern Searching** | Θ(n) |
| **Total** | **Θ(n + m)** |

Where:  
- `n` = length of text  
- `m` = length of pattern  

This is optimal for deterministic pattern matching.

---

## 💾 Space Complexity

### **Space Complexity: Θ(m)**  
Only the LPS array of size equal to the pattern length is required.

---

## 📌 Output Example

Enter the text: THIS IS A TEST TEXT  
Enter the pattern: TEST  

--- KMP String Search Results ---  
Pattern found at index 10  
