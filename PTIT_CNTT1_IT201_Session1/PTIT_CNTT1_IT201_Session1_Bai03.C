#include <stdio.h>
#include <stdlib.h>

int *mallocArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    return arr;
} // space complexity:O(n)

int main()
{
    int k = 25;
    int *a = mallocArray(k);
    for (int i = 0; i < k; i++)
    {
        printf("%d ", *(a + i));
    }
    free(a);
}