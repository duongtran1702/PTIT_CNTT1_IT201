#include <stdio.h>
#include <stdlib.h>

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

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;//time complexity:O n^2
}