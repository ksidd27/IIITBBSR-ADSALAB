# AVL Tree Implementation in C (Insertion, Deletion, Preorder Traversal)

This project implements an **AVL Tree** in C — a self-balancing Binary Search Tree (BST).  
AVL Trees maintain their height balance by performing **rotations** after every insertion and deletion.  
This ensures that search, insert, and delete operations always work efficiently in **O(log n)** time.

The program provides a menu-driven interface to:
- Insert a key  
- Delete a key  
- Display the tree using preorder traversal  
- Exit the program  

---

## 🌳 What is an AVL Tree?

An **AVL Tree** is a height-balanced Binary Search Tree where:

Balance Factor = height(left subtree) - height(right subtree)


AVL property: |Balance Factor| ≤ 1 for every node


Whenever this condition is violated after insertion or deletion, the tree automatically balances itself using:

- **Left Rotation**
- **Right Rotation**
- **Left-Right Rotation**
- **Right-Left Rotation**

This guarantees:
- Faster lookups  
- Strict height balancing  
- Predictable performance  

---

## 🚀 Features of This Program

✔ Insert nodes (with automatic balancing)  
✔ Delete nodes (with rebalancing)  
✔ Preorder traversal display  
✔ Uses single and double rotations  
✔ Fully dynamic memory allocation  
✔ Clean and modular structure  

---

## 📐 Operations & Time Complexity

### **1. Insertion**
Every insertion may cause rotations if the tree becomes unbalanced.

Time Complexity: O(log n) & 
Space Complexity: O(log n) due to recursion


### **2. Deletion**
More complex than insertion because:
- Node may have 0, 1, or 2 children
- Rebalancing required after deletion

Time Complexity: O(log n) <br> 
Space Complexity: O(log n)


### **3. Preorder Traversal (Root → Left → Right)**

Time Complexity: O(n) <br>
Space Complexity: O(n) for recursion


### **4. Searching (Inherited from BST)**

Time Complexity: O(log n)

---

### Example Output
--- AVL Tree Menu ---
1. Insert
2. Delete
3. Display (Preorder)
4. Exit 

Enter your choice: 1  
Enter value to insert: 30  
Inserted 30.

Enter your choice: 1  
Enter value to insert: 20  
Inserted 20.

Enter your choice: 1  
Enter value to insert: 40  
Inserted 40.

Enter your choice: 3  
Preorder traversal: 30 20 40
