#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void initGraph(int g[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = 0;
        }
    }
}

void addEdge(int g[MAX][MAX], int b, int e)
{
    g[b][e] = g[e][b] = 1;
}

void printGraph(int g[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", g[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int g[MAX][MAX];

    scanf("%d", &n);
    initGraph(g, n);

    
    int n1, n2;
    while (scanf("%d %d", &n1, &n2) == 2)
    {
        addEdge(g, n1, n2);
    }
    printGraph(g, n);
}