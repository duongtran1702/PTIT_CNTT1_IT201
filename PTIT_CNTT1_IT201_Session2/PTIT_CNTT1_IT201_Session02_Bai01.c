#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int max=*a;
    for(int i=0;i<n;i++){
        if(max<*(a+i)) max=*(a+i);
    }
    printf("The largest element  : %d",max);
    free(a);
}