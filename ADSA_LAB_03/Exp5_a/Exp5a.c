#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME 50

// Structure to store node names
typedef struct {
    char name[MAX_NAME];
} Node;

// Adjacency matrix for simplicity
int adj[MAX_NODES][MAX_NODES];
Node nodes[MAX_NODES];
int nodeCount = 0;

// Find node index by name (or create if not exists)
int getNodeIndex(char* name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i].name, name) == 0)
            return i;
    }
    strcpy(nodes[nodeCount].name, name);
    nodeCount++;
    return nodeCount - 1;
}

// Print the graph adjacency list
void printGraph() {
    printf("\nGraph (Adjacency List):\n");
    for (int i = 0; i < nodeCount; i++) {
        printf("%s -> ", nodes[i].name);
        int hasEdge = 0;
        for (int j = 0; j < nodeCount; j++) {
            if (adj[i][j]) {
                printf("%s ", nodes[j].name);
                hasEdge = 1;
            }
        }
        if (!hasEdge) printf("No connections");
        printf("\n");
    }
}

int main() {
    char node1[MAX_NAME], node2[MAX_NAME], relation[MAX_NAME];
    int choice;

    printf("Enter SIF data (Format: Node1 Relation Node2)\n");
    printf("Type END to stop input.\n");

    while (1) {
        printf(">> ");
        scanf("%s", node1);
        if (strcmp(node1, "END") == 0)
            break;
        scanf("%s %s", relation, node2);

        int index1 = getNodeIndex(node1);
        int index2 = getNodeIndex(node2);

        // Undirected graph (both directions)
        adj[index1][index2] = 1;
        adj[index2][index1] = 1;
    }

    printGraph();

    return 0;
}
