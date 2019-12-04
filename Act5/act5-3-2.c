/*
 * 程序设计：成绩系统
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

double scores[MAX];
char *names[MAX];

enum Option
{
    oInput = 1,
    oOutput = 2,
    oQuit = 3
};

void input(int n);
void output(int n);
void mqsort(int begin, int end);  //快排：左开右闭区间
void sswap(double *a, double *b); //score swap
void nswap(char **a, char **b);   //name swap
enum Option menu(); //用于获取用户选项
int mbigger(int i, int j); //比较函数，若成绩相同，则比较名字的字典序

int main()
{
    int cmd, n = 0;
    while ((cmd = menu()) != oQuit)
    {
        switch (cmd)
        {
            case oInput:
                system("cls");
                printf("Please input the number of data:\n");
                scanf("%d", &n);
                input(n);
                mqsort(0, n);
                break;

            case oOutput:
                output(n);
                break;
        }
    }
    return 0;
}

void input(int n)
{
    if (n)
    {
        printf("Please input data with the pattern of [name] + [score] on each line\n");
    }
    int i;
    for (i = 0; i < n; ++i)
    {
        names[i] = malloc(30 * sizeof(char));
        scanf("%s", names[i]);
        scanf("%lf", &scores[i]);
    }
}

void output(int n)
{
    system("cls");
    if (n == 0)
    {
        printf("No data!\n");
    }

    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%s", names[i]);
        printf("%8.2f\n", scores[i]);
    }
    system("pause");
}

void nswap(char **a, char **b)
{
    char *t;
    t = *a;
    *a = *b;
    *b = t;
}

void sswap(double *a, double *b)
{
    double t;
    t = *a;
    *a = *b;
    *b = t;
}

int mbigger(int i, int j)
{
    if (scores[i] > scores[j])
    {
        return 1;
    }
    if (scores[i] == scores[j])
    {
        int m, n;
        for (m = 0, n = 0; m < strlen(names[i]) && n < strlen(names[j]); ++m, ++n)
        {
            if (names[i][m] < names[j][n])
            {
                return 1;
            }
            if (names[i][m] > names[j][n])
            {
                return 0;
            }
        }
        if (strlen(names[i]) < strlen(names[j]))
        {
            return 1;
        } else
        {
            return 0;
        }
    }
    return 0;
}

void mqsort(int begin, int end)
{
    if (end - begin <= 1)
    {
        return;
    }
    int i = begin, j = end - 1;
    int pivot = i + (end - begin) / 2;
    while (i <= j)
    {
        while (mbigger(i, pivot))
        {
            ++i;
        }
        while (mbigger(pivot, j))
        {
            --j;
        }
        if (i <= j)
        {
            sswap(scores + i, scores + j);
            nswap(names + i, names + j);
            ++i;
            --j;
        }
    }
    mqsort(begin, j + 1);
    mqsort(i, end);
}

enum Option menu()
{
    system("cls");
    int i;
    const int n = 40;
    for (i = 0; i < n; ++i)
    {
        putchar('=');
    }
    printf("\n\n\n");
    printf("[Menu]\n");
    printf("Please select an operation:\n");
    printf("1.Input data\n2.Display data\n(Use q to quit)");
    printf("\n\n\n");
    for (i = 0; i < n; ++i)
    {
        putchar('=');
    }
    putchar('\n');
    char command;
    while (scanf(" %c", &command) && command != '1' && command != '2' && command != 'q')
    {
        printf("Illegal command!\nPlease try again.\n");
    }
    if (command == 'q')
    {
        return oQuit;
    }
    return command - '0';
}
