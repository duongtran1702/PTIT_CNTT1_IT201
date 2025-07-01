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

    for (int i = 0; i < n; i++)
    {
        int tmp = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[tmp] > a[j])
            {
                tmp = j;
            }
        }
        wrap(&a[i], &a[tmp]);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;//time complexity:O n^2
}