#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];

int front = 0;
int rear = 0;
int vertices;

void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void BFS(int start)
{
    // Mark start as visited
    visited[start] = 1;

    // Put start into queue
    queue[rear++] = start;

    while (front < rear)
    {
        // Remove vertex from queue
        int current = queue[front++];

        printf("%d ", current);

        // Check all neighbours
        for (int i = 0; i < vertices; i++)
        {
            if (graph[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    vertices = 6;

    // Adding edges
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);

    printf("BFS Traversal: ");

    BFS(0);

    return 0;
}