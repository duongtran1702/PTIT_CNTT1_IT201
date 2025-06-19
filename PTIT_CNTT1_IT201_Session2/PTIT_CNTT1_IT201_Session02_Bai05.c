#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    int pos;
    printf("Enter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position.\n");
        free(a);
        return 1;
    }

    
    for (int i = pos - 1; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--; 

    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", a[i]);
    }

    printf("\n");
    free(a);
    return 0;
}
