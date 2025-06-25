#include <stdio.h>
#include <string.h>
int sum(int first, int second)
{
    if (first == second)
        return first;
    return first + sum(first + 1, second);
}

int main()
{
    int first, second;
    printf("Nhap so thu nhat: ");
    scanf("%d", &first);
    printf("Nhap so thu hai: ");
    scanf("%d", &second);
    if (first < 1 || second <= first)
    {
        printf("Khong hop le!");
        return 0;
    }
    printf("Tong: %d", sum(first, second));
}