#include <stdio.h>
#define MAX 100
int cols, rows;

int countPaths(int i, int j)
{
    if (i >= rows || j >= cols)
        return 0;
    if (i == rows - 1 && j == cols - 1)
        return 1;
    return countPaths(i + 1, j) + countPaths(i, j + 1);
}

int countPathsDp(int rows,int cols){
    int dp[MAX][MAX]={0};
    dp[0][0]=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(j>0) dp[i][j]+=dp[i][j-1];
            if(i>0) dp[i][j]+=dp[i-1][j];
        }
    }
    return dp[rows-1][cols-1];

}

int main()
{
    printf("Enter the number of rows and cols :");
    scanf("%d", &rows);
    scanf("%d", &cols);
    if (rows <= 0 || cols <= 0)
    {
        printf("Invalid input: rows and cols must be positive integers.\n");
        return 1;
    }
    printf("Total number of valid paths from (0,0) to (%d,%d): %d\n", rows - 1, cols - 1, countPaths(0, 0));
    printf("Total number of valid paths from (0,0) to (%d,%d): %d", rows - 1, cols - 1, countPathsDp(rows, cols));
}