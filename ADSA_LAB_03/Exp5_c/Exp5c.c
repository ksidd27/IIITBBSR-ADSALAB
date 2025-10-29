#include <stdio.h>
#define INF 99999
#define MAX 100

void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];

    // Initialize the distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Floyd–Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(graph, n);

    return 0;
}


/* input - 
Enter the number of vertices: 4
Enter the adjacency matrix (use 99999 for INF):
0 3 99999 7
8 0 2 99999
5 99999 0 1
2 99999 99999 0
*/