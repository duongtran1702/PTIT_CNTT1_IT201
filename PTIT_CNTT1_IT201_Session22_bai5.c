#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Graph
{
    int numVertex;
    int **adjMatrix;
} Graph;

Graph *init(int n)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->numVertex = n;
    g->adjMatrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
        g->adjMatrix[i] = malloc(sizeof(int) * n);
    return g;
}

void initMatrix(Graph *g)
{
    for (int i = 0; i < g->numVertex; i++)
    {
        for (int j = 0; j < g->numVertex; j++)
        {
            g->adjMatrix[i][j] = 0;
        }
    }
}

int countVertex(Graph *g, int x)
{
    int count = 0;
    for (int j = 0; j < g->numVertex; j++)
    {
        if (g->adjMatrix[x][j] == 1)
        {
            count++;
        }
    }
    return count;
}
void addEdge(Graph *g, int b, int e)
{
    g->adjMatrix[b][e] = g->adjMatrix[e][b] = 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    Graph *g = init(n);
    initMatrix(g);
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) == 2)
    {
        addEdge(g, n1, n2);
    }
    printf("%d", countVertex(g, 3));
}