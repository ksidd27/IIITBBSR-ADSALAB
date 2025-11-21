# Infix to Postfix Conversion and Postfix Evaluation in C

This project implements two classic compiler design operations using **stack data structures**:

1. **Convert an infix expression to postfix (Reverse Polish Notation)**  
2. **Evaluate the postfix expression (only if all operands are numeric)**

It demonstrates stack operations, operator precedence, and expression parsing—core concepts in Data Structures and Compiler Design.

---

## ✨ Features

✔ Converts infix expressions (e.g., `A+B*C`) to postfix (`ABC*+`)  
✔ Supports operators: `+ - * / ^`  
✔ Handles parentheses `(` and `)`  
✔ Evaluates postfix expressions **if they contain only digits**  
✔ Stack implemented manually using arrays  
✔ Prevents underflow and overflow conditions  

---

## 📘 How It Works

### 🔹 **Infix to Postfix Conversion (Using Stack)**
The algorithm uses:
- Stack to hold operators  
- Operator precedence  
- Associativity rules  
- Direct output of operands  

Example:  
Infix: (A+B)*C

Postfix: AB+C*

---

### 🔹 **Postfix Expression Evaluation**
A stack-based evaluation is performed:

Example:  

Postfix: 2354+

Evaluation: (23) + (54) = 6 + 20 = 26

If the expression contains variables like `A` or `x`, evaluation is skipped.

---

## 🧠 Time Complexity

### **Infix → Postfix Conversion**
Each symbol of the expression is processed **once**:

Time Complexity: O(n)
& 
Space Complexity: O(n)


### **Postfix Evaluation**
Each character is pushed/popped at most once:

Time Complexity: O(n)
& 
Space Complexity: O(n)

### Example Run
Enter an infix expression: 3+5*2

Postfix Expression: 352*+

Evaluated Result: 13
