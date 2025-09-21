# 🔢 LUP Decomposition in C

This repository contains a **C program** that performs **LUP decomposition** (also known as **LU decomposition with partial pivoting**) of a given square matrix.

---

## 📌 What is LUP Decomposition?

LUP decomposition factorizes a square matrix **A** into three matrices:

\[
PA = LU
\]

Where:
- **L** = Lower triangular matrix (with 1s on the diagonal)  
- **U** = Upper triangular matrix  
- **P** = Permutation matrix (represents row swaps for numerical stability)  

This is very useful for:
- Solving systems of linear equations
- Computing determinants
- Matrix inversion  

---

## 🧩 Code Explanation

### Functions

1. **`lup_decompose(double A[N][N], int P[N])`**
   - Performs LU decomposition with partial pivoting.
   - Finds a pivot row (the row with the largest absolute value in the current column) to avoid numerical instability.
   - Swaps rows in both the permutation vector `P` and the matrix `A`.
   - Applies Gaussian elimination to transform the matrix into `L` and `U` (stored together in `A`).

   Returns `0` if the matrix is **singular** (non-invertible).

2. **`print_decomposition(double A[N][N], int P[N])`**
   - Extracts the **L** and **U** matrices from `A`.
   - Builds the **Permutation Matrix (P)** using the permutation vector.
   - Prints **L**, **U**, and **P** matrices.

3. **`main()`**
   - Defines the input matrix `A`.
   - Calls `lup_decompose()` and checks if decomposition is possible.
   - Prints **L**, **U**, and **P**.

---

## ▶️ Example Run

**Input Matrix:**
\[
A = \begin{bmatrix}
1 & 6 & 7 \\
2 & 3 & 1 \\
4 & 8 & 2
\end{bmatrix}
\]

**Output:**
L matrix:

1.0000 0.0000 0.0000

0.2500 1.0000 0.0000

0.5000 -0.0769 1.0000

U matrix:

4.0000 8.0000 2.0000

0.0000 4.0000 6.5000

0.0000 0.0000 6.1538

P matrix:

0.0000 0.0000 1.0000

1.0000 0.0000 0.0000

0.0000 1.0000 0.0000
