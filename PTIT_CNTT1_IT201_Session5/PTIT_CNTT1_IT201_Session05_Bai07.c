#include <stdio.h>
#include <stdlib.h>
int a[100];
int k;
int arrayFibonacci(int n)
{
    if (n > k)
        return 0;
    a[n - 1] = a[n - 2] + a[n - 3];
    return arrayFibonacci(n + 1);
}

int main()
{
    a[0] = 0;
    a[1] = 1;
    scanf("%d", &k);
    if (k <= 0)
        printf("Khong hop le");
    else if (k <= 2)
    {
        for (int i = 0; i < k; i++)
            printf("%d ", a[i]);
    }
    else
    {
        arrayFibonacci(3);
        for (int i = 0; i < k; i++)
            printf("%d ", a[i]);
    }
    return 0;
}