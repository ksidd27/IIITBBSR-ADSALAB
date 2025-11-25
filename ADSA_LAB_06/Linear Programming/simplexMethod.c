#include <stdio.h>
#define MAX 10

void printTableau(float a[MAX][MAX], int m, int n) {
    printf("Current Simplex Tableau:\n");
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void simplex(float a[MAX][MAX], int m, int n) {
    int i, j, row, col;
    float key, ratio[MAX], min;

    while (1) {
        printTableau(a, m, n); // Print tableau every iteration

        // Find pivot column (max positive in objective row)
        col = -1;
        float max = 0;
        for (j = 1; j < n; j++) {
            if (a[m][j] > max) {
                max = a[m][j];
                col = j;
            }
        }
        if (col == -1) {
            printf("No positive pivot in objective row. Optimal found.\n");
            break; // optimal reached
        }
        printf("Pivot column chosen: %d with value %.3f\n", col, max);

        // Find pivot row (min positive ratio)
        min = -1;
        row = -1;
        for (i = 0; i < m; i++) {
            if (a[i][col] > 0) {
                ratio[i] = a[i][0] / a[i][col];
                printf("Ratio for row %d: %.3f\n", i, ratio[i]);
                if (min == -1 || ratio[i] < min) {
                    min = ratio[i];
                    row = i;
                }
            }
        }
        if (row == -1) {
            printf("Unbounded solution.\n");
            return;
        }
        printf("Pivot row chosen: %d with minimum ratio %.3f\n", row, min);

        // Pivot operation
        key = a[row][col];
        printf("Pivoting on element %.3f at (%d, %d)\n", key, row, col);

        for (j = 0; j < n; j++)
            a[row][j] /= key;

        for (i = 0; i <= m; i++) {
            if (i != row) {
                float factor = a[i][col];
                for (j = 0; j < n; j++)
                    a[i][j] -= factor * a[row][j];
            }
        }
    }

    printf("Optimal solution value = %.6f\n", a[m][0]);
    // Print variable values (assuming variables x1, x2 start at col 1)
    for (j = 1; j < n; j++) {
        int count_one = 0, one_row = -1;
        for (i = 0; i < m; i++) {
            if (a[i][j] == 1) {
                count_one++;
                one_row = i;
            } else if (a[i][j] != 0) {
                count_one = -1;
                break;
            }
        }
        if (count_one == 1)
            printf("Variable x%d = %.6f\n", j, a[one_row][0]);
        else
            printf("Variable x%d = 0\n", j);
    }
}

int main() {
    int m = 2, n = 5; // 2 constraints, 2 variables x1,x2 + 2 slack variables + RHS
    // Tableau: RHS in column 0, x1 in col 1, x2 in col 2, s1 in col 3, s2 in col 4
    float a[MAX][MAX] = {
        {8, 2, 3, 1, 0},  // 2x + 3y + s1 = 8
        {4, 1, 1, 0, 1},  // x + y + s2 = 4
        {0, -3, -5, 0, 0} // Objective function (Z - 3x - 5y = 0), negated for maximization
    };

    simplex(a, m, n);

    return 0;
}
