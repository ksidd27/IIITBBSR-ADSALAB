#include <stdio.h>
#include <math.h>

#define N 3   // Matrix size (change as needed)

// Perform LUP decomposition (A -> L and U in same array)
int lup_decompose(double A[N][N], int P[N]) {
    int i, j, k, pivot;
    double maxA, absA, temp;

    // Initialize permutation vector
    for (i = 0; i < N; i++) {
        P[i] = i;
    }

    for (i = 0; i < N; i++) {
        // Find pivot row
        maxA = 0.0;
        pivot = i;
        for (k = i; k < N; k++) {
            absA = fabs(A[k][i]);
            if (absA > maxA) {
                maxA = absA;
                pivot = k;
            }
        }

        if (maxA < 1e-12) {
            return 0; // Singular matrix
        }

        // Swap rows in permutation
        if (pivot != i) {
            int tmp = P[i];
            P[i] = P[pivot];
            P[pivot] = tmp;
        }

        // Swap rows in A
        for (j = 0; j < N; j++) {
            temp = A[i][j];
            A[i][j] = A[pivot][j];
            A[pivot][j] = temp;
        }

        // Elimination
        for (j = i + 1; j < N; j++) {
            A[j][i] /= A[i][i];
            for (k = i + 1; k < N; k++) {
                A[j][k] -= A[j][i] * A[i][k];
            }
        }
    }
    return 1;
}

// Print L, U, P matrices
void print_decomposition(double A[N][N], int P[N]) {
    int i, j;
    double L[N][N] = {0}, U[N][N] = {0}, Pm[N][N] = {0};

    // Extract L and U
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i > j)
                L[i][j] = A[i][j];
            else if (i == j)
                L[i][j] = 1.0;
            else
                L[i][j] = 0.0;

            if (i <= j)
                U[i][j] = A[i][j];
            else
                U[i][j] = 0.0;
        }
    }

    // Build permutation matrix Pm
    for (i = 0; i < N; i++) {
        Pm[i][P[i]] = 1.0;
    }

    // Print L
    printf("L matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", L[i][j]);
        printf("\n");
    }

    // Print U
    printf("\nU matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", U[i][j]);
        printf("\n");
    }

    // Print P
    printf("\nP matrix:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf("%8.4f ", Pm[i][j]);
        printf("\n");
    }
}

// {4, 7, 7},
//         {2, 3, 1},
//         {6, 18, 22}

int main() {
    double A[N][N] = {
        {1, 6, 7},
        {2, 3, 1},
        {4
            , 8, 2}
    };
    int P[N];

    if (!lup_decompose(A, P)) {
        printf("Matrix is singular!\n");
        return -1;
    }

    print_decomposition(A, P);

    return 0;
}