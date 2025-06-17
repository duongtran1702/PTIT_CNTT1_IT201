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
    printf("Enter position to add :");
    int pos;
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("Invalid position!\n");
        free(a);
        return 1;
    }
    int value;
    printf("Enter value :");
    scanf("%d", &value);

    ++n;
    int *temp = realloc(a, n * sizeof(int));
    if (temp != NULL)
        a = temp;

    for (int i = n - 1; i > pos - 1; --i)
    {
        a[i] = a[i - 1];
    }
    *(a + pos - 1) = value;
    printf("Array after adding element :");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    free(a);
    return 0;
}