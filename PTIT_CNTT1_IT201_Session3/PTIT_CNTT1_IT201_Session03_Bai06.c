#include <stdio.h>
#include <stdlib.h>

void addElements(int *a, int *n)
{
    printf("Nhap so luong phan tu muon them : ");
    int m;
    scanf("%d", &m);
    if (m < 0)
    {
        printf("So luong phan tu khong hop le");
        return;
    }
    if (m == 0)
    {
        {
            for (int i = 0; i < *n; i++)
                printf("%d ", a[i]);
            return;
        }
    }
    *n += m;
    a = (int *)realloc(a, *n * sizeof(int));
    for (int i = *n - m; i < *n; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < *n; i++)
        printf("%d ", a[i]);
}
int main()
{
    int n;
    printf("Nhap so phan tu :");
    scanf("%d", &n);
    if (n < 1 || n > 1000)
    {
        printf("So luong phan tu khong hop le");
        return 0;
    }

    int *a = (int *)malloc(n * sizeof(int));
    printf("Nhap mang :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    addElements(a, &n);
    free(a);
}