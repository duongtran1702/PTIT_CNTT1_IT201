#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void isPermutation(char *s, char *s2)
{
    int len = strlen(s);
    int len2 = strlen(s2);
    if (len != len2)
    {
        printf("false");
        return;
    }
    int count[300] = {0};
    for (int i = 0; i < len; i++)
    {
        ++count[s[i]];
        --count[s2[i]];
    }
    for (int i = 0; i < 300; i++)
    {

        if (count[i] != 0)
        {
            printf("false");
            return;
        }
    }
    printf("true");
}

int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}
int main()
{
    char s[] = "hello";
    char s2[] = "ehlol";
    isPermutation(s, s2);
    printf("\n");
    int len = strlen(s);
    int len2 = strlen(s2);
    
// Cach 1 : time complexity : O(n)
//          space complexity:O(1)
// Cach 2 : time complexity : O(n log n)
//          space complexity:O(1)