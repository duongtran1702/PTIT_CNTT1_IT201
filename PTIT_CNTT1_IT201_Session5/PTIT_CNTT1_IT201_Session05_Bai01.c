#include <stdio.h>

int printNumber(int tmp, int n)
{
    if (tmp > n)
    {
        return n;
    }
    printf("%d ", tmp);
    return printNumber(tmp + 1, n);
}

int main()
{
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    printNumber(1, n);
}