#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int id;
    char name[30];
    int age;
} Student;
void toLowerCase(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}

int main()
{
    Student st[5];
    for (int i = 0; i < 5; i++)
    {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        st[i].id = i + 1;
        printf("Nhap ten: ");
        fgets(st[i].name, 30, stdin);
        st[i].name[strcspn(st[i].name, "\n")] = '\0';
        printf("Nhap tuoi: ");
        scanf("%d", &st[i].age);
        getchar();
    }
    char name[100];
    printf("Nhap ten muon tim: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0';
    toLowerCase(name);
    int check = 0;
    char tmpName[30];
    for (int i = 0; i < 5; i++)
    {
        strcpy(tmpName, st[i].name);
        toLowerCase(tmpName);
        if (strstr(tmpName, name) != NULL)
        {
            check = 1;
            printf("id: %d, name: \"%s\", age: %d\n", st[i].id, st[i].name, st[i].age);
        };
    }
    if (check == 0)
    {
        printf("Sinh vien nay khong ton tai.\n");
    }
    return 0;
}