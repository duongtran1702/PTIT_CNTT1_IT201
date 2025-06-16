#include<stdio.h>

int main(){
    int n=10;
    int sum1=0,sum2=0;
    for(int i=0;i<=n;i++){
        sum1+=i;
    }//time complexity:O(n)
    //space complexity:O(1)
    
    sum2=n*(n+1)/2;
    //time complexity:O(1)
    //space complexity:O(1)
    printf("Cach 1: %d\n",sum1);
    printf("Cach 2: %d ",sum2);

}