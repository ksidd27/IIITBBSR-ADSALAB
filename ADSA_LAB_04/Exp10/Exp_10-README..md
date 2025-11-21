# Strassen’s Matrix Multiplication in C

This project implements **Strassen’s Algorithm**, an optimized divide-and-conquer method for multiplying two matrices faster than the conventional O(n³) matrix multiplication.

The input consists of two **square matrices of size n × n**, where `n` must be a **power of 2** (2, 4, 8, 16, ...).  
The program outputs the product matrix computed using Strassen’s approach.

---

## 📘 What This Program Does

Strassen’s Algorithm reduces the number of multiplication operations by breaking matrices into submatrices and recursively combining results.

Given two matrices:

A =  
|A11 A12|  
|A21 A22|

B =   
|B11 B12|  
|B21 B22|


It computes the product using **7 multiplications** instead of 8:

M1 = (A11 + A22)(B11 + B22)  
M2 = (A21 + A22) B11  
M3 = A11 (B12 - B22)  
M4 = A22 (B21 - B11)  
M5 = (A11 + A12) B22  
M6 = (A21 - A11)(B11 + B12)  
M7 = (A12 - A22)(B21 + B22)  


Then the result matrix C is calculated as:

C11 = M1 + M4 - M5 + M7  
C12 = M3 + M5  
C21 = M2 + M4  
C22 = M1 - M2 + M3 + M6  


The program:
- Reads two matrices
- Recursively applies Strassen’s algorithm
- Prints the resulting product matrix

---

## 📂 **Program Features**
✔ Recursive divide-and-conquer approach  
✔ Matrix addition and subtraction helper functions  
✔ Works for matrix sizes that are powers of 2  
✔ Produces correct multiplication using only **7 recursive calls**  

---

## 📌 Example Input

Enter the size of the square matrices (power of 2, e.g., 2, 4, 8): 2  

Enter elements of Matrix A:  
1 2  
3 4  

Enter elements of Matrix B:  
5 6  
7 8  


## 📌 Example Output

Resultant Matrix after Strassen Multiplication:  
19 22  
43 50  


---

## ⏱ Time Complexity & Space Complexity

### **Time Complexity**

Strassen's algorithm uses the recurrence:
T(n) = 7T(n/2) + O(n²)  

Using the Master Theorem:  
Time = O(n^log₂7) ≈ O(n^2.807)  

### Comparison:
| Algorithm | Time Complexity |
|----------|----------------|
| Standard Matrix Multiplication | O(n³) |
| **Strassen’s Algorithm** | **O(n².807)** |

Faster than standard multiplication for large matrices.

---

## **Space Complexity**

Strassen requires storing multiple intermediate matrices:  
Temp matrices  
A11, A12, A21, A22  
B11, B12, B21, B22  
M1–M7  


Space complexity: O(n²)   


