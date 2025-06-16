#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort(int *a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(*(a+j)>*(a+j+1)){
                swap((a+j),(a+j+1));
            }
        }
    }//time complexity:O(n^2)
}

int main(){
    int a[]={2,5,1,9,4,0,2};
    int k=sizeof(a)/4;
    sort(a,k);
    for(int i=0;i<k;i++){
        printf("%d ",a[i]);
    }
}