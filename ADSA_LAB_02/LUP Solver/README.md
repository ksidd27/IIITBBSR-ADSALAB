# 🔢 LUP Decomposition & System Solver in C

This project implements **LUP decomposition** (LU decomposition with partial pivoting) in **C** to solve a system of linear equations:

\[
Ax = b
\]

Where:
- **A** is an \(N \times N\) matrix  
- **b** is the right-hand side vector  
- **x** is the solution vector  

---

## 📌 What the Program Does

1. Takes a **matrix A** and a **vector b** as input.  
2. Performs **LUP decomposition**:
   \[
   PA = LU
   \]
   - **L** = Lower triangular matrix (1s on diagonal)  
   - **U** = Upper triangular matrix  
   - **P** = Permutation matrix (row swaps)  
3. Solves the system in two steps:
   - **Forward substitution** → Solve \(Ly = Pb\)  
   - **Backward substitution** → Solve \(Ux = y\)  
4. Prints the **solution vector x**.

---

## 🧩 Code Explanation

### Functions

1. **`swap_rows(double A[N][N], int P[N], int r1, int r2)`**  
   - Swaps two rows in matrix `A` and updates the permutation array `P`.  
   - Used for **partial pivoting** to maintain numerical stability.

2. **`lup_decompose(double A[N][N], int P[N])`**  
   - Performs **LU decomposition with partial pivoting**.  
   - Returns `0` if the matrix is **singular** (non-invertible).  
   - Stores both **L** and **U** inside `A` (below diagonal = L, above diagonal = U).  

3. **`lup_solve(double A[N][N], int P[N], double b[N], double x[N])`**  
   - Uses the decomposition result to solve:  
     - Step 1: Forward substitution → \(Ly = Pb\)  
     - Step 2: Backward substitution → \(Ux = y\)  
   - Stores the final solution in vector `x`.

4. **`main()`**  
   - Reads matrix `A` and vector `b` from user input.  
   - Calls `lup_decompose()` and checks for singularity.  
   - Solves the system using `lup_solve()`.  
   - Prints the **solution vector x**.

---

## ▶️ Example Run

**Input:**
Enter the elements of matrix A (3x3):
A[0][0] = 2
A[0][1] = 1
A[0][2] = -1
A[1][0] = -3
A[1][1] = -1
A[1][2] = 2
A[2][0] = -2
A[2][1] = 1
A[2][2] = 2

Enter the elements of vector b (3 values):
b[0] = 8
b[1] = -11
b[2] = -3


**Output:**
Solution x:
x[0] = 2.000000
x[1] = 3.000000
x[2] = -1.000000

This matches the exact solution to the system.

---

## ⏱️ Time Complexity

- **LUP decomposition:** \(O(n^3)\)  
- **Forward substitution:** \(O(n^2)\)  
- **Backward substitution:** \(O(n^2)\)  

Final complexity:
\[
T(n) = O(n^3)
\]

---
