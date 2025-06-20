#include <stdio.h>
#include <stdlib.h>
int sumMainDiagonal(int **a, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += a[i][i];
    }
    return tmp;
}
int sumSecondaryDiagonal(int **a, int n)
{
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        tmp += a[i][n-i-1];
    }
    return tmp;
}


int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    if (n < 1||n>1000)
    {
        printf("Rows invalid\n");
        return 0;
    }
    else if (m < 1||m>1000)
    {
        printf("Cols invalid\n");
        return 0;
    }
    else if(n!=m){
        printf("Cannot compute diagonals: matrix is not square");
        return 0;
    }
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf("%d", (*(a + i) + j));
        }
    }
    printf("Sum of main diagonal = %d\n", sumMainDiagonal(a, n));
    printf("Sum of secondary diagonal = %d\n", sumSecondaryDiagonal(a, n));
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}