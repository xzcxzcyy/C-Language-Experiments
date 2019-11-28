/*
 * 整数分划
 */

#include <stdio.h>

void print(int *res, int p);
void search(int n, int *res, int p);

int putDot = 0;

int main()
{
    static int res[20] = {0};
    setbuf(stdout, NULL);
    int n;
    printf("Please input a number:\n");
    scanf("%d", &n);
    search(n, res, 0);
    return 0;
}

void print(int *res, int p)
{
    int i;
    if (putDot)
    {
        printf(", ");
    } else
    {
        putDot = 1;
    }
    printf("%d", res[0]);
    for (i = 1; i <= p; ++i)
    {
        printf("+%d", res[i]);
    }
}

void search(int n, int *res, int p)
{
    if (n == 0)
    {
        print(res, p - 1);
        return;
    }

    int mMin = (p == 0 || n <= res[p - 1]) ? n : res[p - 1];
    int i; // i 是当前要分出来的数
    for (i = mMin; i >= 1; --i)
    {
        res[p] = i;
        search(n - i, res, p + 1);
        if (p == 0)
        {
            putchar('\n');
            putDot = 0;
        }
    }
}
