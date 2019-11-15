/*
 * 阶乘之和
 * 优化：计算量最小
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
    //优化：让阶乘的结果和阶乘和的结果均保存下来
    static long long s = 0;
    static long long fac = 1;
    fac *= n;
    s += fac;
    return s;
}
