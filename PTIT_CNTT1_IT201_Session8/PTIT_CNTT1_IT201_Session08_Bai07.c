#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *a, int l, int r)
{
    int pivot = a[r];
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (pivot >= a[j])
        {
            swap(&a[i], &a[j]);
            ++i;
        }
    }
    swap(&a[i], &a[r]);
    return i;
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
    if (n < 1 || n > 1000)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;//time complexity:O(n log n)
}