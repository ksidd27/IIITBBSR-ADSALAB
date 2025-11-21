# 🔍 String Pattern Matching in C  
### (KMP Algorithm & Rabin–Karp Fingerprinting Algorithm)

This project implements two powerful pattern-matching algorithms:

1. **Knuth–Morris–Pratt (KMP) Algorithm**
2. **Rabin–Karp Fingerprinting Algorithm**

The user enters a **text** and a **pattern**, then chooses the desired algorithm to search for occurrences of the pattern within the text.

---

## 📌 Overview

Pattern matching is a fundamental problem in computer science, used in:

- Text editors  
- Search engines  
- DNA sequence matching  
- Plagiarism detection  
- Compiler design  

This program allows users to compare two classical algorithms:

| Algorithm | Technique | Best For |
|----------|-----------|----------|
| **KMP** | Deterministic pattern matching using LPS table | Long texts, worst-case guarantees |
| **Rabin–Karp** | Rolling hash-based matching | Searching multiple patterns, plagiarism detection |

---

# 🧠 1. Knuth–Morris–Pratt (KMP) Algorithm

KMP avoids re-checking previously matched characters.  
It uses an auxiliary **LPS (Longest Prefix Suffix)** table.

### ✔ Key Idea

While matching:
- When a mismatch occurs, instead of restarting from the beginning,
- KMP jumps using the **LPS table**.

### ✔ Why is KMP efficient?

Because every character of the text is processed at most once.

---

# 🧮 2. Rabin–Karp Algorithm

Rabin–Karp uses **hashing** to compare pattern and text windows.

### ✔ Key Idea

- Compute a **hash** of the pattern.
- Compute hash for every window of the text.
- Compare hashes — only if they match, compare characters.

This gives excellent performance for:

- Searching **multiple patterns**
- Large text data scanning
- Document similarity detection

---

## 📂 Program Features

✔ Accepts text and pattern from the user  
✔ Supports both algorithms  
✔ Prints all found occurrences  
✔ Handles multiple occurrences  
✔ Hash-based search (Rabin–Karp)  
✔ LPS-based search (KMP)  

---

# 📥 Sample Input

Enter the text: AABAACAADAABAAABAA  
Enter the pattern to search: AABA  
Choose Algorithm:  
- KMP   
- Rabin-Karp


# 📤 Sample Output

Pattern found at index 0  
Pattern found at index 9  
Pattern found at index 13  



---

# 📊 Time & Space Complexity

## ✅ KMP Algorithm

### Time Complexity

| Step | Complexity |
|------|------------|
| Build LPS array | `O(M)` |
| Pattern search | `O(N)` |
| **Total** | `O(N + M)` |

### Space Complexity

O(M) // LPS table  


---

## ✅ Rabin–Karp Algorithm

### Time Complexity

| Case | Complexity |
|------|------------|
| Average case | `O(N + M)` |
| Best case | `O(N + M)` |
| Worst case (hash collisions) | `O(N × M)` |

Why worst case becomes slow?  
Because **every hash collision requires full character comparison**.

### Space Complexity

O(1) // constant extra space  


---

# 🧱 Technical Summary

| Feature | KMP | Rabin–Karp |
|---------|-----|-------------|
| Method | LPS table | Hashing |
| Best Use Case | Repeated searches in same text | Multiple pattern matching |
| Worst-case time | Linear | Quadratic |
| Extra space | O(M) | O(1) |



