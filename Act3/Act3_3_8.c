#include <stdio.h>

int occupy[10];
int data[10];
int x;

void search(int p);
int check();
void print();

int main()
{
    scanf("%d", &x);
    search(0);
    return 0;
}

void search(int p)
{
    if (p == 9)
    {
        int i = 0;
        while (occupy[i])
        {
            ++i;
        }
        data[p] = i;
        occupy[i] = 1;
        if (check())
        {
            print();
        }
        occupy[i] = 0;
        return;
    }

    int i;
    for (i = 0; i < 10; ++i)
    {
        if (!occupy[i])
        {
            occupy[i] = 1;
            data[p] = i;
            search(p + 1);
            occupy[i] = 0;
            data[p] = 0;
        }
    }
}

int check()
{
    double a = 0, b = 0;
    int i;
    for (i = 0; i <= 4; ++i)
    {
        a *= 10;
        a += data[i];
    }
    for (i = 5; i <= 9; ++i)
    {
        b *= 10;
        b += data[i];
    }

    if (a / b == x)
    {
        return 1;
    } else
    {
        return 0;
    }
}

void print()
{
    int i;
    for (i = 0; i <= 4; ++i)
    {
        printf("%d", data[i]);
    }
    putchar('/');
    for (i = 5; i <= 9; ++i)
    {
        printf("%d", data[i]);
    }
    printf("=%d\n", x);
}
