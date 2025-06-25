#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char numbers[20];
int result = 0;
int checkDigit(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
            return 0;
    }
    return 1;
}

int strToInt(int tmp)
{
    if (tmp > strlen(numbers) - 1)
        return 0;
    result = result * 10 + numbers[tmp] - '0';
    return strToInt(tmp + 1);
}
int main()
{

    printf("Enter the string of number :");
    fgets(numbers, sizeof(numbers), stdin);
    numbers[strcspn(numbers, "\n")] = '\0';
    if (checkDigit(numbers) == 0)
        printf("Input Invalid");
    else
    {
        strToInt(0);
        printf("%d", result);
    }
    return 0;
}