#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **data;
    int top;
    int capacity;
} Stack;

Stack *init(int capacity)
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = -1;
    st->capacity = capacity;
    st->data = (char **)malloc(sizeof(char *) * capacity);
    return st;
}

int isEmpty(Stack *st)
{
    return st->top == -1;
}

char *copy(char *s)
{
    char *tmp = malloc(strlen(s) + 1);
    strcpy(tmp, s);
    return tmp;
}
void push(Stack *st, char *value)
{
    if (st->top + 1 >= st->capacity)
    {
        printf("Stack overflow!\n");
        return;
    }
    st->data[++st->top] = copy(value);
}

char *top(Stack *st)
{
    if (isEmpty(st))
    {
        printf("stack underflow!\n");
        return NULL;
    }
    return st->data[st->top];
}

void pop(Stack *st)
{
    if (isEmpty(st))
    {
        printf("stack underflow!\n");
        return;
    }
    free(st->data[st->top--]);
}

void infix(char *s)
{
    Stack *st = init(100);
    size_t len = strlen(s);
    char tmp[100];
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            char operand[2] = {s[i], '\0'};
            push(st, operand);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            char *right = copy(top(st));
            pop(st);
            char *left = copy(top(st));
            pop(st);
            sprintf(tmp, "(%s%c%s)", left, s[i], right);
            push(st, tmp);
            free(left);
            free(right);
        }
    }
    printf("%s\n", top(st));
}

int main()
{
    char str[100];
    // printf("Enter postfix expression: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    infix(str);
    return 0;
}
