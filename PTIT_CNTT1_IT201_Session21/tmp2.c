#include <stdio.h>

#define s 8

void initGraph(int g[s][s])
{
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            g[i][j] = 0;
        }
    }
}

void addEdge(int g[s][s], int n1, int n2)
{
    g[n1][n2] = g[n2][n1] = 1;
}

void printGraph(int g[s][s])
{
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < s; j++)
        {
            printf("%3d", g[i][j]);
        }
        printf("\n");
    }
}

int visited[s];

void DFS(int graph[s][s], int vertex)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < s; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(graph, i);
        }
    }
}

int main()
{
    int graph[s][s];

    initGraph(graph);

    // Graph structure: 0 isolated, 1-2-3 connected
    // addEdge(graph, 5, 6);
    addEdge(graph, 4, 7);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    // addEdge(graph, 3, 4);

    printGraph(graph);

    // Reset visited array
    for (int i = 0; i < s; i++)
        visited[i] = 0;

    printf("Connected components:\n");
    for (int i = 0; i < s; i++)
    {
        if (!visited[i])
        {
            printf("Component: ");
            DFS(graph, i);
            printf("\n");
        }
    }

    return 0;
}
