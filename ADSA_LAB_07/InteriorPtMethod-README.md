# 🚀 Interior Point Method Implementation in C

This project contains a **C implementation of the Interior Point Method (IPM)** for solving **Linear Programming (LP)** optimization problems of the form:

Minimize: cᵀx  
Subject to: A x = b  
x > 0  
This code implements a simplified **barrier-based interior point algorithm** using:

- Log barrier function: `-μ * Σ log(xᵢ)`
- Gradient descent updates
- Projection to maintain `Ax = b`
- Barrier parameter reduction: `μ ← μ * 0.5`

It is **not a full Newton-based interior point solver**, but a clean and understandable educational version useful for learning how IPM works.

---

## 📌 Features

### ✔ Barrier objective function  
Adds `-μ log(xᵢ)` terms to keep the solution strictly positive.

### ✔ Gradient computation  
Gradient =  `∇f(x) = c - μ * (1/x)`  


### ✔ Projection step  
After each gradient update, the algorithm adjusts `x` to satisfy `Ax = b`.

### ✔ Barrier reduction  
μ is reduced in steps to approach the constraint boundary smoothly.

---

## 🧠 Algorithm Overview

The algorithm performs:

### **1️⃣ Initialize**
- Start with `x = [1,1,…]`
- Barrier parameter `μ = 1.0`

### **2️⃣ For each outer iteration**
- Compute gradient of barrier function  
- Perform gradient descent  
- Project to ensure constraints `Ax = b`  
- Reduce barrier parameter

### **3️⃣ Stop when μ is small**

### **4️⃣ Output approximate optimal solution**

---

## 🧮 Mathematical Formulation

The modified objective: `F(x) = cᵀx - μ Σ log(xᵢ)`    
Gradient: `∂F/∂xᵢ = cᵢ - μ / xᵢ`  

# ⏳ Time Complexity
Let:  
n = number of variables  
m = number of equality constraints  
I = number of outer μ-reductions (20 in code)  
K = number of gradient descent steps per outer loop (20,000)  

### 1️⃣ Gradient computation  
O(n)
### 2️⃣ Matrix-vector multiplication (Ax)
O(mn)
### 3️⃣ Projection update
O(mn)  
Total per inner iteration: O(mn)   
Total overall time complexity: **O(I × K × m × n)** 

# 📦 Space Complexity

The code stores:  

--> Matrix `A` → O(mn)  

--> Vectors `x`, `b`, `c`, gradient → O(n + m)  

Overall Space Complexity: **O(mn)**  

## 📌 Example Program Flow (Output)
Running Interior Point Method...  
Iter  0  μ = 1.00000   x = [ 0.9951 0.8781 ... ]   f = 3.5512  
Iter  1  μ = 0.50000   x = [ 1.1022 0.9044 ... ]   f = 2.1283  

Optimal x ≈ [ 1.234  0.998  ... ]  
Optimal objective ≈ 3.456789  
