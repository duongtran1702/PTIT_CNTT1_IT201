#include <stdio.h>
#include <stdlib.h>
int sumRow(int **a, int cols, int k)
{
    int tmp = 0;
    for (int i = 0; i < cols; i++)
    {
        tmp += a[k-1][i];
    }
    return tmp;
}

int main()
{
    int n, m;
    printf("Enter row and col:");
    scanf("%d", &n);
    scanf("%d", &m);
    if (n < 1 || n > 1000)
    {
        printf("Rows invalid\n");
        return 0;
    }
    else if (m < 1 || m > 1000)
    {
        printf("Cols invalid\n");
        return 0;
    }
    printf("Enter array:");
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (*(a + i) + j));
        }
    }
    int k;
    printf("Enter row:");
    scanf("%d", &k);
    if (k > n || k < 0)
    {
        printf("Rows invalid\n");
        return 0;
    }
    printf("sum = %d\n", sumRow(a, m, k));

    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}