#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter value to search: ");
    scanf("%d", &x);
    int check = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] == x)
        {
            check = 1;
            printf("%d ", i);
        }
        if (a[n - i - 1] == x && i != n - i - 1)
        {
            check = 1;
            printf("%d ", n - i - 1);
        }
    }
    if (check == 0)
        printf("Phan tu khong co trong mang.");
    return 0;
    free(a);
}