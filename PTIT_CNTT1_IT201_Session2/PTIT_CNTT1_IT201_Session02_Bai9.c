#include <stdio.h>
#include <stdlib.h>

int *countOccurrent(int *a, int n)
{
    int *b = (int *)calloc(100, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ++b[a[i]];
    }
    return b;
}

int main()
{
    int n, x;
    printf("Enter the number element of array :");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int *b = countOccurrent(a, n);
    int count = b[0];
    for (int i = 0; i < n; i++)
    {
        if (b[a[i]] > count)
            count = b[a[i]];
    }
    for (int i = 0; i < 100; i++)
    {
        if (b[i] == count)
        {
            printf("Number : %d", i);
            break;
        }
    }
    free(a);
}