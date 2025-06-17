#include <stdio.h>
#include <stdlib.h>

int *countOccurrent(int *a, int n)
{
    int *b = (int *)calloc(100, sizeof(int)); // space complexity:O(1)
    for (int i = 0; i < n; i++)               // time complexity:O(n)
    {
        ++b[a[i]];
    }
    return b;
}
int main()
{

    int n;
    printf("Enter the number element of array :");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int *b = countOccurrent(a, n);
    for (int i = 0; i < 100; i++)
    {
        if (b[i] != 0)
        {
            printf("Phan tu %d xuat hien %d lan\n", i, b[i]);
        }
    }
}