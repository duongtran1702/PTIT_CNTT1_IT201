#include <stdio.h>
#include <stdlib.h>

int k;
void fibonacci(int fib1, int fib2, int count)
{
    if (count > k)
        return;
    printf("%d ",fib1);
    fibonacci(fib2, fib1 + fib2, count + 1);
}

int main()
{

    printf("Enter k: ");
    scanf("%d", &k);
    if (k <= 0)
        printf("Khong hop le");
    else
    {
        fibonacci(1, 1, 1);
    }
    return 0;
}