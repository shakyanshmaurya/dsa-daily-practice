#include <stdio.h>

#define MAX 10

int main() {

    int vertices, edges;
    int graph[MAX][MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");

    for (int i = 0; i < edges; i++) {

        int u, v;

        scanf("%d %d", &u, &v);

        // Undirected graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for (int i = 0; i < vertices; i++) {

        for (int j = 0; j < vertices; j++) {

            printf("%d ", graph[i][j]);
        }

        printf("\n");
    }

    return 0;
}