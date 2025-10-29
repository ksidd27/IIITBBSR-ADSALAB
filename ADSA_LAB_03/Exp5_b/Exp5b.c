#include <stdio.h>
#include <limits.h>

#define V 10  // Maximum number of vertices

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[], int n) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < n; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print the path from source to vertex j
void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to print the shortest distances and paths
void printSolution(int dist[], int n, int parent[], int src) {
    printf("\nShortest distances and paths from source vertex %d:\n", src);
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: Distance = %d, Path = ", i, dist[i]);
        printf("%d", src);
        printPath(parent, i);
        printf("\n");
    }
}

// Dijkstra’s algorithm
void dijkstra(int graph[V][V], int src, int n) {
    int dist[V];       // dist[i] holds the shortest distance from src to i
    int sptSet[V];     // 1 if vertex i is finalized
    int parent[V];     // To store the shortest path tree

    // Initialize distances and parents
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        parent[i] = -1;  // No parent initially
    }

    dist[src] = 0;  // Distance to source is 0

    // Find shortest paths for all vertices
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, sptSet, n);
        sptSet[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;  // Store predecessor
            }
        }
    }

    printSolution(dist, n, parent, src);
}

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[V][V];

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src, n);

    return 0;
}



/*   input - 
Enter number of vertices: 5
Enter the adjacency matrix (0 for no edge):
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter the source vertex: 0

*/