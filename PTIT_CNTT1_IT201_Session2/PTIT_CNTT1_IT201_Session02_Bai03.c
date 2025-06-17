#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

int main(){
    int n;
    printf("Enter the number elements of array :");
    scanf("%d",&n);
    int *a=(int*)malloc(n*sizeof(int));
    printf("Enter array :");
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(int i=0;i<n/2;i++){
        swap(a+i,a+n-1-i);
    }
    printf("Reverse array :");
    for(int i=0;i<n;i++){
        printf("%2d",a[i]);
    }
    free(a);
}