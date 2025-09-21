#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void add(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Function to subtract two matrices
void sub(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen recursive function
void strassen(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) { // Base case
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate submatrices
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];
    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];
    int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k], M7[k][k];
    int temp1[k][k], temp2[k][k];

    // Divide A and B into submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    // M1 = (A11 + A22)(B11 + B22)
    add(k, A11, A22, temp1);
    add(k, B11, B22, temp2);
    strassen(k, temp1, temp2, M1);

    // M2 = (A21 + A22)B11
    add(k, A21, A22, temp1);
    strassen(k, temp1, B11, M2);

    // M3 = A11(B12 - B22)
    sub(k, B12, B22, temp2);
    strassen(k, A11, temp2, M3);

    // M4 = A22(B21 - B11)
    sub(k, B21, B11, temp2);
    strassen(k, A22, temp2, M4);

    // M5 = (A11 + A12)B22
    add(k, A11, A12, temp1);
    strassen(k, temp1, B22, M5);

    // M6 = (A21 - A11)(B11 + B12)
    sub(k, A21, A11, temp1);
    add(k, B11, B12, temp2);
    strassen(k, temp1, temp2, M6);

    // M7 = (A12 - A22)(B21 + B22)
    sub(k, A12, A22, temp1);
    add(k, B21, B22, temp2);
    strassen(k, temp1, temp2, M7);

    // C11 = M1 + M4 - M5 + M7
    add(k, M1, M4, temp1);
    sub(k, temp1, M5, temp2);
    add(k, temp2, M7, C11);

    // C12 = M3 + M5
    add(k, M3, M5, C12);

    // C21 = M2 + M4
    add(k, M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    sub(k, M1, M2, temp1);
    add(k, temp1, M3, temp2);
    add(k, temp2, M6, C22);

    // Combine results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int main() {
    int N;
    printf("Because our code does not uses padding");
    printf("Enter matrix size (must be a power of 2): ");
    scanf("%d", &N);

    int A[N][N], B[N][N], C[N][N];

    printf("Enter elements of 1st matrix row wise:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &A[i][j]);

    printf("1st matrix:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
        {   printf("%d ", A[i][j]); }
      printf("\n");  
    }

    printf("Enter elements of 2nd matrix row wise:\n");
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &B[i][j]);
    
    printf("2nd matrix:\n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++)
          { printf("%d ", B[i][j]); }
        printf("\n");  
    }
    strassen(N, A, B, C);

    printf("Result matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}