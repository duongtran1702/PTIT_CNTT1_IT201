#include<stdio.h>

void printDouble(int n)
{
    int i = 1;
    while (i < n)
    {
        printf("%d ",i);
        i *= 2;
    }
}
int main()
{
    int n = 65;
    printDouble(n);
}
//time complexity:O(log n)

