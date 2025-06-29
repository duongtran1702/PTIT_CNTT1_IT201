#include <stdio.h>

void integerToBinary(int n)
{
    if (n == 0)
        return;
    integerToBinary(n / 2);
    printf("%d", n % 2);
}

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("0");
        return 0;
    }

    integerToBinary(n);

    return 0;
}