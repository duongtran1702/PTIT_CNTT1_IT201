#include <stdio.h>
#include <stdlib.h>
int  printMaxElement(int **a, int n, int m)
{
    int tmp=a[0][0];
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            if(tmp<a[i][j]) tmp=a[i][j];
        }
        
    }
    return tmp;
}
int  printMinElement(int **a, int n, int m)
{
    int tmp=a[0][0];
    for (int i = 0; i < n; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            if(tmp>a[i][j]) tmp=a[i][j];
        }
        
    }
    return tmp;
}


int main()
{
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    if(n<1||n>1000){
        printf("Rows invalid\n");
        return 0;
    }
    if(m<1||m>1000){
        printf("Cols invalid\n");
        return 0;
    }
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        *(a + i) = (int *)calloc(m, sizeof(int));
        for (int j = 0; j < m; j++)
        {
            scanf("%d",(*(a+i)+j));
        }
    }
    printf("max = %d\n",printMaxElement(a,n,m));
    printf("min = %d\n",printMinElement(a,n,m));
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

} 