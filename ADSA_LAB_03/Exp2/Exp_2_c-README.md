# Binary Search Tree (BST) Creation & Traversal in C

This project implements a **Binary Search Tree (BST)** in the C programming language.  
The user can insert multiple integer values into the BST and then choose a traversal method to display the output (Inorder, Preorder, or Postorder).

---

## 🌳 What This Program Does

✔ Takes `n` integers as input from the user  
✔ Inserts them one-by-one into a **Binary Search Tree**  
✔ Asks the user to choose one of the 3 traversal types:  
   - **Inorder Traversal** (produces sorted output)  
   - **Preorder Traversal**  
   - **Postorder Traversal**  
✔ Displays the chosen traversal result  

This helps understand BST operations and tree traversal techniques taught in Data Structures.

---

## 🧠 How the BST Works

### **Insertion Rule**
A Binary Search Tree stores elements such that:
- Left child contains values **smaller** than the node  
- Right child contains values **greater** than the node  

This ensures fast searching and ordered traversal.

### **Tree Traversals**
| Traversal | Order | Purpose |
|----------|--------|----------|
| **Inorder** | Left → Node → Right | Always gives **sorted output** |
| **Preorder** | Node → Left → Right | Used for tree construction |
| **Postorder** | Left → Right → Node | Used for deleting/freeing a tree |

---

## 📈 Time Complexity

### **Insertion in BST**
- **Average Case:** `O(log n)`  
- **Worst Case:** `O(n)` (when input is sorted, tree becomes skewed)

### **Traversals (Inorder, Preorder, Postorder)**
Each traversal visits **every node exactly once**:

Time Complexity: O(n)

Space Complexity: O(h) where h = height of tree

---

### Sample Output
Enter number of elements: 5

Enter 5 integers: 50 30 20 40 70

Choose traversal to display sorted output:

1. Inorder (Sorted Order)

2. Preorder

3. Postorder

Enter your choice: 1

Traversal Result: 20 30 40 50 70
