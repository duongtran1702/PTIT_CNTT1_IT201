#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int sum;
    printf("Enter target sum :");
    scanf("%d", &sum);

    int b[100] = {0};
    int c[100] = {0};

    int check = 0;

    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int temp = sum - x;
        if (temp >= 0 && b[temp] > 0)
        {
            check = 1;
            printf("Found pair: %d,%d\n", x, temp);
        }
        else if (temp < 0 && c[-temp] > 0)
        {
            check = 1;
            printf("Found pair: %d,%d\n", x, temp);
        }

        if (x >= 0)
            ++b[x];
        else
            ++c[-x];
    }
    if (check == 0)
        printf("There is no satisfying pair!");
    free(a);
    return 0;
}
