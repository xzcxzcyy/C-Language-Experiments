/*
 * 哥德巴赫猜想
 */

#include <stdio.h>
#define MAXM 1000000

int tb[MAXM + 1];

int check(int n);
void createPrimeTable(int m);

int main()
{
    int n;
    int i;

    /* 使用筛法创建素数表 */
    for (i = 0; i <= MAXM; i++)
    {
        tb[i] = 1;
    }
    createPrimeTable(MAXM);

    printf("Please input a number(>=4):\n");
    while (scanf("%d", &n) != EOF)
    {
        /* 首先要对数据合法性进行检查 */
        if (n >= 4 && !(n & 1))
        {
            if (!check(n))
            {
                printf("Check failed.\n");
            }
            else
            {
                printf("Check succeeded.\n");
            }
        }
        else
        {
            printf("Illegal input!\n");
        }
    }
}

int check(int n)
{
    int i;
    int success = 0;
    for (i = 2; i <= n; ++i)
    {
        if (tb[i] && tb[n - i])
        {
            printf("%d=%d+%d\t", n, i, n - i);
            success = 1;
            break;
        }
    }
    return success;
}

void createPrimeTable(int m)
{
    int i, j;
    tb[0] = tb[1] = 0;
    tb[2] = 1;
    for (i = 2; i <= m; ++i)
    {
        if (tb[i])
        {
            for (j = 2; i * j <= m; ++j)
            {
                tb[i * j] = 0;
            }
        }
    }
}