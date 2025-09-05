# ⚡ Heap Sort Implementation in C

Heap Sort is a **comparison-based sorting algorithm** that uses the **binary heap data structure**.  

It has a guaranteed **time complexity of O(n log n)** for all cases, making it efficient and predictable.

---

## 📌 How Heap Sort Works

1. **Build a Max Heap**  
   - Convert the input array into a **Max Heap**.  
   - In a Max Heap, every parent node is greater than or equal to its children.  

2. **Extract Elements**  
   - The root (maximum element) is swapped with the last element of the heap.  
   - The heap size is reduced by 1, excluding the sorted element.  

3. **Heapify**  
   - After swapping, restore the heap property by calling the `heapify()` function.  
   - Repeat until all elements are sorted.  

---

## 🧩 Code Flow

### Functions

- **`heapify(int arr[], int n, int i)`**
  - Ensures that the subtree rooted at index `i` satisfies the heap property.  
  - Compares the node with its left and right children.  
  - If a child is larger, swap and recursively heapify.

- **`heapsort(int arr[], int n)`**
  - Builds a Max Heap from the input array.  
  - Repeatedly extracts the maximum element (root), swaps it with the last element, and reduces the heap size.  
  - Calls `heapify` to maintain the heap property.  

### Main Function
1. Takes array size and elements as input.  
2. Prints the **original array**.  
3. Calls `heapsort()` to sort the array.  
4. Prints the **sorted array**.

---

## 🧮 Example Run
**Input:**
Enter Number of Element: 6

Enter Array Elements: 12 3 19 6 5 14


**Output:**
Original Array : 12 3 19 6 5 14

Array after performing heap sort: 3 5 6 12 14 19

