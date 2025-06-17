#include<stdio.h>
#include<stdlib.h>

int *countOccurrent(int *a, int n)
{
    int *b = (int *)calloc(100, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        ++b[a[i]];
    }
    return b;
}

int main(){
    int n,x;
    printf("Enter the number element of array :");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    printf("Enter array :");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    printf("Enter x: ");
    scanf("%d",&x);

    int *b=countOccurrent(a,n);
    printf("Number of occurrences of x :%d",b[x]);
    free(a);

}