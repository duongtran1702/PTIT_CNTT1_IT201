#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char tmp[100];
bool palindromeStr(int l, int r)
{
    if (l >= r)
        return true;
    if (tmp[l] != tmp[r])
    {
        return false;
    }
    return palindromeStr(l + 1, r - 1);
}

int main()
{
    printf("Nhap chuoi: ");
    fgets(tmp, 100, stdin);
    tmp[strcspn(tmp, "\n")] = '\0';
    int n = strlen(tmp);
    if (palindromeStr(0, n - 1))
    {
        printf("Palindrome valid");
    }
    else
        printf("Palindrome Invalid");
}