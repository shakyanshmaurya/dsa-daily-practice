#include <stdio.h>

#define MAX 10

int graph[MAX][MAX] = {0};
int vertices;

// Add Edge
void addEdge(int u, int v) {

    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Remove Edge
void removeEdge(int u, int v) {

    graph[u][v] = 0;
    graph[v][u] = 0;
}

// Check Edge
void checkEdge(int u, int v) {

    if (graph[u][v] == 1) {
        printf("Edge %d - %d exists\n", u, v);
    }
    else {
        printf("Edge %d - %d does not exist\n", u, v);
    }
}

// Display Matrix
void displayGraph() {

    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }
}

int main() {

    vertices = 4;

    // Add edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    printf("Graph after adding edges:");

    displayGraph();

    // Check edge
    printf("\nChecking edges:\n");

    checkEdge(0, 1);
    checkEdge(0, 3);

    // Remove edge
    printf("\nRemoving edge 0 - 1...\n");

    removeEdge(0, 1);

    displayGraph();

    return 0;
}