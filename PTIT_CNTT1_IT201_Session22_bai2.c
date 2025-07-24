#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int v;
    int **adjMatrix;
    Node **adjList;
} Graph;

Node *create(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->vertex = v;
    return newNode;
}

void addEdge(Node **adjList, int b, int e)
{
    Node *n1 = create(e);
    if (adjList[b] == NULL)
    {
        adjList[b] = n1;
    }
    else
    {
        Node *tmp = adjList[b];
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = n1;
    }

    Node *n2 = create(b);
    if (adjList[e] == NULL)
    {
        adjList[e] = n2;
    }
    else
    {
        Node *tmp = adjList[e];
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = n2;
    }
}

void printGraph(Node **adjList)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: ", i);
        Node *tmp = adjList[i];
        while (tmp)
        {
            printf("%d ", tmp->vertex);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d", &n);
    Node **adjList = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++)
        adjList[i] = NULL;

    int n1, n2;
    while (scanf("%d %d", &n1, &n2) == 2)
    {
        addEdge(adjList, n1, n2);
    }
    printGraph(adjList);
}