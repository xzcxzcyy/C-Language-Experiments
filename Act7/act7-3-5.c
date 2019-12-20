/*
 * 成绩单
 * 选择排序
 * 交换指针域
 */

#include <stdio.h>
#include <stdlib.h>

#define LSIZE sizeof(struct List)

typedef char *String;

struct Student
{
    long long id;
    String name;
    int english;
    int calculus;
    int physics;
    int CLanguage;
    int total;
    double average;
};

struct List
{
    struct Student data;
    struct List *next;
};

struct List *input();
void output(const struct List *head);
int modify(struct List *head);
void makeAverage(struct List *head);
void outputAverage(const struct List *head);
int menu();
void mSort(struct List **p);
void mSwap(struct List *pre1, struct List *p1, struct List *pre2, struct List *p2);
int smaller(const struct List *p1, const struct List *p2);

void testSwap()
{
    struct List *L[4];
    for (int i = 0; i < 4; ++i)
    {
        L[i] = malloc(LSIZE);
        L[i]->data.id = i;
    }
    for (int i = 0; i < 3; ++i)
    {
        L[i]->next = L[i + 1];
    }
    L[3]->next = NULL;
    struct List *p = L[0];
    mSwap(NULL, L[0], L[1], L[2]);
    while (p != NULL)
    {
        printf("%lld ", p->data.id);
        p = p->next;
    }
}

int main()
{
    setbuf(stdout, NULL);
    int cmd;
    struct List *list = NULL;
    while ((cmd = menu()))
    {
        switch (cmd)
        {
            case 1:
                list = input();
                makeAverage(list);
                mSort(&list);
                break;

            case 2:
                output(list);
                break;

            case 3:
                while (!modify(list));
                makeAverage(list);
                mSort(&list);
                break;

            case 4:
                outputAverage(list);
                break;
        }
    }
    return 0;
}

struct List *input()
{
    system("cls");
    int n;
    puts("Please input the number of students.");
    scanf("%d", &n);
    struct List *head, *current;
    head = current = malloc(LSIZE);
    for (int i = 0; i < n; ++i)
    {
        printf("Please input id and name: ");
        current->data.name = malloc(20 * sizeof(char));
        scanf("%lld %s", &current->data.id, current->data.name);
        printf("Please input scores in order of English, Calculus, Physics, C Programming Language:");
        scanf("%d %d %d %d", &current->data.english, &current->data.calculus,
              &current->data.physics, &current->data.CLanguage);
        if (i != n - 1)
        {
            current->next = malloc(LSIZE);
            current = current->next;
        }
        else
        {
            current->next = NULL;
        }
    }
    return head;
}

void output(const struct List *head)
{
    system("cls");
    while (head != NULL)
    {
        printf("#%lld\t%s\n", head->data.id, head->data.name);
        printf("English:\t%d\nCalculus:\t%d\nPhysics:\t%d\nC Programming Language:\t%d\n", head->data.english,
               head->data.calculus, head->data.physics, head->data.CLanguage);
        putchar('\n');
        head = head->next;
    }
    system("pause");
}

int modify(struct List *head)
{
    system("cls");
    int success = 0;
    puts("Please input the ID");
    long long id;
    scanf("%lld", &id);
    while (head != NULL)
    {
        if (head->data.id == id)
        {
            success = 1;
            break;
        }
        head = head->next;
    }
    if (success)
    {
        puts("What do you want to modify?");
        puts("1.ID\n2.Name\n3.English\n4.Calculus\n5.Physics\n6.C Programming Language");
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
            case 1:
                puts("Please enter the new ID");
                scanf("%lld", &head->data.id);
                break;

            case 2:
                puts("Please enter the new NAME");
                scanf("%s", head->data.name);
                break;

            case 3:
                puts("Please enter the new English score");
                scanf("%d", &head->data.english);
                break;

            case 4:
                puts("Please enter the new Calculus score");
                scanf("%d", &head->data.calculus);
                break;

            case 5:
                puts("Please enter the new Physics score");
                scanf("%d", &head->data.physics);
                break;

            case 6:
                puts("Please enter the new C Programming Language score");
                scanf("%d", &head->data.CLanguage);
                break;

            default:
                puts("Unknown code!");
                break;
        }
        return 1;
    }
    else
    {
        puts("ID not found!");
        system("pause");
        return 0;
    }
}

void makeAverage(struct List *head)
{
    while (head != NULL)
    {
        head->data.total = head->data.english + head->data.calculus + head->data.physics + head->data.CLanguage;
        head->data.average = head->data.total / 4.0;
        head = head->next;
    }
}

void outputAverage(const struct List *head)
{
    system("cls");
    while (head != NULL)
    {
        printf("#%lld\t%s\n", head->data.id, head->data.name);
        printf("Total Score:\t%d\nAverage Score:\t%.2lf\n", head->data.total, head->data.average);
        putchar('\n');
        head = head->next;
    }
    system("pause");
}

int menu()
{
    system("cls");
    puts("====================MENU====================");
    puts("\n0.Quit\n1.Input\n2.List\n3.Modify\n4.Show total and average scores.\n");
    puts("============================================\n");
    int cmd;
    do
    {
        scanf("%d", &cmd);
    } while (cmd < 0 || cmd > 4);
    return cmd;
}

void mSort(struct List **p)
{
    struct List *x = *p, *y = *p, *px = NULL, *py = NULL;
    for (; x != NULL; px = x, x = x->next)
    {
        for (py = x, y = x->next; y != NULL; py = y, y = y->next)
        {
            if (smaller(y, x))
            {
                mSwap(px, x, py, y);
                struct List *t;
                t = x;
                x = y;
                y = t;
                if (px == NULL)
                {
                    *p = x;
                }
            }
        }
    }
}

void mSwap(struct List *pre1, struct List *p1, struct List *pre2, struct List *p2)
{
    struct List *post1 = p1->next, *post2 = p2->next;

    if (p1 == p2)
    {
        return;
    }

    if (post1 == p2)
    {
        if (pre1 != NULL)
        {
            pre1->next = p2;
        }
        p2->next = p1;
        p1->next = post2;
        return;
    }

    if (post2 == p1)
    {
        if (pre2 != NULL)
        {
            pre2->next = p1;
        }
        p1->next = p2;
        p2->next = post1;
        return;
    }

    p2->next = post1;
    p1->next = post2;
    if (pre1 != NULL)
    {
        pre1->next = p2;
    }
    if (pre2 != NULL)
    {
        pre2->next = p1;
    }
}

int smaller(const struct List *p1, const struct List *p2)
{
    if (p1->data.average < p2->data.average)
    {
        return 1;
    }
    else if (p1->data.average == p2->data.average)
    {
        return p1->data.id < p2->data.id;
    }
    else
    {
        return 0;
    }
}
