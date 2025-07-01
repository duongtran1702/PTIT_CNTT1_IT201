#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[tmp] > a[j])
                tmp = j;
        }
        if (tmp != i)
            swap(&a[i], &a[tmp]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    selectionSort(a, n);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}