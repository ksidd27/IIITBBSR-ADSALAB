#include <stdio.h>

//ternary Search and Binary Search

int ternarySrch(int min, int high, int arr[], int x, int *count1){
    
    while (min <= high) {
        int mid1 = min + (high - min) / 3;
        int mid2 = high - (high - min) / 3;

        (*count1)++;
        if (arr[mid1] == x) {
            printf("Key found in Ternary Search At index %d\n",mid1);
            printf("Number of Comparisons in: %d\n", *count1);
            return 0;
        }
        (*count1)++;
        if (arr[mid2] == x) {
            printf("Key found in Ternary Search At index %d\n",mid2);
            printf("Number of Comparisons : %d\n", *count1);

            return 0;
        }

        if (x < arr[mid1]) {
            high = mid1 - 1;
        }
        else if (x > arr[mid2]) {
            min = mid2 + 1;
        }
        else {
            min = mid1 + 1; 
            high = mid2 - 1;
        }
    }
    return -1;
}

int binarySrch(int min, int high, int arr[], int x, int *count2){

    while(min<=high){
        int mid = min + (high - min) / 2;
        
        (*count2)++;
        if (arr[mid] == x) {
            printf("Key found in Binary Search At index %d\n",mid);
            printf("Number of Comparisons : %d", *count2);

            return 0;
        }

        if (x < arr[mid]) {
            high = mid - 1;
        }
        else{
            min = mid + 1;
        }
    }
    return -1;
}

int main() {

    int count1=0;
    int count2=0;
    int n;
    printf("Enter Size of Array :");
    scanf("%d", &n);
    printf("Enter Array Elements :");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    int min = 0;
    int high = n - 1;
    printf("Enter value of key :");
    int x;
    scanf("%d",&x);

    
    int element=ternarySrch(min,high,arr,x,&count1);
    if(element == -1)
    printf("Not found in Ternary Search\n");

    int element2=binarySrch(min,high,arr,x,&count2);
    if(element2 == -1)
    printf("Not Found in Binary Search\n");
    return 0;
}