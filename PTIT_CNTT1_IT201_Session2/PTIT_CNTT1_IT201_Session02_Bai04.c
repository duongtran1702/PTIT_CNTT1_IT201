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
    printf("Enter position :");
    int pos;
    scanf("%d", &pos);
    printf("Enter the value :");
    int value;
    scanf("%d", &value);
    *(a + pos - 1) = value;
    printf("Array after editing :");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    free(a);
}