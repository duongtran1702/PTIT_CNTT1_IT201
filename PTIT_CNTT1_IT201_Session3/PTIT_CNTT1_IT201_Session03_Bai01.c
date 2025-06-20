#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d", &n);
    if (n == 0)
    {
        printf("So luong phan tu phai lon hon 0");
        return 0;
    }
    else if (n < 0)
    {
        printf("So luong phan tu khong duoc am");
        return 0;
    }
    else if(n>1000){
        printf("So luong phan tu khong hop le");
        return 0;
    }
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("So thu %d = %d\n", i + 1, a[i]);
    }
    free(a);
}