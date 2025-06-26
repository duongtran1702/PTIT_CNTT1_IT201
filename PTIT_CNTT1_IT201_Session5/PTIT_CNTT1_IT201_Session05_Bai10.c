#include <stdio.h>
#define MAX 100
int cols, rows;
int colBlock, rowBlock;

int countPathsWithBlock(int i, int j)
{
    if (i >= rows || j >= cols)
        return 0;
    if (i == rows - 1 && j == cols - 1)
        return 1;
    if (i == rowBlock - 1 && j == colBlock - 1)
        return 0;
    return countPathsWithBlock(i + 1, j) + countPathsWithBlock(i, j + 1);
}
int countPathsWithBlockDp(int rows, int cols)
{
    int dp[MAX][MAX] = {0};
    dp[0][0] = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if ( i == rowBlock-1 && j == colBlock-1)
                continue;
            if (j > 0)
                dp[i][j] += dp[i][j - 1];
            if (i > 0)
                dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[rows - 1][cols - 1];
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
    printf("Enter the position of the blocked cell (row and col):");
    scanf("%d", &rowBlock);
    scanf("%d", &colBlock);
    if (rowBlock <= 0 || rowBlock > rows || colBlock <= 0 || colBlock > cols)
    {
        printf("Invalid block position: must be inside the matrix.\n");
        return 1;
    }
    printf("Total number of valid paths with block from (0,0) to (%d,%d): %d\n", rows - 1, cols - 1, countPathsWithBlock(0, 0));
    printf("Total number of valid paths with block from (0,0) to (%d,%d): %d", rows - 1, cols - 1, countPathsWithBlockDp(rows,cols));
}