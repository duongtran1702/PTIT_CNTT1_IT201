#include <stdio.h>
#include <stdlib.h>

// int cmp(const void *a, const void *b)
// {
//     int x = *(int *)a;
//     int y = *(int *)b;
//     if (x < y)
//         return -1;
//     if (x > y)
//         return 1;
//     return 0;
// }
// int binarySearchFirstOccurrence(int *a, int n, int x)
// {
//     int l = 0;
//     int r = n - 1;
//     int res = -1;
//     while (l <= r)
//     {
//         int m = (l + r) / 2;
//         if (a[m] == x)
//         {
//             res = m;
//             r = m - 1;
//         }
//         else if (a[m] < x)
//             l = m + 1;
//         else
//             r = m - 1;
//     }
//     return res;
// }
int main()
{
    int n;
    printf("Nhap so phan tu :");
    scanf("%d", &n);
    if(n<=0) {
        printf("So luong phan tu khong hop le !");
        return 0;
    }
    int *a = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int x=a[0];
    for(int i=1;i<n;i++){
        if(x>a[i]) x=a[i];
    }
    int tmp=-1;
    for(int i=0;i<n;i++){
        if(a[i]==x){
            tmp=i;
            break;
        }
    }
    if(tmp>-1){
        printf("%d",tmp);
    }
    else printf("Khong tim thay phan tu ");
    free(a);

}