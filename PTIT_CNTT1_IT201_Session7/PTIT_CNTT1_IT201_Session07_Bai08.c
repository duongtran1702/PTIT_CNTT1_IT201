#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int rows, cols;
    scanf("%d", &rows);
    scanf("%d", &cols);

    if (rows <= 0 || rows >= MAX || cols <= 0 || cols >= MAX)
    {
        return 0;
    }

    int a[MAX][MAX];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &a[i][j]);

    int k;
    scanf("%d", &k);
    k -= 1;
    if (k < 0 || k >= cols)
    {
        return 0;
    }
    int *tmp = malloc(rows * sizeof(int));

    for (int i = 0; i < rows; i++)
    {
        tmp[i] = a[i][k];
    }
    qsort(tmp, rows,sizeof(int), cmp);
    for (int i = 0; i < rows; i++)
    {
        a[i][k] = tmp[i];
    }
    free(tmp);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
