#include <stdio.h>
#include <stdlib.h>

int everage(int *a, int n)
{
    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            sum += a[i];
            ++count;
        }
    }
    return sum / count;
}

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d", &n);
    if (n <= 0||n>1000)
    {
        printf("So luong phan tu khong hop le !");
        return 0;
    }
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("everage = %d", everage(a, n));

    free(a);
}