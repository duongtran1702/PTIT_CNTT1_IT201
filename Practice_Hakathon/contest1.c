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

typedef struct DoublyNode
{
    Subject sub;
    struct DoublyNode *next;
    struct DoublyNode *prev;
} DoublyNode;

typedef struct
{
    Node *top;
} Stack;

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
Stack *initStack()
{
    Stack *st = (Stack *)malloc(sizeof(Stack));
    st->top = NULL;
    return st;
}
void pushStack(Stack *st, Subject sub)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->sub = sub;

    newNode->next = st->top;
    st->top = newNode;
}
int emptyStack(Stack *st)
{
    return st->top == NULL;
}

void popStack(Stack *st)
{
    if (emptyStack(st))
    {
        printf("Stack underFlow!\n");
        return;
    }
    Node *tmp = st->top;
    st->top = tmp->next;
    free(tmp);
}

Subject topStack(Stack *st)
{
    Subject empty = {"", "", -1};
    if (emptyStack(st))
    {
        printf("Stack is empty!\n");
        return empty;
    }
    return st->top->sub;
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
void undoAddSubject(Node **head, Stack *st)
{
    popStack(st);
    Subject tmpSub = topStack(st);
    Node *tmp = *head;
    if (strcmp(tmp->sub.subjectCode, tmpSub.subjectCode) == 0 && tmp->next == NULL)
    {
        *head = NULL;
    }
    else
    {
        while (tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        if (strcmp(tmp->next->sub.subjectCode, tmpSub.subjectCode) == 0)
        {
            tmp->next = NULL;
        }
    }
    printf("Undo successfully!\n");
}

void addSubject(Node **head, Stack *st)
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
    pushStack(st, newSub->sub);
}

Subject searchSubByCode(Node *head)
{
    char code[30];
    printf("Enter the subject code to search: ");
    fgets(code, 30, stdin);
    code[strcspn(code, "\n")] = '\0';
    Node *tmp = head;
    while (tmp != NULL)
    {
        if (strcmp(tmp->sub.subjectCode, code) == 0)
        {
            return tmp->sub;
        }
        tmp = tmp->next;
    }
    Subject empty = {"", "", -1};
    return empty;
}

void menu()
{
    printf("1. Add new subject to list.\n");
    printf("2. Search subject by code.\n");
    printf("3. Arrange by name (A-Z).\n");
    printf("4. Calculate total credit of the list.\n");
    printf("5. Move the subject to the completed list.\n");
    printf("6. Undo add subject.\n");
    printf("7. Manage student waiting for register subject.\n");
    printf("0. Exit.\n");
}

void sortListByName(Node *head)
{
    if (head == NULL || head->next == NULL)
        return;
    else
    {
        int isSorted;
        for (Node *i = head; i->next != NULL; i = i->next)
        {
            isSorted = 1;
            for (Node *j = head; j->next != NULL; j = j->next)
            {
                if (strcmp(j->sub.subjectName, j->next->sub.subjectName) > 0)
                {
                    Subject tmp = j->sub;
                    j->sub = j->next->sub;
                    j->next->sub = tmp;
                    isSorted = 0;
                }
            }
            if (isSorted == 1)
                break;
        }
    }
    printf("Arranging by name is successfull\n");
}

int sumCreditOfList(Node *head)
{
    int sum = 0;
    while (head != NULL)
    {
        sum += head->sub.credit;
        head = head->next;
    }
    return sum;
}

void displayList(Node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("Sub %d:\nSubject code: %s\n", i, head->sub.subjectCode);
        printf("Subject name: %s\n", head->sub.subjectName);
        printf("Subject credit: %d\n", head->sub.credit);
        i++;
        head = head->next;
    }
}
DoublyNode *createDoubNode(Subject sub)
{
    DoublyNode *newNode = (DoublyNode *)malloc(sizeof(DoublyNode));
    newNode->sub = sub;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void moveToCompleted(Node **head, DoublyNode **dhead)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    char code[30];
    printf("Enter the subject code to move: ");
    fgets(code, 30, stdin);
    code[strcspn(code, "\n")] = '\0';
    Subject subTmp = {"", "", -1};
    Node *tmp = *head;
    if (strcmp(tmp->sub.subjectCode, code) == 0)
    {
        subTmp = tmp->sub;
        *head = tmp->next;
        free(tmp);
    }
    else
    {
        while (tmp != NULL)
        {
            if (tmp->next != NULL && strcmp(tmp->next->sub.subjectCode, code) == 0)
            {
                Node *tmp1 = tmp->next;
                tmp->next = tmp1->next;
                subTmp = tmp1->sub;
                free(tmp1);
                break;
            }
            tmp = tmp->next;
        }
    }
    if (subTmp.credit == -1)
    {
        printf("Subject does not exist!\n");
        return;
    }
    DoublyNode *tmpDoubHead = *dhead;
    DoublyNode *newNode = createDoubNode(subTmp);
    if (tmpDoubHead == NULL)
    {
        tmpDoubHead = newNode;
        *dhead = newNode;
    }
    else
    {
        newNode->next = tmpDoubHead;
        tmpDoubHead->prev = newNode;
        *dhead = newNode;
    }
}
typedef struct
{
    char name[30];
    char id[15];
} Student;
typedef struct Node2
{
    Student student;
    struct Node2 *next;
} Node2;
typedef struct
{
    Node2 *front;
    Node2 *back;
} Queue;

Student addStudent()
{
    Student student;

    printf("Enter the name student: ");
    fgets(student.name, 30, stdin);
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter the id of student: ");
    fgets(student.id, 15, stdin);
    student.id[strcspn(student.id, "\n")] = '\0';

    return student;
}

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->back = q->front = NULL;
    return q;
}
int emptyQueue(Queue *q)
{
    return q->front == NULL;
}
void pushQueue(Queue *q, Student student)
{
    Node2 *newNode = (Node2 *)malloc(sizeof(Node2));
    newNode->student = student;
    newNode->next = NULL;

    if (q->back == NULL)
        q->front = q->back = newNode;
    else
    {
        q->back->next = newNode;
        q->back = newNode;
    }
}

Student front(Queue *q)
{
    if (emptyQueue(q))
    {
        printf("Queue is empty!\n");
        Student empty = {"", ""};
        return empty;
    }
    return q->front->student;
}

void serveStudent(Queue *q)
{
    Student servedStudent = front(q);
    if (strcmp(servedStudent.name, "") == 0)
    {
        return;
    }
    Node2 *tmp = q->front;
    q->front = tmp->next;
    if (q->front == NULL)
        q->back = NULL;
    free(tmp);
    printf("Served student: %s\nID: %s\n", servedStudent.name, servedStudent.id);
}

void displayQueue(Queue *q)
{
    if (emptyQueue(q))
    {
        printf("Queue is empty!\n");
        return;
    }
    Node2 *tmp = q->front;
    int i = 1;
    printf("Waiting list:\n");
    while (tmp != NULL)
    {
        printf("Student %d:\nName: %s\nID: %s\n\n", i, tmp->student.name, tmp->student.id);
        tmp = tmp->next;
        i++;
    }
}
void freeSubjectList(Node *head)
{
    Node *tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}
void freeCompletedList(DoublyNode *dhead)
{
    DoublyNode *tmp;
    while (dhead != NULL)
    {
        tmp = dhead;
        dhead = dhead->next;
        free(tmp);
    }
}
void freeStack(Stack *st)
{
    while (!emptyStack(st))
    {
        popStack(st);
    }
    free(st);
}
void freeQueue(Queue *q)
{
    Node2 *tmp;
    while (q->front != NULL)
    {
        tmp = q->front;
        q->front = q->front->next;
        free(tmp);
    }
    free(q);
}
int main()
{
    Node *head = NULL;
    DoublyNode *dhead = NULL;
    Stack *st = initStack();
    Queue *q = initQueue();
    int choice;
    do
    {
        menu();
        printf("Please enter the choice: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter the number!\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();
        if (choice == 1)
        {
            addSubject(&head, st);
        }
        else if (choice == 2)
        {
            Subject tmp = searchSubByCode(head);
            if (tmp.credit != -1)
            {
                printf("Subject code: %s\n", tmp.subjectCode);
                printf("Subject name: %s\n", tmp.subjectName);
                printf("Subject credit: %d\n", tmp.credit);
            }
            else
                printf("Subject code does not exist!\n");
        }
        else if (choice == 3)
        {
            sortListByName(head);
            displayList(head);
        }
        else if (choice == 4)
        {
            printf("Total credit of the list: %d", sumCreditOfList(head));
        }
        else if (choice == 5)
        {
            moveToCompleted(&head, &dhead);
        }
        else if (choice == 6)
        {
            undoAddSubject(&head, st);
        }
        else if (choice == 7)
        {
            char option;
            do
            {
                printf("a. Add student to waiting list.\n");
                printf("b. Serve student from waiting list.\n");
                printf("c. Display waiting list.\n");
                printf("d. Exit waiting list management.\n");

                printf("Please enter the option: ");
                scanf(" %c", &option);
                getchar();

                if (option == 'a')
                {
                    Student student = addStudent();
                    pushQueue(q, student);
                }
                else if (option == 'b')
                {
                    serveStudent(q);
                }
                else if (option == 'c')
                {
                    displayQueue(q);
                }
                else
                {
                    printf("Invalid option!\n");
                }
            } while (option != 'd');
        }
        else if (choice == 0)
        {
            printf("Exiting...\n");
            freeSubjectList(head);
            freeCompletedList(dhead);
            freeStack(st);
            freeQueue(q);
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);
    return 0;
}
