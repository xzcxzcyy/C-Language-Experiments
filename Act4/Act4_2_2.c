/*
 * 阶乘之和
 * 修改：递归版本
 */

#include <stdio.h>

long long sum_fac(int n);

int main(void)
{
    int k;
    for (k = 1; k <= 20; k++)
    {
        printf("k=%d\tthe sum is %lld\n", k, sum_fac(k));
    }
    return 0;
}

long long sum_fac(int n)
{
    /* 递归边界： n == 1 */
    if (n == 1)
    {
        return 1;
    }

    long long fac = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        fac *= i;
    }
    return sum_fac(n - 1) + fac;
}
