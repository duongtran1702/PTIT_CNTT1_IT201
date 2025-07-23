#include <stdio.h>
#include <stdlib.h>

#define s 3

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node **adjList, int b, int e)
{
    Node *n1 = createNode(e);
    n1->next = adjList[b];
    adjList[b] = n1;

    Node *n2 = createNode(b);
    n2->next = adjList[e];
    adjList[e] = n2;
}

void printGraph(Node **adjList)
{
    for (int i = 0; i < s; i++)
    {
        printf("%d: ", i);
        Node *tmp = adjList[i];
        if (!tmp)
        {
            printf("NULL\n");
        }
        else
        {
            while (tmp)
            {
                printf("%d -> ", tmp->vertex);
                tmp = tmp->next;
            }
            printf("NULL\n");
        }
    }
}

void freeGraph(Node **adjList)
{
    for (int i = 0; i < s; i++)
    {
        Node *current = adjList[i];
        while (current != NULL)
        {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adjList);
}


int main()
{
    Node **adjList = (Node **)malloc(sizeof(Node *) * s);
    for (int i = 0; i < s; i++)
    {
        adjList[i] = NULL;
    }
    printf("Initial graph:\n");
    printGraph(adjList);
    printf("\n");

    addEdge(adjList, 1, 2);
    printf("After adding edge 1 - 2:\n");
    printGraph(adjList);
    printf("\n");

    addEdge(adjList, 0, 1);
    printf("After adding edge 0 - 1:\n");
    printGraph(adjList);
}