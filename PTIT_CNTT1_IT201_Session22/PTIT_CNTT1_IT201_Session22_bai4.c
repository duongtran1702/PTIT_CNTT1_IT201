#include <stdio.h>
#include <stdlib.h>

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
        g->adjMatrix[i] = malloc(sizeof(int)*n);
    return g;
}

void enterMatrix(Graph *g)
{
    for (int i = 0; i < g->numVertex; i++)
    {
        for (int j = 0; j < g->numVertex; j++)
        {
            scanf("%d", &(g->adjMatrix[i][j]));
        }
    }
}

int countEdge(Graph *g)
{
    int count = 0;
    for (int i = 0; i < g->numVertex; i++)
    {
        for (int j = 0; j < g->numVertex; j++)
        {
            if (g->adjMatrix[i][j] == 1)
            {
                ++count;
                g->adjMatrix[j][i] = 0;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    Graph *g = init(n);
    enterMatrix(g);
    int numEdge = countEdge(g);
    printf("%d", numEdge);
}