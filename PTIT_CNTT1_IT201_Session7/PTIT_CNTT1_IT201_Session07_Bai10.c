#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int value;
    int dis;
} Distance;

void swap(Distance *x, Distance *y)
{
    Distance temp = *x;
    *x = *y;
    *y = temp;
}

int partition(Distance *a, int l, int r) // Hoare
{
    int m = l + (r - l) / 2;
    int pivot = a[m].dis;
    int i = l, j = r;

    while (i <= j)
    {
        while (a[i].dis < pivot)
            i++;
        while (a[j].dis > pivot)
            j--;

        if (i <= j)
        {
            swap(&a[i], &a[j]);
            i++;
            j--;
        }
    }
    return i;
}
void quickSort(Distance *a, int l, int r)
{
    if (l >= r)
        return;

    int pi = partition(a, l, r);
    quickSort(a, l, pi - 1);
    quickSort(a, pi, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int x;
    scanf("%d", &x);
    Distance *kc = malloc(n * sizeof(Distance));
    for (int i = 0; i < n; i++)
    {
        kc[i].value = a[i];
        kc[i].dis = abs(a[i] - x);
    }

    quickSort(kc, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", kc[i].value);
    }
}