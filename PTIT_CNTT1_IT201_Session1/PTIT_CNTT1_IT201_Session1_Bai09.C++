#include <stdio.h>
#include <stdlib.h>
void printMatrix(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    { // time complexity:O(m*n)
        for (int j = 0; j < m; j++)
        {
            printf("%3d ", *(*(a + i) + j));
        }
        printf("\n");
    }
}

void printMainDiagonal(int **a, int n, int m)
{
    for (int i = 0; i < n; i++)
    { // time complexity:O(m*n)
        for (int j = 0; j < m; j++)
        {
            if (j != i)
                printf("    ");
            else
            {
                printf("%3d ", *(*(a + i) + j));
            }
        }
        printf("\n");
    }
}
int main()
{
    int n = 5, m = 5;
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++)
        {
            *(*(a + i) + j) = m * i + j + 1;
        }
    }
    printMatrix(a, n, m);
    printMainDiagonal(a, n, m);
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

} // tong ca chuong trinh:
// time complexity:O(m*n)
// space complexity(m*n)