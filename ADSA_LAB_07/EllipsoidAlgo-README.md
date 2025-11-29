# 🔵 Ellipsoid Method Implementation in C

This project contains a complete **C implementation of the Ellipsoid Method** used for solving **feasibility problems** of the form:

Find x such that: A x ≤ b  

The Ellipsoid Method is an iterative optimization algorithm used in convex optimization and theoretical computer science. It works by:

1. Starting from an initial **ellipsoid** that contains the feasible region.
2. Checking if the current center satisfies all constraints.
3. If a constraint is violated, cutting the ellipsoid using a **separating hyperplane**.
4. Updating the ellipsoid to a smaller one that still contains all feasible points.

This algorithm guarantees convergence for feasible convex sets but can be computationally expensive in practice.

---

# 📌 Features

### ✔ Matrix-vector multiplication  
Used for checking constraints.

### ✔ Ellipsoid update rule  
Implements standard ellipsoid shrinking formulas using:
- New center: x_new = x - (gamma * P*a) / sqrt(aᵀ P a)
- New shape matrix `P_new`: P_new = (n² / (n² - 1)) * (P - β * (Pa)(Pa)ᵀ / (aᵀ P a))


### ✔ Automatic feasibility detection  
Stops when `Ax ≤ b + EPS`.

### ✔ Prints intermediate ellipsoid centers  
Every 50 iterations.

---

# 🧠 Algorithm Overview

### **1️⃣ Input**
- Number of variables `n`
- Number of constraints `m`
- Constraint matrix `A (m × n)`
- Constraint vector `b (m)`
- Initial guess `x₀`
- Initial ellipsoid radius `R`

### **2️⃣ Initialize Ellipsoid**
**P = R² I**  


### **3️⃣ For each iteration**
- Compute `Ax`
- If no constraint is violated → feasible solution found
- Otherwise:
  - Identify violated constraint `aᵢ x > bᵢ`
  - Compute ellipsoid update using:
    - `Pa = P * a`
    - `aᵀPa`
    - New center `x_new`
    - New shape matrix `P_new`

### **4️⃣ Repeat up to MAX_ITER times**

If no solution is found → infeasibility likely.

---
# ⏳ Time Complexity

Let:
- `n` = number of variables
- `m` = number of constraints
- `T` = maximum iterations (set as 1000)

**1️⃣ Evaluating Ax**  
O(mn)

**2️⃣ Ellipsoid Update**

- Computing `Pa = P a` → O(n²)
- Computing `aᵀPa` → O(n)
- Outer product (Pa)(Pa)ᵀ → O(n²)
- Updating P → O(n²)

Total per iteration: O(n² + mn)  

### Overall Time Complexity
Since the loop runs for at most `T` iterations: O(T × (n² + mn))  
With T = 1000 (constant): **O(n² + m n)**

# 📦 Space Complexity

The stored data includes:
- Matrix A → O(mn)  
- Shape matrix P → O(n²)  
- Vectors x, b, Pa, Ax → O(n + m)  

Overall Space Complexity: **O(mn + n²)**  

---
## 🖥 Sample Output

Running Ellipsoid Method...  
Iter 50: center = [ 0.34552 0.12344 ]  
Iter 100: center = [ 0.21231 0.09112 ]  

Feasible solution found at iteration 133:  
[ 0.20012 0.08193 ]  





