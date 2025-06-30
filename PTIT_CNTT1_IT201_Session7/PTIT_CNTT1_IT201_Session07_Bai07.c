#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    int neg[MAX], zezo[MAX], pos[MAX];
    int ni = 0, zi = 0, pi = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            neg[ni++] = a[i];
        else if (a[i] > 0)
            pos[pi++] = a[i];
        else
            zezo[zi++] = a[i];
    }

    int idx = 0;
    for (int i = 0; i < ni; i++)
        a[idx++] = neg[ni - i - 1];
    for (int i = 0; i < zi; i++)
        a[idx++] = zezo[zi - i - 1];
    for (int i = 0; i < pi; i++)
        a[idx++] = pos[pi - 1 - i];

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    free(a);
    return 0;
}