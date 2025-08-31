#include <stdio.h>

//find defective coins from N-1 perfect coins

int find(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        
        if(arr[low]< arr[high]){
            return arr[low];
        }
        int mid = low + (high - low) / 2;

       
        if ((mid == 0 || arr[mid] < arr[mid - 1]) &&
            (mid == n - 1 || arr[mid] < arr[mid + 1])) {
            return arr[mid];  
        }
        if (low > 0 && arr[low] < arr[low - 1]) {
            mid = low - 1;
        }
        else {
            
            low =  low + 1;
        }
        
        
        if ((low == 0 || arr[low] < arr[low - 1]) &&
            (low == n - 1 || arr[low] < arr[low + 1])) {
            return arr[low];  
        }

      
        if (low > 0 && arr[low] < arr[low - 1]) {
            mid = low - 1;
        }
        else {
            
            low = low + 1;
        }
    }
    return -1; 
}

int main() {
    printf("Enter number of Elements N: ");
    int n;
    scanf("%d", &n);

    printf("Enter array elements: ");

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int defect = find(arr, n);
    if (defect != -1){
        printf("Defective coin value: ");
        printf("%d",defect);
    }
    else
        printf("No defect found\n");

    return 0;
}