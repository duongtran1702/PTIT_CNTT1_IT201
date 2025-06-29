#include <stdio.h>
#include <stdlib.h>

int max, min;
int n;
void findMax(int *a, int idx)
{
    if (idx >= n)
        return;

    if (a[idx] > max)
        max = a[idx];

    findMax(a, idx + 1);
}
void findMin(int *a, int idx)
{
    if (idx >= n)
        return;

    if (a[idx] < min)
        min = a[idx];

    findMin(a, idx + 1);
}

int main()
{
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    min = a[0];
    max = a[0];
    findMax(a, 1);
    findMin(a, 1);
    printf("%d,%d", min, max);
}
