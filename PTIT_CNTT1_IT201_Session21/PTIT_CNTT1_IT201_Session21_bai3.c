#include <stdio.h>

#define s 3

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

void addEdge(int g[s][s], int b, int e)
{
    g[b][e] = 1;
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

int main()
{
    int graph[s][s];

    initGraph(graph);
    printGraph(graph);

    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

    printGraph(graph);

    return 0;
}