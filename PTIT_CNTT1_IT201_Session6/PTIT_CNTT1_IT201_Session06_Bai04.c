#include <stdio.h>

void moveDisks(int n, char from, char to, char tmp)
{
    if (n == 1)
    {
        printf("Di chuyen dia 1 tu %c sang %c\n", from, to);
        return;
    }
    moveDisks(n - 1, from, tmp, to);
    printf("Di chuyen dia %d tu %c sang %c\n", n, from, to);
    moveDisks(n - 1, tmp, to, from);
}
int main()
{

    printf("Nhap so dia: ");
    int n;
    scanf("%d",&n);
    moveDisks(n,'A','C','B');
}
