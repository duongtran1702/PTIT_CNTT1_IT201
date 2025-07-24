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

void BFS(Graph *g, int start)
{
    int visited[MAX] = {0};
    int q[MAX];
    int front = 0;
    int back = 0;

    q[back++] = start;
    visited[start] = 1;
    while (front < back)
    {
        int u = q[front++];
        printf("%d ", u);

        for (int i = 0; i < g->numVertex; i++)
        {
            if (g->adjMatrix[u][i] == 1 && visited[i] == 0)
            {
                q[back++] = i;
                visited[i] = 1;
            }
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
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    printf("Cac dinh duoc duyet theo BFS tu %d: ", start);
    BFS(g, start);

    for (int i = 0; i < v; i++)
        free(g->adjMatrix[i]);
    free(g->adjMatrix);
    free(g);

    return 0;
}