#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the number of array: ");
    scanf("%d", &n);
    int *a = (int *)calloc(n, sizeof(int));
    printf("Enter array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
    }
    int check=0;
    for(int i=0;i<n/2;i++){
        if(a[i]==a[n-i-1]){
            check=1;
            printf("Symmetric pair: (%d,%d)\n",a[i],a[n-i-1]);
        }
    }
    if(check==0) printf("There is no symmetric pair.");
    free(a);
}