#include <stdio.h>

int c[10][10];

void calculate();
void putSpace(int n);

int main()
{
    calculate();
    int i, j;
    for (i = 0; i < 10; ++i)
    {
        putSpace(18 - 2 * i);
        for (j = 0; j <= i; ++j)
        {
            printf("%4d", c[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

void calculate()
{
    int i, j;
    for (i = 0; i < 10; ++i)
    {
        c[i][0] = 1;
    }
    for (i = 0; i < 10; ++i)
    {
        for (j = 1; j <= i; ++j)
        {
            c[i][j] = c[i][j - 1] * (i - j + 1) / j;
        }
    }
}

void putSpace(int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        putchar(' ');
    }
}
