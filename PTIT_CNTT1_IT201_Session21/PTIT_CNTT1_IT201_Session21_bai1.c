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

int main()
{
    int graph[s][s];

    initGraph(graph);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);

    printGraph(graph);

    return 0;
}