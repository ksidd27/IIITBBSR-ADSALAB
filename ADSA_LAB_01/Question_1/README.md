# Function Growth Comparison in C

This project compares the growth of multiple mathematical functions in C and prints their **asymptotic increasing order**.  
It computes values for each function over a range of `n`, takes averages, and sorts them to empirically approximate their growth rates.

---

## 📌 Functions Compared

We evaluate the following 12 functions:

1. **f1(n) = 1/n**  
2. **f2(n) = log₂(n)**  
3. **f3(n) = 12·√n**  
4. **f4(n) = 50·√n**  
5. **f5(n) = n^0.51**  
6. **f6(n) = n·log₂(n)**  
7. **f7(n) = n² − 324**  
8. **f8(n) = 100·n² + 6n**  
9. **f9(n) = 2·n³**  
10. **f10(n) = n^(log₂(n))**  
11. **f11(n) = 3^n**  
12. **f12(n) = 2^n**

---

## ⚖️ Equal Growth (Θ Notation)

Some functions differ only by constant factors and are therefore **asymptotically equal**:

- `12√n` and `50√n` → Both are Θ(√n)  
- `n² − 324` and `100n² + 6n` → Both are Θ(n²)  

These constants and small subtractions do **not** affect the asymptotic growth order.

---

## 📈 Asymptotic Growth Order
The theoretical increasing order of the functions is:
1/n < log₂(n) < √n (both 12√n and 50√n) < n^0.51 < n·log₂(n) < n² (both n²−324 and 100n²+6n) < 2n^3 < n^(log₂ n) < 3^n < 2^n 

---

## 🖥️ Program Output (Example for N = 2^20)

When running the program with `N = 1,048,576 (2^20)`, the output order is: 
1/n < log2(n) < 12sqrt(n) < 50sqrt(n) < n^0.51 < n*log(n) < n^2-324 < 100n^2+6n < 2n^3 < n^log(n) < 3^n < 2^n

This matches the **asymptotically correct growth order**.

---

## 🔧 Why We Fixed `2^32·n` to `2^n`

Originally, the code used: 
f12(n) = 2^32 · n

But this is **not exponential** — it’s just a linear function with a very large constant.  
Asymptotically, `2^32·n` is **Θ(n)**, which will **never surpass n·log(n), n², or n³**.  

The intended comparison was with an **exponential function**.  
Therefore, we corrected it to:

f12(n) = 2^n

Now the function grows much faster than all polynomials and logarithmic terms, fitting correctly at the top of the order.
