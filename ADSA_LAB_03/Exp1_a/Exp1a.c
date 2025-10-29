#include <stdio.h>

// Recursive Binary Search Function
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Key found
        else if (key < arr[mid])
            return binarySearchRecursive(arr, low, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1; // Key not found
}

// Non-Recursive (Iterative) Binary Search Function
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Key found
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1; // Key not found
}

int main() {
    int n, key, choice, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements in sorted order:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Recursive Binary Search\n");
    printf("2. Non-Recursive Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        result = binarySearchRecursive(arr, 0, n - 1, key);
    else
        result = binarySearchIterative(arr, n, key);

    if (result != -1)
        printf("Key %d found at position %d (0-based index).\n", key, result);
    else
        printf("Key %d not found in the list.\n", key);

    return 0;
}
