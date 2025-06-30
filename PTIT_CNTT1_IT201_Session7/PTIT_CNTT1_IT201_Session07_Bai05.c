#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *a, int l, int r)
{
    int pivot = a[r];
    int idx = l;
    for (int i = l; i < r; i++)
    {
        if (pivot > a[i])
        {
            swap(&a[i], &a[idx]);
            idx++;
        }
    }
    swap(&a[idx], &a[r]);
    return idx;
}
void quickSort(int *a, int l, int r)
{
    if (l >= r)
        return;
    int pivot = partition(a, l, r);
    quickSort(a, l, pivot - 1);
    quickSort(a, pivot + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}