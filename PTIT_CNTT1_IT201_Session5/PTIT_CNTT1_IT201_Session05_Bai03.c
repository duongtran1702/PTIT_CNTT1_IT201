#include <stdio.h>
#include<string.h>
int factorial(int n)
{
    if (n == 1)
        return 1;
    return n*factorial(n - 1);
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(n<1){
        printf("Khong hop le!");
        return 0;
    }
    printf("Giai thua cua %d: %d",n,factorial(n));
}