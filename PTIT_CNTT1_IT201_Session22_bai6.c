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

void addEdge(Graph *g, int b, int e)
{
    g->adjMatrix[b][e] = g->adjMatrix[e][b] = 1;
}

void DFS(Graph *g, int u, int *visited)
{
    visited[u] = 1;
    printf("%d ", u);
    for (int i = 0; i < g->numVertex; i++)
    {
        if (g->adjMatrix[u][i] == 1 && visited[i] == 0)
        {
            DFS(g, i, visited);
        }
    }
}

int main()
{
    int v, e;
    printf("Nhap so dinh (v) va so canh (e): ");
    scanf("%d %d", &v, &e);

    Graph *g = init(v);
    initMatrix(g);

    printf("Nhap danh sach %d canh (u v):\n", e);
    int n1, n2;
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &n1, &n2);
        addEdge(g, n1, n2);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    int visited[MAX] = {0};
    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(g, start, visited);

    // Free memory
    for (int i = 0; i < v; i++)
        free(g->adjMatrix[i]);
    free(g->adjMatrix);
    free(g);

    return 0;
}