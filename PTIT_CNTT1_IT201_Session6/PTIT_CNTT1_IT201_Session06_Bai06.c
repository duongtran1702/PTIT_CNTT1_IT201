#include <stdio.h>
#include <stdlib.h>

int stairWays(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return stairWays(n - 1) + stairWays(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", stairWays(n));
}
