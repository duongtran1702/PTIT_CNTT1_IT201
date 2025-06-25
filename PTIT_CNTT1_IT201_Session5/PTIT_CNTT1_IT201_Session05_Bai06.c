#include <stdio.h>
#include <stdlib.h>
int sumArray(int n, int *a)
{
    if (n == 0)
        return 0;
    return a[n-1]+sumArray(n-1,a);
}

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    printf("%d",sumArray(n,a));
    free(a);
}
