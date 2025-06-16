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
    int count = 0;
    int a[] = {5, 5, 6, 8, 0, 0, 5, 2, 7, 4, 3, 9, 9};
    int n = sizeof(a) / sizeof(int);
    int *b = countOccurrent(a, n);
    for (int i = 0; i < 100; i++) // time complexity:O(n)
    {
        if (b[i]>count)
        {
            count = b[i];
        }
    }
    for (int i = 0; i < 100; i++) // time complexity:O(n)
    {
        if (b[i] == count)
        {
            printf("%d ", i);
        }
    }
}