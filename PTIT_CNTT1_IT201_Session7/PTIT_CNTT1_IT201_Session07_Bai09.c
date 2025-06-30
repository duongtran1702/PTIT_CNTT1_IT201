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
int cmp(const void *x, const void *y)
{
    return *(int *)y - *(int *)x;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    int *odd = (int *)calloc(n, sizeof(int));
    int *even = (int *)calloc(n, sizeof(int));
    int oi = 0, ei = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        if (a[i] % 2 == 0)
        {
            even[ei++] = a[i];
        }
        else
            odd[oi++] = a[i];
    }
    quickSort(even, 0, ei - 1);
    qsort(odd, oi, sizeof(int), cmp);
    int idx = 0;
    for (int i = 0; i < ei; i++)
        a[idx++] = even[i];
    for (int i = 0; i < oi; i++)
        a[idx++] = odd[i];

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    free(even);
    free(odd);
}