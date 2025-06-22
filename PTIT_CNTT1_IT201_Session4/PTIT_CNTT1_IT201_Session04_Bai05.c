#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y)
        return -1;
    if (x > y)
        return 1;
    return 0;
}
int binarySearch(int *a, int n, int x)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (a[m] == x)
            return m;
        else if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main()
{
    int n;
    printf("Nhap so phan tu :");
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int x;
    printf("Nhap phan tu muon tim vi tri :");
    scanf("%d", &x);
    qsort(a,n,sizeof(int),cmp);
    int tmp = binarySearch(a,n,x);
    if (tmp > -1)
    {
        printf("Phan tu co trong mang");
    }
    else
        printf("Phan tu khong co trong mang");
    free(a);
}