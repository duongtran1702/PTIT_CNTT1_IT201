#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[30];
    int age;
} Student;

int binarySearch(Student *st, int n, int id)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (st[m].id == id)
            return m;
        else if (st[m].id < id)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int tmp(const void *a, const void *b)
{
    Student *x=(Student *)a;
    Student *y=(Student *)b;
    return (*x).id - (*y).id;
}
int main()
{
    Student st[] = {
        {3, "Charlie", 22},
        {2, "Bob", 21},
        {1, "Alice", 20},
        {5, "Eva", 23},
        {4, "David", 20},
    };

    int n = sizeof(st) / sizeof(Student);
    qsort(st, n, sizeof(Student), tmp);
    int id;
    printf("Enter id:");
    scanf("%d", &id);
    int tmp = binarySearch(st, n, id);
    if (tmp > -1)
    {
        printf("id: %d, name: \"%s\", age: %d", st[tmp].id, st[tmp].name, st[tmp].age);
    }
    else
        printf("Sinh vien khong ton tai");
}