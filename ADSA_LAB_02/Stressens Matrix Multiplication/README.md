# ⚡ Strassen’s Matrix Multiplication in C

This project implements **Strassen’s Algorithm** for **matrix multiplication** in C.  
It improves over the **classical \(O(n^3)\)** algorithm by reducing the number of multiplications using a **divide-and-conquer approach**.

---

## 📌 What is Strassen’s Algorithm?

Strassen’s algorithm is a **recursive matrix multiplication method** that reduces the multiplication count from 8 (in standard divide-and-conquer) to 7 for two \(2 \times 2\) matrices.  
This reduces the overall time complexity from:

$O(n^3) \to O(n^{\log_2 7}) \approx O(n^{2.81})$


---

## 🧩 How the Program Works

1. The program reads the **matrix size** `N` (must be a **power of 2**, e.g., 2, 4, 8, 16).  
   > ⚠️ The code does not use padding, so non-power-of-2 sizes are not supported.

2. The input matrices `A` and `B` are divided into four submatrices each:  
A = | A11 A12 |
| A21 A22 |  B = | B11 B12 |
| B21 B22 |

3. The algorithm computes **7 products** (M1 to M7) recursively using combinations of submatrices:
M1 = (A11 + A22)(B11 + B22)
M2 = (A21 + A22)B11
M3 = A11(B12 - B22)
M4 = A22(B21 - B11)
M5 = (A11 + A12)B22
M6 = (A21 - A11)(B11 + B12)
M7 = (A12 - A22)(B21 + B22)

4. The results are combined into the final product matrix `C`:
C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6

5. The **resultant matrix C** is printed.

---

## ▶️ Example Run

**Input:**
Because our code does not uses padding

Enter matrix size (must be a power of 2): 2

Enter elements of 1st matrix row wise:

1 2\
3 4

1st matrix:

1 2\
3 4

Enter elements of 2nd matrix row wise:

5 6\
7 8

2nd matrix:

5 6\
7 8


**Output:**
Result matrix:

19 22

43 50

---

This matches the standard multiplication:

[15 + 27 16 + 28] = [19 22]\
[35 + 47 36 + 48] = [43 50]

---

## ⏱️ Time Complexity

- Standard Matrix Multiplication: **O(n³)**
- Strassen’s Algorithm: **O(n^log₂7) ≈ O(n^2.81)**
- Base Case: **O(1)** for 1x1 matrices.

This makes Strassen’s method asymptotically faster for **large matrices**.  

> ⚠️ For **small matrices**, Strassen may be slower due to recursion overhead.
