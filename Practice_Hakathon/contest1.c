#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    char subjectCode[15];
    char subjectName[30];
    int credit;
} Subject;

typedef struct Node
{
    Subject sub;
    struct Node *next;
} Node;

int equalsIgnorecase(const char *s1, const char *s2)
{
    while (*s1 && *s2)
    {
        if (tolower(*s1) != tolower(*s2))
            return 0;
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int checkDupplicate(Node **head, const char *s)
{
    Node *cur = *head;
    int dup = 1;
    while (cur != NULL)
    {
        if (equalsIgnorecase(cur->sub.subjectCode, s))
            return 1;
        cur = cur->next;
    }
    return 0;
}

void addSubject(Node **head)
{
    Node *newSub = (Node *)malloc(sizeof(Node));
    newSub->next = NULL;
    char code[15];
    do
    {
        printf("Enter the code subject: ");
        fgets(code, 15, stdin);
        code[strcspn(code, "\n")] = '\0';
    } while (checkDupplicate(head, code));
    strcpy(newSub->sub.subjectCode, code);

    printf("Enter subject name: ");
    fgets(newSub->sub.subjectName, sizeof(newSub->sub.subjectName), stdin);
    newSub->sub.subjectName[strcspn(newSub->sub.subjectName, "\n")] = '\0';

    printf("Enter number of credits: ");
    scanf("%d", &newSub->sub.credit);
    getchar();

    if (*head == NULL)
    {
        *head = newSub;
    }
    else
    {
        Node *cur = *head;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        cur->next = newSub;
    }
}

void menu()
{
    printf("1. Add new subject to list.\n");
    printf("2. Search subject by code.\n");
    printf("0. Exit");
}

int main()
{
    Node *head = NULL;
    addSubject(&head);
}