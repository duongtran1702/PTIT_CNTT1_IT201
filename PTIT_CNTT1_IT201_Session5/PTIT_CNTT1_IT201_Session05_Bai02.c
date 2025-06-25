#include <stdio.h>
#include<string.h>
int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int main()
{
    char tmp[100];
    printf("Nhap chuoi: ");
    fgets(tmp, 100, stdin);
    tmp[strcspn(tmp, "\n")] = '0';
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    if(n<1){
        printf("Khong hop le!");
        return 0;
    }
    printf("Tong: %d",sum(n));
}