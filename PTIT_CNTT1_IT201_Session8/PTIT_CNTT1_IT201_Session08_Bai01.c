#include <stdio.h>
#include <stdlib.h>
int main()
{

    int n;
    scanf("%d", &n);
    if(n<1||n>1000){
        printf("So luong phan tu khong hop le!\n");
        return 0;
    }
    int *a = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    int x;
    scanf("%d", &x);
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        printf("Khong ton tai phan tu");
    else
        printf("Vi tri: %d", pos + 1);
    free(a);
    return 0;
    //time complexity:O n
}