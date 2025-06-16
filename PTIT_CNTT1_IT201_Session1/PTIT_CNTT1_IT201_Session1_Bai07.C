#include <stdio.h>
#include <stdlib.h>

int *countOccurrent(int *a, int n)
{
    int *b = (int *)calloc(1000, sizeof(int)); // space complexity:O(1)
    for (int i = 0; i < n; i++)               // time complexity:O(n)
    {
        ++b[a[i]];
    }
    return b;
}
int main()
{
     int a[] = {5, 5, 6, 8, 0, 0, 5, 2, 7, 4, 3, 9, 9};
    int n = sizeof(a) / sizeof(int);

    int check1 = 0;
    int *b = countOccurrent(a, n);
    // Cach 1:
    for (int i = 0; i < 1000; i++)
    {
        if (b[i] > 1)
        {
            printf("Duplicate element\n");
            check1 = 1;
            break;
        }
    }
    if (check1 == 0)
        printf("No duplicate element\n");
    // Cach 2:
    int check2=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] == a[i])
            {
                printf("Duplicate element\n");
                check2 = 1;
                break;
            }
        }
        if(check2) break;
    }//time complexity:O(n^2)
    //sapce complexity:O(1)
    if (check2 == 0)
        printf("No duplicate element\n");
}