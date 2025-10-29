#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find the median-of-three pivot
int medianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid]) swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high]) swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high]) swap(&arr[mid], &arr[high]);

    // Place the median at high - 1 position
    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}

// Partition function using median-of-three pivot
int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low, j = high - 1;

    while (1) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[i], &arr[high - 1]); // Restore pivot
    return i;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low + 10 <= high) {  // cutoff for small subarrays (optional)
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    } else {
        // For very small subarrays, use simple insertion sort
        for (int i = low + 1; i <= high; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= low && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    printArray(arr, n);

    return 0;
}
