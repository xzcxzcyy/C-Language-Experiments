/*
 * 自幂数
 */

#include <stdio.h>
#include <math.h>

int check(int n);
int getNumberOfDigits(int n);

long long data[4];

int main()
{
    setbuf(stdout, 0);
    char *a[9];
    a[3] = "水仙花";
    a[4] = "四叶玫瑰";
    a[5] = "五角星";
    a[6] = "六合";
    a[7] = "北斗七星";
    a[8] = "八仙";

    int n, p;
    int k = 0;
    while (scanf("%d", &k) != EOF)
    {
        n = 0;
        p = 0;
        int i;
        for (i = pow(10, k - 1); i < pow(10, k); ++i)
        {
            if (check(i))
            {
                ++n;
                data[p++] = i;
            }
        }
        printf("%d位的%s数共有%d个: %lld", k, a[k], n, data[0]);
        int p0;
        for (p0 = 1; p0 < p; ++p0)
        {
            printf(", %lld", data[p0]);
        }
        putchar('\n');
    }
    return 0;
}

int check(int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int cpn = n;
    int i = getNumberOfDigits(n);

    int j;
    long long sum = 0;
    for (j = 0; j < i; ++j)
    {
        sum += pow(cpn - cpn / 10 * 10, i);
        cpn /= 10;
    }
    return sum == n;
}

int getNumberOfDigits(int n)
{
    int i = 1;
    /* 计算 n 的位数 */
    while (n /= 10)
    {
        ++i;
    }
    return i;
}
