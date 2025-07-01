#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int linearSearch(int *a, int n, int x)
{
    int tmp = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return tmp;
}
int binarySearch(int *a, int l, int r, int x)
{
    if (l > r)
        return -1;
    int m = l + (r - l) / 2;
    if (a[m] == x)
        return m;
    else if (a[m] < x)
        return binarySearch(a, m + 1, r, x);
    else
        return binarySearch(a, l, m - 1, x);
}
int main()
{
    printf("Nhap n: ");
    int n;
    scanf("%d", &n); // nhap n
    if (n < 1 || n > 1000)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    // nhap mang
    printf("Nhap mang: ");
    int *a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    // Nhap x
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    // in
    printf("Mang truoc sap xep: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    // Sap xep
    insertionSort(a, n);
    printf("Mang sau sap xep: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    printf("%d %d", linearSearch(a, n, x), binarySearch(a, 0, n - 1, x));
    free(a);
    return 0;
}