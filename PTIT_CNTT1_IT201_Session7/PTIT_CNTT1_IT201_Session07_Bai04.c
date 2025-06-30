#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (str[j] > str[j + 1])
            {
                swapped = 1;
                swap(&str[j + 1], &str[j]);
            }
        }
        if (swapped == 0)
            break;
    }
}

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    bubbleSort(str);
    printf("%s", str);
    return 0;
}