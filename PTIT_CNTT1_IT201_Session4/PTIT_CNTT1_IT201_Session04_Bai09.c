#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int binarySearchRecursive(int *a, int l, int r, int x)
{
    if (l > r)
        return -1;
    int m = (l + r) / 2;
    if (a[m] == x)
        return m;
    else if (a[m] < x)
        return binarySearchRecursive(a, m + 1, r, x);
    else
        return binarySearchRecursive(a, l, m - 1, x);
}

int main()
{
    int n;
    printf("Nhap so phan tu :");
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int x;
    printf("Nhap phan tu muon tim: ");
    scanf("%d", &x);
    qsort(a, n, sizeof(int), cmp);
    int index = binarySearchRecursive(a,0,n-1, x);
    if (index > -1)
    {
        printf("Phan tu co trong mang");
    }
    else
        printf("Phan tu khong co trong mang");
    free(a);
}