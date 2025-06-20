#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the number elements of array :");
    scanf("%d",&n);
    if(n<=0||n>1000){
        printf("So luong phan tu khong hop le !");
        return 0;
    }
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    int max=*a;
    for(int i=0;i<n;i++){
        if(max<*(a+i)) max=*(a+i);
    }
    printf("Max = %d",max);
    free(a);
}