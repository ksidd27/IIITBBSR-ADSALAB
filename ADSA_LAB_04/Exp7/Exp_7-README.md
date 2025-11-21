# Huffman Coding in C (Text Compression)

## 📌 Overview

This project implements **Huffman Coding**, a lossless compression algorithm that reduces the size of text by assigning **shorter binary codes to frequent characters** and **longer codes to less frequent characters**.

The program:

✔ Reads any input string (up to 1000 characters)  
✔ Computes character frequencies  
✔ Builds a Huffman Tree  
✔ Generates Huffman codes for each character  
✔ Prints original input  
✔ Prints generated Huffman codes  
✔ Prints the final encoded binary message  

---

## 🧠 What is Huffman Coding?

Huffman Coding is a **greedy algorithm** used for **lossless data compression**.

### Key ideas:
- Characters with higher frequency receive **shorter codes**.
- Characters with lower frequency receive **longer codes**.
- The algorithm constructs a **binary tree (Huffman Tree)** where:
  - Leaf nodes store characters
  - Internal nodes store the sum of child frequencies
- Traversing left = `0`, right = `1`
- Codes are generated from root to leaves.

---

## 📂 Features of This Implementation

### ✔ Supports all ASCII characters  
### ✔ Automatically calculates frequencies  
### ✔ Builds Huffman tree without priority queue (simplified approach)  
### ✔ Displays:  
- Original message  
- Huffman code for each character  
- Fully encoded binary message  

---

## 📥 Input Format

The program takes **any string** as input:  
Enter text (max 1000 chars): hello huffman  


---

## 📤 Output Format

Original Message: hello huffman  

Huffman Codes for each character:  
'h': 01  
'e': 110  
'l': 10  
'o': 111  
' ': 00  
'u': 1010  
'f': 1011  
'm': 011  
'a': 010  

Final Encoded Message:  
01 110 10 10 111 ...  


(The actual codes depend on character frequencies.)

---

## 🏗 How the Code Works

### 1️⃣ **Count frequencies of each character**  
Stores only characters with frequency > 0.

### 2️⃣ **Create nodes** for each character  
Each node contains:
- character  
- frequency  
- left child  
- right child  

### 3️⃣ **Build Huffman Tree**  
Repeatedly:
- Pick **two smallest frequency nodes**  
- Combine into a new parent node

### 4️⃣ **Generate codes** by DFS traversal  
Left → 0  
Right → 1  

### 5️⃣ **Encode the full message** by concatenating all codes.

---

## ⏳ Time & Space Complexity

### ✔ **Frequency Counting**
- **Time:** `O(n)`  
- **Space:** `O(1)` (fixed array of size 256)

---

### ✔ **Building Huffman Tree (Simplified Approach)**
Instead of priority queue (min-heap), this code uses linear scanning to find the smallest nodes.

- Finding two minimums each iteration → `O(size)`
- Tree building performed `(size - 1)` times

**Time Complexity:**  
O(size²)  
(size = number of distinct characters, max 256)  


**Space Complexity:**  
O(size)  

(nodes + arrays)

---

### ✔ **Generating Huffman Codes**
DFS traversal of tree:

- **Time:** `O(size)`  
- **Space:** `O(size × height)` worst case

---

### ✔ **Encoding the message**
For input length `n`:

- **Time:** `O(n × L)`  
  where `L` = average code length

- **Space:** `O(n × L)` for encoded string

---

### Overall Complexity Summary

| Step | Time Complexity | Space Complexity |
|------|------------------|------------------|
| Counting frequencies | O(n) | O(1) |
| Building Huffman Tree | O(size²) | O(size) |
| Generating codes | O(size) | O(size) |
| Encoding message | O(n × L) | O(n × L) |
| **Total** | **O(n + size²)** | **O(n × L)** |

Where:  
- `n` = input length  
- `size` = distinct characters (≤256)

