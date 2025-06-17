#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    printf("Enter array :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int b[100],count=0;
    int maxRight=a[n-1];
    b[count++]=maxRight;

    for(int i=n-2;i>=0;--i){
        if(a[i]>maxRight){
            maxRight=a[i];
            b[count++]=maxRight;
        }
    }

    printf("Output : ");
    for(int i=count-1;i>=0;--i) printf("%d ",b[i]);
    

    free(a);
    return 0;
}
