/*
 * 阶乘之和
 */

#include <stdio.h>

/* 主函数使用了 sum_fac() 函数，所以应在调用之前提供其原型 */
/* 用于储存阶乘之和的变量应该是 long long 类型，因为在本系统中 long 和 int 的大小相同（均为32位整数） */
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
    /* 应将 s 定义为静态变量，使其值可以在多次调用之间保存下来 */
    static long long s = 0;
    /*fac 未经初始化，其值未定义*/
    int i;
    /* 与前述理由相似，应用 long long 类型的变量保存阶乘 */
    long long fac = 1;
    for (i = 1; i <= n; i++)
    {
        fac *= i;
    }
    s += fac;
    return s;
}
