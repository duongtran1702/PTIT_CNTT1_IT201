#include <stdio.h>
#include <stdlib.h>
void wrap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n < 1 || n > 1000)
    {
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }
    int *a = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < n - 1; i++)
    {
        int isWrapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                isWrapped = 1;
                wrap(&a[j], &a[j + 1]);
            }
        }
        if (isWrapped == 0)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}