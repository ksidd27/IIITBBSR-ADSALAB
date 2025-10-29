#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to find maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to find the length of LCS using Dynamic Programming
int LCSLength(char X[], char Y[], int m, int n, int dp[MAX][MAX]) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// Function to print one LCS using dp table
void printLCS(char X[], char Y[], int m, int n, int dp[MAX][MAX]) {
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    printf("Longest Common Subsequence: %s\n", lcs);
}

// Recursive function to print all common subsequences
void allCommonSubsequences(char X[], char Y[], int m, int n, char sub[], int index) {
    if (m == 0 || n == 0) {
        sub[index] = '\0';
        if (strlen(sub) > 0)
            printf("%s\n", sub);
        return;
    }

    if (X[m - 1] == Y[n - 1]) {
        sub[index] = X[m - 1];
        allCommonSubsequences(X, Y, m - 1, n - 1, sub, index + 1);
    } else {
        allCommonSubsequences(X, Y, m - 1, n, sub, index);
        allCommonSubsequences(X, Y, m, n - 1, sub, index);
    }

}

int main() {
    char X[MAX], Y[MAX];
    int dp[MAX][MAX];

    printf("Enter first string: ");
    scanf("%s", X);
    printf("Enter second string: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    int length = LCSLength(X, Y, m, n, dp);
    printf("\nLength of Longest Common Subsequence: %d\n", length);
    printLCS(X, Y, m, n, dp);

    printf("\nAll Common Subsequences (may include duplicates):\n");
    char sub[MAX];
    allCommonSubsequences(X, Y, m, n, sub, 0);

    return 0;
}
