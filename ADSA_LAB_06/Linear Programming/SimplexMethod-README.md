# 📌 Simplex Algorithm Implementation in C (with Step-by-Step Tableau Printing)

This project contains a complete **C implementation of the Simplex Algorithm** used to solve **Linear Programming (LP)** problems of the form:

Maximize: Z = c₁x₁ + c₂x₂ + ...  
Subject to: Ax ≤ b  
x ≥ 0    

The code prints the **Simplex Tableau at every iteration**, shows **pivot column**, **pivot row**, **ratios**, and computes the **optimal solution**.

---

## 🚀 Features

### ✔ Step-by-step tableau printing  
Displays the tableau at every iteration to help visualize the algorithm.

### ✔ Pivot selection  
- **Pivot column**: largest positive value in objective row  
- **Pivot row**: minimum **positive ratio** (RHS / pivot column value)

### ✔ Handles unbounded and optimal conditions  
Stops if:
- No positive value in the objective row → **Optimal reached**
- No valid pivot row → **Unbounded solution**

### ✔ Final solution extraction  
Prints:
- Optimal value of **Z**
- Value of each **variable** (`x1`, `x2`, ...)

---

## 📌 Problem Solved (Example)

The embedded tableau solves:
Maximize: Z = 3x + 5y
Subject to:
2x + 3y ≤ 8
x + y ≤ 4
x, y ≥ 0  


Converted into simplex form with slack variables `s1`, `s2`.

---

## 🧠 How the Code Works

### 1️⃣ Represent tableau as a matrix  
Each row = constraint  
Last row = objective function  

### 2️⃣ Find pivot column  
The column with **largest positive value** in objective row.

### 3️⃣ Compute ratios  
For all rows where pivot column > 0:

```ratio[i] = RHS / a[i][pivot_column]```


Choose smallest positive ratio → pivot row.

### 4️⃣ Perform pivot operations  
Normalize pivot row and eliminate pivot column from all other rows.

### 5️⃣ Repeat  
Until no positive value exists in objective row.

---

## 🧮 **Time Complexity**

Let:
- `m` = number of constraints  
- `n` = number of variables + slack variables  
- `I` = number of iterations  

### **Pivot selection**
- Finding pivot column: **O(n)**
- Finding pivot row: **O(m)**

### **Pivot operation (full-row updates)**
Updating entire tableau:

(m rows) × (n columns) = O(mn)  

### ✅ **Overall Time Complexity**
`O(I × m × n)`  


Simplex can be exponential in the worst case, but **runs very fast in practice**.

---

## 💾 **Space Complexity**

The tableau is stored in an `m × n` matrix.

Space Complexity = O(mn)  
Very efficient for moderate-sized problems.

---
## 📝 Output Example (Truncated)
Current Simplex Tableau:  
   8.000    2.000    3.000    1.000    0.000  
   4.000    1.000    1.000    0.000    1.000  
   0.000   -3.000   -5.000    0.000    0.000  

Pivot column chosen: 2 with value -5.000  
Optimal solution value = 20.000  
Variable x1 = 2.000000  
Variable x2 = 2.000000  
